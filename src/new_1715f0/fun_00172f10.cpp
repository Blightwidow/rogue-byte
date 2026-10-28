struct GOAL { char pad[0x10]; float pos[4]; };
struct QWV { char b[16]; } __attribute__((aligned(16)));
extern "C" {
int GoalGoto_FArrived(void *);
void func_002562A8(void *);
void SetGoalTarget(void *, void *);
}
extern const float D_002A53D4;
extern float g_2dded0;
extern "C" void func_00172F10(char *pbeh)
{
    if (*(unsigned *)(pbeh + 0xD0) < 4) {
        void *psub = *(void **)(pbeh + 0x18);
        if (*(float *)(pbeh + 0x3C) == D_002A53D4) {
            if (GoalGoto_FArrived(psub))
            {
                float one;
                asm("lui $1, 0x3F80\n\tmtc1 $1, %0\n\tnop" : "=f" (one) : : "$1");
                *(float *)(pbeh + 0x3C) = g_2dded0 + one;
            }
        }
        if (g_2dded0 < *(float *)(pbeh + 0x3C))
            return;
        {
            unsigned islot = *(unsigned *)(pbeh + 0xD0);
            QWV *pposLook = (QWV *)(pbeh + 0x50 + islot * 0x20);
            islot++;
            *(unsigned *)(pbeh + 0xD0) = islot;
            if (islot > 3)
                *(unsigned *)(pbeh + 0xD0) = 0;
            GOAL goal;
            func_002562A8(&goal);
            *(QWV *)goal.pos = *pposLook;
            SetGoalTarget(psub, &goal);
            *(float *)(pbeh + 0x3C) = D_002A53D4;
        }
    }
}
