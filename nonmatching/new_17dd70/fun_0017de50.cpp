#include "sly2.h"
struct VT { char pad[0x2C0]; short delta; short pad2; int (*fn)(char *); };
struct OBJ { char pad[0xC]; VT *vt; };
extern "C" {
int FGoalAnimDone(int);
QW PosLoWorld(char *);
void func_0017E0E0(char *);
void func_0017E278(char *, int);
QW func_001C1EC0(char *, QW);
void func_001EEF98();
int func_001EF0A8(char *);
int func_00208B38(char *, int);
float func_00208BB0(char *);
int func_00209098(char *);
extern const float RO_002BE760;
extern const float RO_002BE764;
extern const float RO_002BE768;
extern float g_2dded0[2];
void func_0017DE50(char *goal) {
    QW first;
    QW second;
    int previous;
    func_001EEF98();
    while (previous = *(int *)(goal + 0x30), func_001EF0A8(goal) == 0) {
        switch (*(int *)(goal + 0x30)) {
        case 0:
            if (FGoalAnimDone(*(int *)(goal + 0x18)) != 0) {
                func_0017E278(goal, 1);
            }
            break;
        case 1:
            if (func_00209098(*(char **)(goal + 0x10)) != 0) {
                func_0017E278(goal, 2);
            } else {
                float remaining = *(float *)(goal + 0x40) - g_2dded0[1];
                *(float *)(goal + 0x40) = remaining;
                if (remaining <= 0.0f) {
                    int result = (*(OBJ **)(goal + 0x10))->vt->fn((char *)*(OBJ **)(goal + 0x10) + (*(OBJ **)(goal + 0x10))->vt->delta);
                    if (result == *(int *)(goal + 0x38) && func_00208B38(*(char **)(goal + 0x10), result) != 0) {
                        *(float *)(goal + 0x40) = func_00208BB0(*(char **)(goal + 0x10));
                    } else {
                        func_0017E278(goal, -1);
                    }
                }
            }
            break;
        case 2:
            if (func_00209098(*(char **)(goal + 0x10)) == 0) {
                func_0017E278(goal, 1);
            }
            break;
        }
        if (*(int *)(goal + 0x30) == previous) {
            break;
        }
    }
    if (*(int *)(goal + 0x30) == 1) {
        if (RO_002BE760 < g_2dded0[0] - *(float *)(goal + 0x3C)) {
            char *anim = *(char **)(goal + 0x18) + 0x40;
            int near = 0;
            second = func_001C1EC0(anim, PosLoWorld(*(char **)(goal + 0x10)));
            QW position = PosLoWorld(*(char **)(goal + 0x10));
            int distanceBits;
            asm volatile("qmtc2.ni %0, vf2" : : "r"(position));
            asm volatile("lqc2 vf3, %0" : : "m"(second));
            asm volatile("vsub.xyzw vf1, vf2, vf3");
            asm volatile("vmul.xy vf1, vf1, vf1");
            asm volatile("vaddy.x vf1, vf1, vf1y");
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            asm volatile("qmfc2.ni %0, vf1" : "=r"(distanceBits));
            if (*(float *)&distanceBits < RO_002BE764) {
                near = 1;
            } else {
                QW guardPosition = PosLoWorld(*(char **)(goal + 0x10));
                asm volatile("qmtc2.ni %0, vf1" : : "r"(guardPosition));
                QW targetPosition = PosLoWorld(*(char **)(goal + 0x38));
                asm volatile("sqc2 vf1, %0" : "=m"(first));
                asm volatile("qmtc2.ni %0, vf2" : : "r"(targetPosition));
                asm volatile("lqc2 vf1, %0" : : "m"(first));
                asm volatile("vsub.xyzw vf1, vf1, vf2");
                asm volatile("vmul.xy vf1, vf1, vf1");
                asm volatile("vaddy.x vf1, vf1, vf1y");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                asm volatile("qmfc2.ni %0, vf1" : "=r"(distanceBits));
                if (*(float *)&distanceBits < RO_002BE768) {
                    near = 1;
                }
            }
            if (near != 0) {
                func_0017E0E0(goal);
            }
        }
    }
}
}
