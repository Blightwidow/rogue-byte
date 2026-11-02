#include "sly2.h"
struct DL { char *first; char *last; int offset; };
struct DLI { DL *list; char *current; int offset; DLI *next; };
struct ALLOCREQ { int size; int align; };
struct Hit { QW point; char pad0[0x10]; QW normal; char pad1[0x10]; float weight; char pad2[0x1C]; };
struct RVT { char pad[0x40]; short delta; short index; int (*fn)(char *, char *, QW, QW); };
struct Rip { char pad0[0x14]; float created; char pad1[0x70 - 0x18]; QW edgeB; QW edgeA; char pad2[0xEC - 0x90]; RVT *vt; };
struct Item { char pad0[0x10]; long flags; char pad1[0x6C - 0x18]; int count; char pad2[0x74 - 0x70]; void *bsp; };
struct Obj { char pad0[0x34]; DL items; char pad1[0x60 - 0x40]; int type; char pad2[0x70 - 0x64]; long flags; };
struct So { char pad[0xEC]; Obj *obj; };
struct Node { char pad0[4]; Node *next; char pad1[4]; So *so; };
struct World { char pad0[0x20]; QW pos; float radius; char pad1[0x64 - 0x34]; Node *head; };
struct LVT { char pad[0x48]; short delta; short index; void (*fn)(char *); };
struct Ripg { char pad0[0xC]; LVT *vt; char pad1[0xEC - 0x10]; World *world; char pad2[0x150 - 0xF0]; int state; char pad3[0x15C - 0x154]; DL rips; };
extern DLI *g_2dd2fc;
extern float g_2dded0;
extern "C" {
void *CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
int ClsgClipEdgeToObjectPruned(Item *, void *, QW, QW, int, Hit *);
int FIsBasicDerivedFrom(int, int);
int FIsDlEmpty__FP2DL(DL *);
int PruneBsp__FP3BSPP6VECTORfPP3BSP(void *, int, QW, int *, void **, float);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
}
inline void PushDli(DLI *it, DL *list)
{
    it->list = list;
    it->current = (char *)list;
    it->offset = list->offset;
    it->next = g_2dd2fc;
    g_2dd2fc = it;
}
inline char *PvStep(DLI *it)
{
    char *item = *(char **)it->current;
    it->current = item + it->offset;
    return item;
}
inline void PopDli(DLI *it) { g_2dd2fc = it->next; }

extern "C" void BounceRipgRips__FP4RIPG(Ripg *ripg)
{
    if (ripg->state != 1)
        return;
    DL *rips = &ripg->rips;
    for (Node *node = ripg->world->head; node; node = node->next) {
        Obj *obj = node->so->obj;
        if (obj->flags & 4)
            continue;
        int basic = FIsBasicDerivedFrom(obj->type, 0x59);
        DLI outer;
        PushDli(&outer, &node->so->obj->items);
        for (Item *item = (Item *)PvStep(&outer); item; item = (Item *)PvStep(&outer)) {
            if ((item->flags & (0x8000L << 33)) && !basic)
                continue;
            char frame[16];
            CStackFrame_Construct(frame);
            void *pruned = 0;
            int count;
            if (!(item->flags & (0x8000L << 34))) {
                count = item->count < 0x1555 ? item->count : 0x1555;
                ALLOCREQ req;
                req.size = count * 0xC;
                req.align = 0x10;
                pruned = PvAllocStackImpl__Fi(&req);
                World *world = ripg->world;
                if (PruneBsp__FP3BSPP6VECTORfPP3BSP(item->bsp, 0x7FFFFFFF, world->pos, &count, &pruned, world->radius) != 2) {
                    CStackFrame_Destructor(frame, 2);
                    continue;
                }
                pruned = (char *)pruned - 0xC;
            }
            DLI inner;
            PushDli(&inner, rips);
            for (Rip *rip = (Rip *)PvStep(&inner); rip; rip = (Rip *)PvStep(&inner)) {
                if (g_2dded0 <= rip->created)
                    continue;
                Hit hits[4];
                int hitCount = ClsgClipEdgeToObjectPruned(item, pruned, rip->edgeA, rip->edgeB, 4, hits);
                for (int index = 0; index < hitCount; index++) {
                    if (hits[index].weight != 0.0f && rip->vt->fn((char *)rip + rip->vt->delta, (char *)item, hits[index].point, hits[index].normal))
                        break;
                }
            }
            PopDli(&inner);
            CStackFrame_Destructor(frame, 2);
        }
        PopDli(&outer);
    }
    if (FIsDlEmpty__FP2DL(rips))
        ripg->vt->fn((char *)ripg + ripg->vt->delta);
}
