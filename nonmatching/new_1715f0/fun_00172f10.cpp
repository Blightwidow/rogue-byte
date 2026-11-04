// SPDX-License-Identifier: GPL-3.0-or-later
struct GOAL_k02 { char pad[0x10]; float pos[4]; };
struct QWV_k02 { char b[16]; } __attribute__((aligned(16)));
extern "C" {
int GoalGoto_FArrived(void *);
void func_002562A8(void *);
void SetGoalTarget(void *, void *);
extern const float RO_FLT_002A53D4;
extern float g_2dded0;
}
extern "C" void func_00172F10(char *pbeh)
{
    if (*(unsigned *)(pbeh + 0xD0) < 4) {
        void *psub = *(void **)(pbeh + 0x18);
        if (*(float *)(pbeh + 0x3C) == RO_FLT_002A53D4) {
            if (GoalGoto_FArrived(psub)) {
                *(float *)(pbeh + 0x3C) = g_2dded0 + 1.0f;
            }
        }
        if (g_2dded0 < *(float *)(pbeh + 0x3C))
            return;
        {
            unsigned islot = *(unsigned *)(pbeh + 0xD0);
            QWV_k02 *pposLook = (QWV_k02 *)(pbeh + 0x50 + islot * 0x20);
            islot++;
            *(unsigned *)(pbeh + 0xD0) = islot;
            if (islot > 3)
                *(unsigned *)(pbeh + 0xD0) = 0;
            GOAL_k02 goal;
            func_002562A8(&goal);
            *(QWV_k02 *)goal.pos = *pposLook;
            SetGoalTarget(psub, &goal);
            *(float *)(pbeh + 0x3C) = RO_FLT_002A53D4;
        }
    }
}
