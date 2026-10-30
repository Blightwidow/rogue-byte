#include "sly2.h"
struct SMP;
extern "C" {
void ContinueAmb(char *);
float GSmooth__FfffP3SMPPf(float, float, float, SMP *, float *);
void Mount_SetState(char *, int);
void PauseAmb(char *);
void SetAmbVolume(char *, float);
void SetSmaGoal__FP3SMA3OID(void *, int);
QW SetVectorCylind__FP6VECTORfff(float, float, float);
void UpdateSo();
void func_0012D108(void *, QW);
int func_0017F550(char *);
extern SMP D_002BE7F0;
extern float g_2be7e8;
extern float g_2dded4;
void Mount_Update(char *mount) {
    unsigned state;
    unsigned after;
    UpdateSo();
    do {
        state = *(unsigned *)(mount + 0x1C0);
        if (state == 2 && func_0017F550(mount) != 0) {
            Mount_SetState(mount, 1);
        }
        after = *(unsigned *)(mount + 0x1C0);
    } while (after != state);
    switch (after) {
    case 0:
        {
            int *vec = (int *)(mount + 0x220);
            vec[1] = 0;
            vec[2] = 0;
            vec[0] = 0;
        }
        break;
    case 2:
        {
            int *vec = (int *)(mount + 0x220);
            vec[1] = 0;
            vec[2] = 0;
            vec[0] = 0;
        }
        break;
    case 3:
        {
            int *vec = (int *)(mount + 0x220);
            vec[1] = 0;
            vec[2] = 0;
            vec[0] = 0;
        }
        break;
    case 4:
        {
            int *vec = (int *)(mount + 0x220);
            vec[1] = 0;
            vec[2] = 0;
            vec[0] = 0;
        }
        break;
    case 1: {
        char *data = *(char **)(mount + 0x150);
        int index = 0;
        *(float *)(mount + 0x218) = *(float *)(data + 0x18);
        *(QW *)(mount + 0x220) = SetVectorCylind__FP6VECTORfff(*(float *)(data + 0x18), *(float *)(data + 0x1C) * g_2be7e8, 0.0f);
        float second = *(float *)(*(char **)(mount + 0x150) + 0x28);
        QW vector;
        asm("pextlw %0, %1, %2\n\tpcpyld %0, %3, %0" : "=r"(vector) : "r"(0), "r"(0), "r"(second));
        if (*(int *)(mount + 0x230) > 0) {
            char *entry = mount + 0x234;
            do {
                void *link = *(void **)(entry + 0xC);
                if (link != 0) {
                    func_0012D108(link, vector);
                }
                void *sma = *(void **)(entry + 0x14);
                if (sma != 0) {
                    if (*(float *)(*(char **)(mount + 0x150) + 0x2C) > 0.0f) {
                        SetSmaGoal__FP3SMA3OID(sma, 0x68);
                    } else {
                        SetSmaGoal__FP3SMA3OID(sma, 0x66);
                    }
                }
                index += 1;
                entry += 0x18;
            } while (index < *(int *)(mount + 0x230));
        }
        break;
    }
    }
    if (*(char **)(mount + 0x2A4) != 0) {
        float goal;
        if (*(unsigned *)(mount + 0x1C0) == 1) {
            goal = *(float *)(*(char **)(mount + 0x150) + 0x1C);
        } else {
            goal = 0.0f;
        }
        float smoothed = GSmooth__FfffP3SMPPf(*(float *)(mount + 0x2AC), goal, g_2dded4, &D_002BE7F0, 0);
        *(float *)(mount + 0x2AC) = smoothed;
        SetAmbVolume(*(char **)(mount + 0x2A4), smoothed);
        char *amb = *(char **)(mount + 0x2A4);
        if (*(float *)(mount + 0x2AC) > 0.0f) {
            if (*(short *)(amb + 0x4E) > 0) {
                ContinueAmb(amb);
            }
        } else if (*(short *)(amb + 0x4E) <= 0) {
            PauseAmb(amb);
        }
    }
}
}
