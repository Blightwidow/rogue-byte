typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct VT { char pad[0x40]; short delta0; short padA; void (*fn0)(void *); short delta1; short padB; void (*fn1)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct ENT { int kind; int arg; };
struct NODE { int id; int unused; int count; ENT *ents; };
struct SW { char pad[0x158]; int flag; int cur; int count; NODE *nodes; };
extern "C" {
OBJ *PloFindSwObject_thunk(void *, int, int, void *);
void func_001F6978(SW *, int, OBJ *);
void func_001F69F8(SW *, int, OBJ *);
void func_001F6AC8(SW *, int, OBJ *);
void func_001F6B48(SW *, int, OBJ *);
extern char B_003DD490[];
void StepStgSwitch(SW *sw, int id)
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
    int cur = sw->cur;
    if (cur != target) {
        if (cur < target) {
            int forward = cur;
            do {
                sw->cur = forward + 1;
                NODE *node = &sw->nodes[forward];
                for (int index = 0; index < node->count; index++) {
                    ENT *ent = &node->ents[index];
                    OBJ *obj = 0;
                    if ((0xC3 >> ent->kind) & 1) {
                        obj = PloFindSwObject_thunk(B_003DD490, 1, ent->arg, sw);
                        if (obj == 0)
                            continue;
                    }
                    switch (ent->kind) {
                    case 0: obj->vt->fn0((char *)obj + obj->vt->delta0); break;
                    case 1: obj->vt->fn1((char *)obj + obj->vt->delta1); break;
                    case 2: func_001F6978(sw, ent->arg, obj); break;
                    case 3: func_001F69F8(sw, ent->arg, obj); break;
                    case 4: func_001F6AC8(sw, ent->arg, obj); break;
                    case 5: func_001F6B48(sw, ent->arg, obj); break;
                    }
                }
                forward = sw->cur;
            } while (forward < target);
        } else if (target < cur) {
            do {
                sw->cur = cur - 1;
                NODE *node = (__typeof__(&(sw->nodes)[0]))((cur - 1) * sizeof((sw->nodes)[0]) + (unsigned)(sw->nodes));
                int index = node->count;
                while (index-- > 0) {
                    ENT *ent = &node->ents[index];
                    OBJ *obj = 0;
                    if ((0xC3 >> ent->kind) & 1) {
                        obj = PloFindSwObject_thunk(B_003DD490, 1, ent->arg, sw);
                        if (obj == 0)
                            continue;
                    }
                    switch (ent->kind) {
                    case 0: obj->vt->fn1((char *)obj + obj->vt->delta1); break;
                    case 1: obj->vt->fn0((char *)obj + obj->vt->delta0); break;
                    case 2: func_001F69F8(sw, ent->arg, obj); break;
                    case 3: func_001F6978(sw, ent->arg, obj); break;
                    case 4: func_001F6B48(sw, ent->arg, obj); break;
                    case 5: func_001F6AC8(sw, ent->arg, obj); break;
                    }
                }
                cur = sw->cur;
            } while (target < cur);
        }
        sw->flag = 0;
    }
}
}
