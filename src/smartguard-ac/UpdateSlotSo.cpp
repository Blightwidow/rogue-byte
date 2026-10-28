struct SO {
    char pad0[0x168];
    float dtFade;
    int pcrvWander;
    char pad1[0x1C4 - 0x170];
    int pactAnim;
    char pad2[0x220 - 0x1C8];
    int state;
    int pad224;
    float tNext;
    float tFade;
};
extern float g_2dded0;
extern float g_2a70e0;
extern "C" {
void UpdateSo(SO *, float);
int SenseSlotSoTargetState(SO *);
int FSlotSoFacingHeading(SO *);
void FadeAloOut(SO *, float);
void SetSlotSoState(SO *, int);
void SteerSlotSoAlongCrv(SO *);
}

extern "C" void UpdateSlotSo(SO *pso, float dt)
{
    UpdateSo(pso, dt);
    int stateNext = pso->state;
    switch (pso->state) {
    case 0: {
        stateNext = SenseSlotSoTargetState(pso);
        if (stateNext != 3 && pso->tNext <= g_2dded0) {
            if (pso->pcrvWander)
                stateNext = 1;
        }
        break;
    }
    case 1:
        stateNext = SenseSlotSoTargetState(pso);
        if (stateNext != 3 && pso->tNext <= g_2dded0)
            stateNext = 0;
        break;
    case 2:
        stateNext = SenseSlotSoTargetState(pso);
        if (stateNext != 3 && FSlotSoFacingHeading(pso))
            stateNext = 1;
        break;
    case 3:
        if (pso->pactAnim == 0 && FSlotSoFacingHeading(pso))
            stateNext = 4;
        break;
    case 4:
        if (pso->tFade <= g_2dded0) {
            FadeAloOut(pso, pso->dtFade);
            pso->tFade = g_2a70e0;
        }
        break;
    }
    SetSlotSoState(pso, stateNext);
    SteerSlotSoAlongCrv(pso);
}
