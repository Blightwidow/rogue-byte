#include "sly2.h"
struct Node_1281B0 { int pad0; unsigned low : 31; unsigned mark : 1; };
struct Gc_1281B0 {
    int gen;
    int cframe; Node_1281B0 **aframe;
    int cproc; Node_1281B0 **aproc;
    int cpair; Node_1281B0 **apair;
};
struct Ref_1281B0 { int tagk; Node_1281B0 *pv; };
struct Binding_1281B0 { int pad0; unsigned low : 31; unsigned mark : 1; int pad8; Ref_1281B0 ref; Binding_1281B0 *next; };
struct Frame_1281B0 { int pad0; unsigned low : 31; unsigned mark : 1; int count; Node_1281B0 *child[4]; Binding_1281B0 *bindings; };
struct Link_1281B0 { int pad0; unsigned low : 31; unsigned mark : 1; int pad8; int padC; Link_1281B0 *next; };
struct Pair_1281B0 { int pad0; unsigned low : 31; unsigned mark : 1; Node_1281B0 *frame; int padC; int pad10; Link_1281B0 *links; Node_1281B0 *proc; };
struct Proc_1281B0 { int pad0; unsigned low : 31; unsigned mark : 1; Ref_1281B0 ref; Node_1281B0 *next; };
extern Gc_1281B0 g_2dd598;

extern "C" void bevy_splice_eval_reset(Gc_1281B0 *gc)
{
    Node_1281B0 *node;
    Frame_1281B0 *frame;
    Proc_1281B0 *proc;
    for (;;) {
        if (gc->cframe > 0)
            frame = (Frame_1281B0 *)gc->aframe[--gc->cframe];
        else
            frame = 0;
        if (frame) {
            for (Binding_1281B0 *binding = frame->bindings; binding; binding = binding->next) {
                Ref_1281B0 *ref = &binding->ref;
                binding->mark = g_2dd598.gen;
                switch (ref->tagk) {
                case 0x1F: {
                    Node_1281B0 *proc = ref->pv;
                    if (proc->mark != g_2dd598.gen) {
                        proc->mark = g_2dd598.gen;
                        gc->aproc[gc->cproc++] = proc;
                    }
                    break;
                }
                case 0x20:
                    node = ref->pv;
                    if (node->mark != g_2dd598.gen) {
                        node->mark = g_2dd598.gen;
                        gc->apair[gc->cpair++] = node;
                    }
                    break;
                case 0x22:
                    /* retail marks the node of the last 0x20 binding, not ref->pv (stale pointer in the original) */
                    node->mark = g_2dd598.gen;
                    break;
                }
            }
            for (int index = 0; index < frame->count; index++) {
                Node_1281B0 *child = frame->child[index];
                if (child->mark != g_2dd598.gen) {
                    child->mark = g_2dd598.gen;
                    gc->aframe[gc->cframe++] = child;
                }
            }
            continue;
        }
        if (gc->cpair > 0)
            node = gc->apair[--gc->cpair];
        else
            node = 0;
        if (node) {
            Pair_1281B0 *pair = (Pair_1281B0 *)node;
            for (proc = (Proc_1281B0 *)pair->links; proc; proc = (Proc_1281B0 *)((Link_1281B0 *)proc)->next) {
                if (proc->mark != g_2dd598.gen)
                    proc->mark = g_2dd598.gen;
            }
            proc = (Proc_1281B0 *)pair->proc;
            if (proc->mark != g_2dd598.gen) {
                proc->mark = g_2dd598.gen;
                gc->aproc[gc->cproc++] = (Node_1281B0 *)proc;
            }
            frame = (Frame_1281B0 *)pair->frame;
            if (frame->mark != g_2dd598.gen) {
                frame->mark = g_2dd598.gen;
                gc->aframe[gc->cframe++] = (Node_1281B0 *)frame;
            }
            continue;
        }
        if (gc->cproc > 0)
            proc = (Proc_1281B0 *)gc->aproc[--gc->cproc];
        else
            proc = 0;
        if (!proc)
            return;
        switch (proc->ref.tagk) {
        case 0x1F: {
            Node_1281B0 *target = proc->ref.pv;
            if (target->mark != g_2dd598.gen) {
                target->mark = g_2dd598.gen;
                gc->aproc[gc->cproc++] = target;
            }
            break;
        }
        case 0x20:
            node = proc->ref.pv;
            if (node->mark != g_2dd598.gen) {
                node->mark = g_2dd598.gen;
                gc->apair[gc->cpair++] = node;
            }
            break;
        case 0x22:
            proc->ref.pv->mark = g_2dd598.gen;
            break;
        }
        proc = (Proc_1281B0 *)proc->next;
        if (proc && proc->mark != g_2dd598.gen) {
            proc->mark = g_2dd598.gen;
            gc->aproc[gc->cproc++] = (Node_1281B0 *)proc;
        }
    }
}
