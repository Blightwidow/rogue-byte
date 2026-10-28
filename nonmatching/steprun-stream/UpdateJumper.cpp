struct SO { char pad[0x208]; int hit; char pad1[0x498 - 0x20C]; void *pcheck; };
struct JUMPER { char pad[0x10]; int state; float tState; char pad1[0x34 - 0x18]; SO *pso; void *pasega; char pad2[0x50 - 0x3C]; float tLand; float tLandStart; char pad3[0x60 - 0x58]; int flight; };
extern float g_2dded0;
extern float D_002C3DE0;
extern "C" {
void SetJumperState(JUMPER *, int);
int FIsBasicDerivedFrom(SO *, int);
void EnableFallCheck(void *);
int FAsegaGone(void *);
void UpdateJumper(JUMPER *pjumper)
{
    for (;;) {
        int state = pjumper->state;
        switch (state) {
        case 1:
            if (pjumper->pso->hit != 0 && pjumper->tState + 0.15f < g_2dded0)
                SetJumperState(pjumper, 3);
            else if (pjumper->tLandStart <= g_2dded0)
                SetJumperState(pjumper, 2);
            break;
        case 2:
            if (pjumper->pso->hit != 0 || D_002C3DE0 < g_2dded0 - pjumper->tLand)
                SetJumperState(pjumper, 3);
            else if (pjumper->tLand <= g_2dded0) {
                if (pjumper->flight != 0)
                    SetJumperState(pjumper, 3);
                else if (FIsBasicDerivedFrom(pjumper->pso, 0x38))
                    EnableFallCheck(pjumper->pso->pcheck);
            }
            break;
        case 3:
            if (FAsegaGone(pjumper->pasega))
                SetJumperState(pjumper, 4);
            break;
        default:
            break;
        }
        if (state == pjumper->state) return;
    }
}
}
