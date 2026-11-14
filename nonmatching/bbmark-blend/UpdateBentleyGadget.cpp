struct GADGETVT136118 { char pad[0x260]; short delta; short index; void (*fn)(void *, int); };
struct GADGET136118 { char pad0[0xC]; GADGETVT136118 *vt; char pad1[0x148]; int kind; char pad2[0x44]; int stickArg; };
struct BENTLEY136118;
extern "C" {
extern float g_2dded0;
int FAsegaGone(int);
int FVjoyButtonHeld(int, int);
int GrfbtnJtGadget(BENTLEY136118 *, int);
void ReleaseBentleyGadget(BENTLEY136118 *);
void SetBentleyGadgetAnim(BENTLEY136118 *, int);
void SetJmpState(void *, int, int, int);
void StickGadgetObj(GADGET136118 *, int);
}
#define FIELD136118(type, offset) (*(type *)((char *)pbentley + (offset)))
void UpdateBentleyGadget(BENTLEY136118 *pbentley)
{
    int state;
    do {
        state = FIELD136118(int, 0x16B0);
        if (state == 0) {
            if (FAsegaGone(FIELD136118(int, 0x1030)))
                SetBentleyGadgetAnim(pbentley, 1);
        } else if (state >= 0) {
            if (state < 3) {
                GADGET136118 *pgadget = FIELD136118(GADGET136118 *, 0x186C);
                int kind = pgadget->kind;
                if (kind == 2) {
                    StickGadgetObj(pgadget, pgadget->stickArg);
                } else {
                    if (kind == 4 || !FVjoyButtonHeld(FIELD136118(int, 0x150), GrfbtnJtGadget(pbentley, **FIELD136118(int **, 0x16B4)) | 0x10)) {
                        pgadget->vt->fn((char *)pgadget + pgadget->vt->delta, 1);
                    } else {
                        if (g_2dded0 - FIELD136118(float, 0x20C) > 0.1f)
                            SetBentleyGadgetAnim(pbentley, 2);
                        else
                            SetBentleyGadgetAnim(pbentley, 1);
                        continue;
                    }
                }
                ReleaseBentleyGadget(pbentley);
                SetJmpState((char *)pbentley + 0x2C0, 0xB, 0, 0);
            }
        }
    } while (FIELD136118(int, 0x16B0) != state && FIELD136118(int, 0x13D0) == 6);
}
