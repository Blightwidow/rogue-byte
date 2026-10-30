#include "sly2.h"
struct GOAL { char pad0[0x10]; char *guard; char pad1[0x40 - 0x14]; char *animref; };
struct VT { char pad[0x118]; short delta; short index; void (*fn)(char *, QW); };
struct OBJ30 { char pad[0x30]; char *focus; char pad2[0x50 - 0x34]; void *field50; };
extern "C" {
int func_00209518(void *);
void *func_002097C8(void *, void *);
void func_002097D8(void *, void *);
void func_001EEFC0(void *, int);
void func_001EF038(void *, int);
int func_001A6AF8(void *, char *);
QW func_00204E38(char *, int, float);
void func_001F7A68(void *, int);
void *func_00205458(void *, int);
char *PpoSwFocusBase(char *);
void TriggerJoyRumbleRumk__FP3JOY4RUMKf(void *, int, float);
void JoltCm(void *, int);
extern char B_002DDF40[];
extern char B_002DFC00[];
extern char B_003DD490[];
extern char *g_2f7900;
#define guard (goal->guard)
int GoalAnim_FHandleMessage(GOAL *goal, int message, int *data) {
    QW junk;
    if (message == 9) {
        void *animref = goal->animref;
        if (animref != 0) {
            int sender = func_00209518(animref);
            if (sender == data[0]) {
                switch (data[2]) {
                case 0x25:
                    func_002097C8(guard + 0xFD0, goal);
                    return 1;
                case 0x26:
                    func_002097D8(guard + 0xFD0, goal);
                    return 1;
                case 0x27:
                    func_001EEFC0(goal, sender);
                    return 1;
                case 0x28:
                    func_001EF038(goal, sender);
                    return 1;
                case 0x29:
                    *(int *)(guard + 0x1A4) = 1;
                    return 1;
                case 0x2A:
                    *(int *)(guard + 0x1A4) = 0;
                    return 1;
                case 0x2F: {
                    OBJ30 *obj = (OBJ30 *)func_00205458(guard, 0xA5);
                    if (obj != 0) {
                        if (obj->focus == PpoSwFocusBase(B_003DD490))
                            TriggerJoyRumbleRumk__FP3JOY4RUMKf(B_002DFC00, 8, 1.0f);
                    }
                    return 0;
                }
                case 0x34:
                case 0x35: {
                    char *focus = PpoSwFocusBase(B_003DD490);
                    OBJ30 *obj = (OBJ30 *)func_00205458(guard, 0xA0);
                    if (obj != 0 && func_001A6AF8(obj->field50, focus) != 0) {
                        if (focus == g_2f7900) {
                            int type = data[2];
                            if (type != 0x34) {
                                if (type == 0x35) JoltCm(B_002DDF40, 0);
                            } else {
                                TriggerJoyRumbleRumk__FP3JOY4RUMKf(B_002DFC00, 3, 0.15f);
                            }
                        }
                    }
                    return 0;
                }
                case 0x36:
                    func_001F7A68(guard, 2);
                    return 0;
                case 0x15E: {
                    QW vel = func_00204E38(guard, sender, *(float *)(data + 1));
                    float scale = -1.0f;
                    QW world;
                    int chain;
                    asm volatile("qmtc2.ni %1, vf4" : "=r" (chain) : "r" (vel));
                    asm volatile("qmtc2.ni %1, vf1" : "=r" (chain) : "r" (scale), "r" (chain));
                    asm volatile("vmulx.xyzw vf2, vf4, vf1x" : "=r" (chain) : "r" (chain));
                    asm volatile("sqc2 vf1, %0" : "=m" (junk) : "r" (chain));
                    asm volatile("sqc2 vf2, %0" : "=m" (*(QW *)(guard + 0x190)) : "r" (chain));
                    char *base = guard;
                    VT *vtable = *(VT **)(base + 0xC);
                    QW *rows = (QW *)(base + 0x1B0);
                    asm volatile("lqc2 vf3, 0x20(%1)" : "=r" (chain) : "r" (rows), "r" (chain));
                    asm volatile("lqc2 vf2, 0x1b0(%1)" : "=r" (chain) : "r" (base), "r" (chain));
                    asm volatile("lqc2 vf1, 0x10(%1)" : "=r" (chain) : "r" (rows), "r" (chain));
                    void (*fn)(char *, QW) = vtable->fn;
                    char *self = base + vtable->delta;
                    asm volatile("vmulax.xyz ACC, vf2, vf4x\n\tvmadday.xyz ACC, vf1, vf4y\n\tvmaddz.xyz vf5, vf3, vf4z\n\tqmfc2.ni %0, vf5" : "=r" (world) : "r" (chain));
                    fn(self, world);
                    return 1;
                }
                default:
                    return 0;
                }
            }
        }
    }
    return 0;
}
}
