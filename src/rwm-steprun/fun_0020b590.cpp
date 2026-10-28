/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct VT { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct GUARD { char pad0[0xC]; VT *vt; };
struct LIST { char pad[0x50]; int count; GUARD **pguards; };
void *memset(void *, int, unsigned int);
extern "C" {
extern const float RO_FLT_002A88CC;
extern float g_2dded0;
extern float g_2c3dbc;
void UpdateLo(void *);
void *func_00205458(void *, int);
void GoalBrain_SetCommand(void *, void *);
void ResetSensorStates(void *);
#define I(base, off) (*(int *)((char *)(base) + (off)))
#define F(base, off) (*(float *)((char *)(base) + (off)))
void func_0020B590(LIST *list)
{
    UpdateLo(list);
    int count = list->count;
    GUARD **pguards = list->pguards;
    for (int index = 0; index < count; index++) {
        GUARD *guard = pguards[index];
        if (((int)(*(unsigned long *)((char *)guard + 0x28) >> 60) & 1) != 0 && g_2dded0 - F(guard, 0xFF8) > g_2c3dbc) {
            switch (I(guard, 0x1000)) {
            case 1:
                guard->vt->fn((char *)guard + guard->vt->delta);
                break;
            case 0:
                break;
            case 2: {
                void *goal = func_00205458(guard, 0x9C);
                if (goal != 0) {
                    int command[0x70 / 4];
                    memset(command, 0, 0x70);
                    command[0] = 1;
                    GoalBrain_SetCommand(goal, command);
                }
                if (I(guard, 0xF64) != 0)
                    ResetSensorStates((void *)I(guard, 0xF64));
                break;
            }
            }
            F(guard, 0xFF8) = RO_FLT_002A88CC;
        }
    }
}
}
