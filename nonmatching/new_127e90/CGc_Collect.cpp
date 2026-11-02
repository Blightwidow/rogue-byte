#include "sly2.h"
struct Node { int pad; unsigned low : 31; unsigned mark : 1; };
struct Sub { int pad; unsigned low : 31; unsigned mark : 1; int pad8; int padC; int pad10; Sub *next; };
struct Item { int pad; unsigned low : 31; unsigned mark : 1; Sub *subs; int padC; Item *unused; };
struct Gc { int flag; int count0; Node **array0; int count1; Node **array1; int count2; Node **array2; };
struct Link { int pad; Link *pad4; Node *node; int padC; Link *next; };
struct Req { int size; int align; int p8; int pc; int p10; int p14; int p18; int p1c; };
struct Frame { int a, b, c, d; };
extern "C" {
void func_002574E0(); void func_002574E8(); void func_002574F0(); void func_002574F8(); void func_00257500(); void func_00257508();
void CStackFrame_Construct(Frame *); void CStackFrame_Destructor(Frame *, int);
void *PvAllocStackImpl__Fi(Req *);
void CGc_MarkRef(Gc *, void *);
void bevy_splice_eval_reset(Gc *);
void SweepFrames(); void SweepVarbs(); void SweepPairs(); void SweepProcs(); void SweepSidebags(); void func_00257C18();
}
extern Node *B_002DD2AC;
extern Item *B_002DD2CC;
extern Link *B_003E0E80;
extern int B_004520B8, B_00452108, B_00452130;
extern char *B_004520E8[];
extern char *B_00452138[];
extern int g_2dd598;
static inline Node *NextNode(Node *node)
{
    unsigned word = ((unsigned *)node)[1];
    unsigned idx = (word >> 16) & 0x1FFF, pool = (word >> 29) & 3;
    if (idx || pool) return (Node *)(B_004520E8[pool] + idx * 0x28);
    return 0;
}
static inline Item *NextItem(Item *item)
{
    unsigned word = ((unsigned *)item)[1];
    unsigned idx = (word >> 16) & 0x1FFF, pool = (word >> 29) & 3;
    if (idx || pool) return (Item *)(B_00452138[pool] + idx * 0xC);
    return 0;
}
extern "C" void CGc_Collect(Gc *gc)
{
    Frame frame;
    int align = 16;
    Req req;
    gc->flag = gc->flag == 0;
    func_002574E0(); func_002574E8(); func_002574F0(); func_002574F8(); func_00257500(); func_00257508();
    CStackFrame_Construct(&frame);
    Req *preq = &req;
    req.size = B_00452108 * 4; preq->align = align;
    gc->array0 = (Node **)PvAllocStackImpl__Fi(preq);
    gc->count0 = 0;
    req.size = B_004520B8 * 4; preq->align = align;
    gc->array1 = (Node **)PvAllocStackImpl__Fi(preq);
    gc->count1 = 0;
    req.size = B_00452130 * 4; preq->align = align;
    gc->array2 = (Node **)PvAllocStackImpl__Fi(preq);
    gc->count2 = 0;
    Node *next;
    Item *nextItem;
    Node *node = B_002DD2AC;
    if (node) {
        do {
            if (node->mark != g_2dd598) {
                node->mark = g_2dd598;
                int count = gc->count0;
                gc->array0[count] = node;
                gc->count0 = count + 1;
            }
            unsigned word = ((unsigned *)node)[1];
            unsigned idx = (word >> 16) & 0x1FFF, pool = (word >> 29) & 3;
            if (idx != 0 || (next = 0, pool != 0)) next = (Node *)(B_004520E8[pool] + idx * 0x28);
            node = next;
        } while (node);
    }
    Item *item = B_002DD2CC;
    if (item) {
        do {
            if (item->mark != g_2dd598) item->mark = g_2dd598;
            Sub *sub = item->subs;
            while (sub) {
                sub->mark = g_2dd598;
                CGc_MarkRef(gc, (char *)sub + 0xC);
                sub = sub->next;
            }
            unsigned word = ((unsigned *)item)[1];
            unsigned idx = (word >> 16) & 0x1FFF, pool = (word >> 29) & 3;
            if (idx != 0 || (nextItem = 0, pool != 0)) nextItem = (Item *)(B_00452138[pool] + idx * 0xC);
            item = nextItem;
        } while (item);
    }
    Link *link = B_003E0E80;
    if (link) {
        do {
            Node *target = link->node;
            if (target->mark != g_2dd598) {
                target->mark = g_2dd598;
                int count = gc->count1;
                gc->array1[count] = target;
                gc->count1 = count + 1;
            }
            link = link->next;
        } while (link);
    }
    bevy_splice_eval_reset(gc);
    SweepFrames(); SweepVarbs(); SweepPairs(); SweepProcs(); SweepSidebags(); func_00257C18();
    CStackFrame_Destructor(&frame, 2);
}
