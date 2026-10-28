struct CLOCK {
    float t0;      // 0
    float d4;      // 4
    float scale8;  // 8
    float scaleC;  // C
    float d10;     // 10
    float t14;     // 14
    char pad18[0x24 - 0x18];
    float scale24; // 24
    char pad28[0x3C - 0x28];
    float t3C;     // 3C
    float d40;     // 40
    char pad44[4];
    unsigned long ticks; // 48
};
extern "C" {
extern char B_002DEB30;
unsigned long TickReadCount(void);
void UpdatePlayTime(void *);
}

void MarkClockTick__FP5CLOCK(CLOCK *clock, int realOnly)
{
    unsigned long now = TickReadCount();
    unsigned long diff = now - clock->ticks;
    float seconds = (float)diff * 3.390842e-9f;
    float hi = 0.033333335f;
    float dt;
    if (seconds < 0.016666668f)
        dt = 0.016666668f;
    else if (hi < seconds)
        dt = hi;
    else
        dt = seconds;
    float dtReal = dt * clock->scaleC;
    float dtScaled = dt * clock->scale24;
    clock->d10 = dtReal;
    clock->d40 = dtScaled;
    clock->t14 = clock->t14 + dtReal;
    if (realOnly == 0) {
        float dtGame = dtScaled * clock->scale8;
        clock->d4 = dtGame;
        clock->t0 = clock->t0 + dtGame;
        UpdatePlayTime(&B_002DEB30);
    }
    clock->ticks = now;
    clock->t3C = clock->t3C + clock->d40;
}
