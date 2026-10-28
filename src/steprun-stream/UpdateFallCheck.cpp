struct VT { char pad[0x260]; short delta; short index; int (*fn)(void *, int, void *); };
struct Guard { char pad[0xC]; VT *vt; };
struct Check { Guard *guard; int state; float t; int active; };
extern float g_2dded0;
extern float D_002C3DF0;
extern "C" {
int FGuardOffGround(Check *);
void SetFallCheckState(Check *, int);
}

void UpdateFallCheck(Check *check)
{
    if (check->active != 0) {
        int off = FGuardOffGround(check);
        int state;
        do {
            state = check->state;
            switch (state) {
            case 0:
                if (off != 0) SetFallCheckState(check, 1);
                break;
            case 1:
                if (off == 0) {
                    SetFallCheckState(check, 0);
                } else if (g_2dded0 - check->t > D_002C3DF0) {
                    register Guard *guard asm("$6") = check->guard;
                    if (guard->vt->fn((char *)guard + guard->vt->delta, 0x4000, guard) == 0)
                        SetFallCheckState(check, 2);
                }
                break;
            case 2:
                if (off == 0) SetFallCheckState(check, 0);
                break;
            }
        } while (check->state != state);
    }
}
