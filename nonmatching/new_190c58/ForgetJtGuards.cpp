typedef int QW __attribute__((mode(TI)));

extern "C" void *PentryFindSensorLo(int, void *);
extern "C" QW PosLoWorld(void *);
extern "C" void SetSensorEntryState(void *, void *, int);
extern "C" void CStackFrame_Construct(void *, void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void bevy_camera_follow_push_out(void *, QW, QW, void *, void *, int *, int *);
extern "C" int PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, int, int);
extern "C" void *B_003E1444;
extern "C" char B_003DD490[];
extern "C" char FFilterSensorSight[];
extern "C" float g_2bf638;

void ForgetJtGuards(void **arg0)
{
    char *pguard = (char *)B_003E1444;
    if (pguard == 0)
        return;
    int sp4;
    int sp8;
    QW sp10;
    QW sp20;
    char sp1[0x20];
    for (; pguard != 0; ) {
        void *pentry = PentryFindSensorLo(*(int *)(pguard + 0xF64), *arg0);
        if (pentry != 0 && *(int *)((char *)pentry + 4) != 0
                && !(*(int *)(*(char **)(pguard + 0xF64) + 0xF8) & 1)) {
            sp10 = PosLoWorld(pguard);
            sp20 = PosLoWorld(*arg0);
            register float distance asm("$f0");
            asm volatile(
                ".word 0x48A21800\n\t"
                "lqc2 $vf2, 0(%1)\n\t"
                ".word 0x4BE3106C\n\t"
                ".word 0x4BC1086A\n\t"
                ".word 0x4B000083\n\t"
                ".word 0x4B01083D\n\t"
                ".word 0x4B01104A\n\t"
                ".word 0x4A0103BD\n\t"
                "vwaitq\n\t"
                ".word 0x4B000060\n\t"
                ".word 0x48230800\n\t"
                "mtc1 $3, $f0\n\t"
                : "=f"(distance) : "r"(&sp10) : "$3");
            int isOutOfRange = 1;
            if (!(g_2bf638 < distance))
                isOutOfRange = 0;
            if (isOutOfRange != 0) {
                SetSensorEntryState(*(void **)(pguard + 0xF64), pentry, 0);
            } else {
                CStackFrame_Construct(sp1, pentry);
                bevy_camera_follow_push_out(B_003DD490, sp10, sp20, FFilterSensorSight, pguard, &sp4, &sp8);
                if (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp10, sp20, sp4, sp8, 0) != 0) {
                    SetSensorEntryState(*(void **)(pguard + 0xF64), pentry, 0);
                    CStackFrame_Destructor(sp1, 2);
                } else {
                    CStackFrame_Destructor(sp1, 2);
                }
            }
        }
        pguard = (char *)*(void **)(pguard + 0xFE0);
    }
}
