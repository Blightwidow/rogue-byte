// SPDX-License-Identifier: GPL-3.0-or-later
// Near miss (score 20, 2026-11-08): retail's frame is 0xC0 with a 16-byte slot at sp+0x20 that nothing reads or writes; an unused ALLOCREQ local reproduces it
// (score 0) but nothing shows the original declared one there, so it is not kept (AGENTS.md: a field that exists only to size the frame is not allowed).
#include "sly2.h"

// Word 4 of every pooled splice node: previous and next links as (pool, index)
// pairs and the collector's mark bit on top (layout of UnlinkSidebagNode).
struct NodeLinks {
    unsigned short prevIndex : 13;
    unsigned prevPool : 2;
    unsigned unused15 : 1;
    unsigned short nextIndex : 13;
    unsigned nextPool : 2;
    unsigned mark : 1;
};
struct Node {
    int field0;
    NodeLinks links;
};
struct Ref {
    int tag;
    Node *value;
};
// Same shape as the bindings bevy_splice_eval_reset walks.
struct Binding {
    int field0;
    NodeLinks links;
    int field8;
    Ref ref;
    Binding *next;
};
struct Frame {
    int field0;
    NodeLinks links;
    char field8[0x20];
};
struct Sidebag {
    int field0;
    NodeLinks links;
    Binding *bindings;
};
struct ProcLink {
    int field0;
    int field4;
    Node *proc;
    int fieldC;
    ProcLink *next;
};
// Field names follow CGc_MarkRef and bevy_splice_eval_reset.
struct GC {
    int generation;
    int frameCount;
    Node **frames;
    int procCount;
    Node **procs;
    int pairCount;
    Node **pairs;
};
// CreateSlotheapSwAlign stores the first three words; +0x10 is the slot count
// the collector sizes its mark stacks with.
struct SLOTHEAP {
    int slotSize;
    int slotsPerChunk;
    int align;
    void *freeList;
    int slotCount;
};
#include "alloc.h"
struct STACKFRAME { int field0; int field4; int field8; int fieldC; };

extern "C" {
void func_002574E0();
void func_002574E8();
void func_002574F0();
void func_002574F8();
void func_00257500();
void func_00257508();
void CStackFrame_Construct(STACKFRAME *);
void CStackFrame_Destructor(STACKFRAME *, int);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
void CGc_MarkRef(GC *, Ref *);
void bevy_splice_eval_reset(GC *);
void SweepFrames();
void SweepVarbs();
void SweepPairs();
void SweepProcs();
void SweepSidebags();
void func_00257C18();
}
extern SLOTHEAP B_004520A8; // proc heap (0x14-byte slots)
extern SLOTHEAP B_004520F8; // frame heap (0x28-byte slots)
extern SLOTHEAP B_00452120; // pair heap (0x1C-byte slots)
extern Frame *B_004520E8[];
extern Sidebag *B_00452138[];
extern Frame *B_002DD2AC;
extern Sidebag *B_002DD2CC;
extern ProcLink *B_003E0E80;
extern int g_2dd598;

// Retail: the three mark stacks are sized from each slot heap's count at +0x10
// (read as a struct member, which keeps every array store ahead of its count
// store and the next load), the request is filled as request.cb plus
// prequest->cbAlign like LoadCoinFromBrx, and the next link is decoded with
// "index == 0 && pool == 0 ? 0 : chunk + index", the index a 13-bit field of
// a short (its shift and mask land in two registers, the pool's in one).
// Retail's frame is 0xC0: STACKFRAME at sp+0, the request at sp+0x10 and a
// further 16-byte slot at sp+0x20 that nothing reads or writes; gcc 2.95 gives
// an unused struct local such a slot, so a second, unused ALLOCREQ stands for
// it (without it the frame is 0xB0 and every save offset moves by 0x10).
extern "C" void CGc_Collect(GC *gc)
{
    STACKFRAME frame;
    int align = 16;

    gc->generation = gc->generation == 0;
    func_002574E0();
    func_002574E8();
    func_002574F0();
    func_002574F8();
    func_00257500();
    func_00257508();
    CStackFrame_Construct(&frame);
    ALLOCREQ request;
    ALLOCREQ *prequest = &request;

    request.cb = B_004520F8.slotCount * 4;
    prequest->cbAlign = align;
    gc->frames = (Node **)PvAllocStackImpl__Fi(prequest);
    gc->frameCount = 0;
    request.cb = B_004520A8.slotCount * 4;
    prequest->cbAlign = align;
    gc->procs = (Node **)PvAllocStackImpl__Fi(prequest);
    gc->procCount = 0;
    request.cb = B_00452120.slotCount * 4;
    prequest->cbAlign = align;
    gc->pairs = (Node **)PvAllocStackImpl__Fi(prequest);
    gc->pairCount = 0;

    for (Frame *frameNode = B_002DD2AC; frameNode != 0;) {
        if (frameNode->links.mark != g_2dd598) {
            frameNode->links.mark = g_2dd598;
            gc->frames[gc->frameCount++] = (Node *)frameNode;
        }
        Frame *next;
        unsigned nextIndex = frameNode->links.nextIndex;
        unsigned nextPool = frameNode->links.nextPool;
        if (nextIndex == 0 && nextPool == 0)
            next = 0;
        else
            next = B_004520E8[nextPool] + nextIndex;
        frameNode = next;
    }

    for (Sidebag *sidebag = B_002DD2CC; sidebag != 0;) {
        if (sidebag->links.mark != g_2dd598)
            sidebag->links.mark = g_2dd598;
        for (Binding *binding = sidebag->bindings; binding != 0; binding = binding->next) {
            binding->links.mark = g_2dd598;
            CGc_MarkRef(gc, &binding->ref);
        }
        Sidebag *next;
        unsigned nextIndex = sidebag->links.nextIndex;
        unsigned nextPool = sidebag->links.nextPool;
        if (nextIndex == 0 && nextPool == 0)
            next = 0;
        else
            next = B_00452138[nextPool] + nextIndex;
        sidebag = next;
    }

    for (ProcLink *link = B_003E0E80; link != 0; link = link->next) {
        Node *proc = link->proc;
        if (proc->links.mark != g_2dd598) {
            proc->links.mark = g_2dd598;
            gc->procs[gc->procCount++] = proc;
        }
    }

    bevy_splice_eval_reset(gc);
    SweepFrames();
    SweepVarbs();
    SweepPairs();
    SweepProcs();
    SweepSidebags();
    func_00257C18();
    CStackFrame_Destructor(&frame, 2);
}
