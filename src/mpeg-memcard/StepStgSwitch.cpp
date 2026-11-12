typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
#define NULL 0
struct VT { char pad[0x40]; short delta0; short padA; void (*fn0)(void *); short delta1; short padB; void (*fn1)(void *); };
struct SW;
struct OBJ { char pad[0xC]; VT *vt; };
struct ENT { int kind; int arg; };
struct NODE { int id; int unused; int count; ENT *ents; };
struct STGSWITCH { char pad[0x158]; int flag; int cur; int count; NODE *nodes; };
extern "C" {
OBJ *PloFindSwObject_thunk(SW *, int, int, void *);
void func_001F6978(STGSWITCH *, int);
void func_001F69F8(STGSWITCH *, int);
void func_001F6AC8(STGSWITCH *, int);
void func_001F6B48(STGSWITCH *, int);
extern SW B_003DD490;
void StepStgSwitch(STGSWITCH *sw, int id)
{
    int target = sw->cur;
    if (id == 0x609) {
        target = 0;
    } else if (id == 0x60A) {
        target = sw->count;
    } else if (id != -1) {
        for (int index = 0; index < sw->count; index++) {
            if (sw->nodes[index].id == id) {
                target = index;
                break;
            }
        }
    }
    int forward = sw->cur;
    if (forward != target) {
        if (forward < target) {
            do {
                sw->cur = forward + 1;
                NODE *node = &sw->nodes[forward];
                for (int index = 0; index < node->count; index++) {
                    ENT *ent = &node->ents[index];
                    OBJ *obj = 0;
                    if ((0xC3 >> ent->kind) & 1) {
                        obj = PloFindSwObject_thunk(&B_003DD490, 1, ent->arg, sw);
                        if (obj == 0)
                            continue;
                    }
                    switch (ent->kind) {
                    case 0: obj->vt->fn0((char *)obj + obj->vt->delta0); break;
                    case 1: obj->vt->fn1((char *)obj + obj->vt->delta1); break;
                    case 2: func_001F6978(sw, ent->arg); break;
                    case 3: func_001F69F8(sw, ent->arg); break;
                    case 4: func_001F6AC8(sw, ent->arg); break;
                    case 5: func_001F6B48(sw, ent->arg); break;
                    }
                }
                forward = sw->cur;
            } while (forward < target);
        } else if (target < forward) {
            do {
                sw->cur = sw->cur - 1;
                NODE *node = &sw->nodes[sw->cur];
                int index = node->count;
                while (index-- > 0) {
                    ENT *ent = &node->ents[index];
                    OBJ *obj = 0;
                    if ((0xC3 >> ent->kind) & 1) {
                        obj = PloFindSwObject_thunk(&B_003DD490, 1, ent->arg, sw);
                        if (obj == 0)
                            continue;
                    }
                    switch (ent->kind) {
                    case 0: obj->vt->fn1((char *)obj + obj->vt->delta1); break;
                    case 1: obj->vt->fn0((char *)obj + obj->vt->delta0); break;
                    case 2: func_001F69F8(sw, ent->arg); break;
                    case 3: func_001F6978(sw, ent->arg); break;
                    case 4: func_001F6B48(sw, ent->arg); break;
                    case 5: func_001F6AC8(sw, ent->arg); break;
                    }
                }
            } while (target < sw->cur);
        }
        sw->flag = 0;
    }
}
}
