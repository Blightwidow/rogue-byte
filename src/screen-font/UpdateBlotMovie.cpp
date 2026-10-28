struct CLK { char pad[0x3C]; float t; };
struct BLOT {
    char pad0[0x58]; int blots; float f5C; char pad1[4]; int req; float f68; char pad2[8];
    int f74; int f78; int f7C; char pad3[4]; void *f84; float f88; float f8C;
};
extern "C" {
void UpdateLo(BLOT *);
int FBlotLabelPlaying(BLOT *, int);
void SetTimerTimers__FP5TIMER6TIMERS(BLOT *, int);
void SetBlotBlots(BLOT *, int);
void UpdateRootSprite(void *, float);
extern CLK g_2dded0;
extern float g_2ddf10;
}
void UpdateBlotMovie(BLOT *blot)
{
    UpdateLo(blot);
    int blots = blot->blots;
    if (blots == 1) {
        if (blot->req == 2)
            blots = (blot->f74 == -1) ? 2 : 3;
    } else if (blot->f68 != g_2dded0.t) {
        switch (blots) {
        case 2:
            if (!FBlotLabelPlaying(blot, blot->f7C))
                SetTimerTimers__FP5TIMER6TIMERS(blot, 1);
            {
                float visible = blot->f8C;
                float zero;
                asm("mtc1 $0, %0\n\tnop" : "=f" (zero));
                if (zero < visible && visible < g_2dded0.t - blot->f5C)
                    SetTimerTimers__FP5TIMER6TIMERS(blot, 1);
            }
            if (blot->req == 1)
                blots = (blot->f78 == -1) ? 1 : 4;
            break;
        case 3:
            if (!FBlotLabelPlaying(blot, blot->f74)) {
                switch (blot->req) {
                case 1:
                    blots = (blot->f78 == -1) ? 1 : 4;
                    break;
                case 2:
                    blots = 2;
                    break;
                }
            }
            break;
        case 4:
            if (!FBlotLabelPlaying(blot, blot->f78)) {
                switch (blot->req) {
                case 1:
                    blots = 1;
                    break;
                case 2:
                    blots = (blot->f74 == -1) ? 2 : 3;
                    break;
                }
            }
            break;
        }
    }
    SetBlotBlots(blot, blots);
    if (blot->f7C != -1) {
        blot->f88 = blot->f88 + g_2ddf10;
        UpdateRootSprite(blot->f84, g_2ddf10);
    }
}
