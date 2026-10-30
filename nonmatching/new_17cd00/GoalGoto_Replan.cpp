#include "sly2.h"
extern "C" {
QW PosLoWorld(char *);
QW func_001C1EC0(char *, QW);
QW ClosestPointOnSegment(QW, QW, QW, QW *, float *, int);
int FFindPathzoneCrv(int, QW, QW, char *);
void GoalGoto_SetState(char *, int);
void MeasureCrv(char *);
void func_0017D8A8(char *);
int func_001EF0A8();
void func_002562A8(char *);
extern char *B_003E1A5C;
extern float g_2dded0;
float fabsf(float);
void GoalGoto_Replan(char *goal) {
    QW buffer[4];
    if (*(int *)(goal + 0x30) != -1) {
        if (*(int *)(*(char **)(goal + 0x10) + 0xFE8) & 2) {
            if (func_001EF0A8() == 0) {
                int mode;
                GoalGoto_SetState(goal, 0);
                func_0017D8A8(goal);
                func_002562A8((char *)buffer);
                if (*(int *)(goal + 0xB4) == 0) {
                    mode = 1;
                    buffer[0] = *(QW *)(goal + 0x60);
                    buffer[1] = *(QW *)(goal + 0x70);
                } else {
                    char *path = *(char **)(goal + 0xB8);
                    buffer[0] = *(QW *)(path + 0x60);
                    buffer[1] = *(QW *)(path + 0x70);
                    mode = 2;
                    if (*(int *)(path + 0x120) == 0) {
                        QW position = PosLoWorld(*(char **)(goal + 0x10));
                        QW start = func_001C1EC0(path + 0x60, position);
                        QW end = func_001C1EC0(path + 0x80, position);
                        ClosestPointOnSegment(position, start, end, &buffer[2], (float *)&buffer[3], 0);
                        int near = 0;
                        float along = *(float *)&buffer[3];
                        if (along > 0.0f && along < 1.0f) {
                            int distanceBits;
                            asm volatile("lqc2 vf1, 0x20(%1)\n\tqmtc2.ni %2, vf2\n\tvsub.xyzw vf1, vf1, vf2\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r"(distanceBits) : "r"(buffer), "r"(position) : "memory");
                            if (*(float *)&distanceBits < 50.0f) {
                                int zBits;
                                asm("pextuw %0, $0, %1" : "=r"(zBits) : "r"(position));
                                if (fabsf(*(float *)((char *)&buffer[2] + 8) - *(float *)&zBits) < 300.0f) {
                                    near = 1;
                                }
                            }
                        }
                        if (near) {
                            mode = 3;
                        }
                    }
                }
                if (mode > 0) {
                    if (mode < 3) {
                        char *guard = *(char **)(goal + 0x10);
                        char *crv = *(char **)(guard + 0x294);
                        QW position = PosLoWorld(guard);
                        QW target = func_001C1EC0((char *)buffer, position);
                        if (*(int *)(goal + 0xBC) != 0) {
                            *(int *)(crv + 0xE8) = 2;
                            **(QW **)(crv + 0xF4) = position;
                            *(QW *)(*(char **)(crv + 0xF4) + 0x10) = target;
                            MeasureCrv(crv);
                        } else {
                            char *first = *(char **)(*(char **)(goal + 0x10) + 0xE8);
                            char *second = 0;
                            if (first != 0) {
                                second = *(char **)(first + 0xDC);
                            }
                            int zone = 0;
                            if (second != 0) {
                                zone = *(int *)(second + 0x10);
                            }
                            if (FFindPathzoneCrv(zone, position, target, crv) == 0) {
                                mode = 5;
                                *(QW *)(goal + 0x80) = buffer[0];
                                *(QW *)(goal + 0x90) = buffer[1];
                            }
                        }
                    }
                }
                GoalGoto_SetState(goal, mode);
                *(float *)(goal + 0xA0) = g_2dded0;
                *(int *)(goal + 0xA4) = *(int *)(B_003E1A5C + 0x28);
            }
        }
    }
}
}
