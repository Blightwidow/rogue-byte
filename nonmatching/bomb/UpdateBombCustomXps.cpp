#include "sly2.h"
struct POB_13AC18 { char pad0[0x28]; unsigned long flags; char pad30[0xEC - 0x30]; struct POX_13AC18 *pox; };
struct POX_13AC18 { char pad0[0x30]; float radius; };
struct PROXY_13AC18 { char pad0[0xEC]; POX_13AC18 *pox2; };
struct CHILD_13AC18 { char pad0[0x10]; CHILD_13AC18 *next; char pad14[0xEC - 0x14]; struct HOLDER_13AC18 *holder; };
struct HOLDER_13AC18 { char pad0[0x60]; POB_13AC18 *pob; };
struct LO_13AC18 {
    char pad0[0x10];
    CHILD_13AC18 *child;
    char pad14[0xE0 - 0x14];
    LO_13AC18 *next;
    char padE4[4];
    int flags;
    char padEC[4];
    int active;
};
struct ITEM_13AC18 { QW vec0; QW vec1; int field20; POB_13AC18 *pob; char pad28[8]; };
struct BOMB_13AC18 {
    char padE4[0xE4];
    char *info;
    int padE8;
    void *pox;
    char padF0[0x1F8 - 0xF0];
    int count;
    ITEM_13AC18 *items;
};
struct LSG_13AC18 { QW point; QW pad; QW normal; char tail[0x30]; };
extern "C" {
int ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(QW, QW, QW, int, LSG_13AC18 *, float);
QW PosLoWorld(void *);
void UpdateSwPox(void *, void *, void *, int);
extern char B_003DD490;
extern LO_13AC18 *B_003E13B4;
}
extern "C" void UpdateBombCustomXps(BOMB_13AC18 *bomb) {
    char frameGap[0x10] __attribute__((aligned(16))); // retail frame: 0x10 unused bytes below the LSG
    LSG_13AC18 lsg;
    POX_13AC18 *pox;
    int index;
    LO_13AC18 *lo;
    CHILD_13AC18 *child;
    POB_13AC18 *pob;
    ITEM_13AC18 *item;
    QW first;
    QW center;
    int bits;
    for (index = 0; index < bomb->count; index++) {
        UpdateSwPox(&B_003DD490, bomb->pox, *(void **)((char *)((POB_13AC18 *)bomb->items[index].pob) + 0xEC), 2);
    }
    bomb->count = 0;
    for (lo = B_003E13B4; lo != 0; lo = lo->next) {
        if (lo->active == 0) {
            continue;
        }
        if ((lo->flags & 0x100) == 0) {
            continue;
        }
        pob = 0;
        for (child = lo->child; child != 0; child = child->next) {
            if (child->holder != 0) {
                pob = child->holder->pob;
                break;
            }
        }
        if (pob == 0) {
            continue;
        }
        if (((pob->flags >> 60) & 1) == 0) {
            continue;
        }
        first = PosLoWorld(lo);
        pox = pob->pox;
        center = *(QW *)(bomb->info + 0x50);
        if (ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(first, center, PosLoWorld(bomb), 1, &lsg, pox->radius) != 0) {
            UpdateSwPox(&B_003DD490, bomb->pox, pob->pox, 1);
            item = (ITEM_13AC18 *)(bomb->count * 0x30 + (unsigned)bomb->items);
            bomb->count++;
            item->pob = pob;
            asm("lqc2 vf2, %2\n\tsqc2 vf2, 0(%1)\n\tlqc2 vf1, %3\n\tvmul.xyz vf2, vf2, vf1\n\tvaddw.x vf3, vf0, vf0w\n\t"
                "vadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tqmfc2.ni %0, vf2\n\tsqc2 vf1, 0x10(%1)"
                : "=r" (bits) : "r" (item), "m" (lsg.point), "m" (lsg.normal) : "memory");
            item->field20 = bits;
            if (bomb->count >= 4) {
                break;
            }
        }
    }
}
