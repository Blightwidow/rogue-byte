// SPDX-License-Identifier: GPL-3.0-or-later
struct SEMA_1C9190 { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; };
struct XF2_1C9190 { float a, b, c, d, x, y, pad0, pad1; };
struct CLOCK_1C9190 { char pad[0x3C]; float tReal; };
struct DMAS_1C9190 { char pad[0xC]; int mark; char pad10[0x10]; int field20; };
struct FRM_1C9190 { char pad[0x24]; int mark; char pad28[8]; int grf; };
extern "C" {
int WaitSema(int);
int SignalSema(int);
int ReferSemaStatus(int, SEMA_1C9190 *);
float sinf(float);
void *memset(void *, int, unsigned int);
void DrawLoadingLogo(void *, XF2_1C9190 *, float);
void CloseFrame__Fv();
void OpenFrame__Fv();
void MarkClockTick__FP5CLOCK(CLOCK_1C9190 *, int);
void AddDmaCnt__4DMAS(DMAS_1C9190 *);
void AddVifDirect__4VIFSiP2QWi(DMAS_1C9190 *, int, void *, int);
void EndDmaCnt__4DMAS(DMAS_1C9190 *);
extern int B_003D3A3C;
extern int B_003D3A40;
extern int B_003D3A44;
extern int g_2deb18;
extern int g_2dedbc;
extern int g_2be538;
extern CLOCK_1C9190 g_2dded0;
extern float *g_2dd314;
extern float g_2c10b4;
extern float g_2c10b0;
extern int g_2c10a0, g_2c10a4, g_2c10a8, g_2c10ac;
extern float g_2c10c0[];
extern float g_2bbb60[];
extern DMAS_1C9190 g_2dea28;
extern FRM_1C9190 *g_2dea4c;
extern char B_002DF260[];
extern char B_002DEA00[];
}

static inline void SetFrameMark(int mark)
{
    g_2dea4c->mark = mark;
}

static inline void InitXf(XF2_1C9190 *pxf)
{
    memset(pxf, 0, sizeof(*pxf));
    pxf->d = 1.0f;
}

// Retail: the outer loop waits on the start semaphore; the inner loop opens a frame, sends the VIF packet, then polls the stop
// semaphore and, while it is not signalled, draws the pulsing logo. The test sits at the bottom of the rotated inner loop, which
// a `for (;;)` with the exit `if ... break` at its head gives. The frame flag is cleared inside that exit branch: the access to
// g_2dea4c then counts at inner-loop depth, which gives its hoisted high part the priority that puts it in $s3 (as in retail)
// ahead of the coefficient table and the clock; written after the loop it lands in $s6 and the pointer and -2 swap $v1/$a0.
// SetFrameMark is inline so the mark is read before g_2dea4c (retail's load order).
extern "C" void LoadingLogoThread()
{
    SEMA_1C9190 status;
    XF2_1C9190 xf;
    for (;;) {
        WaitSema(B_003D3A3C);
        g_2dedbc = 0;
        for (;;) {
            MarkClockTick__FP5CLOCK(&g_2dded0, 1);
            OpenFrame__Fv();
            SetFrameMark(g_2dea28.mark);
            g_2dea28.field20 = 1;
            AddDmaCnt__4DMAS(&g_2dea28);
            AddVifDirect__4VIFSiP2QWi(&g_2dea28, 0x25, B_002DF260, 0);
            EndDmaCnt__4DMAS(&g_2dea28);
            ReferSemaStatus(B_003D3A40, &status);
            if (status.count != 0) {
                g_2dea4c->grf &= ~1;
                break;
            }
            float elapsed = g_2dded0.tReal - *g_2dd314;
            float scale = g_2c10b0 * sinf(elapsed * g_2c10b4) + 1.0f;
            InitXf(&xf);
            xf.a = (float)g_2c10a0 * scale;
            xf.d = (float)g_2c10a4 * scale;
            xf.x = (float)g_2c10a8;
            xf.y = (float)g_2c10ac;
            float alpha = g_2c10c0[0] + elapsed * (g_2c10c0[1] + elapsed * g_2c10c0[2]);
            float low = g_2bbb60[0];
            float high = g_2bbb60[1];
            if (alpha < low)
                alpha = low;
            else if (high < alpha)
                alpha = high;
            DrawLoadingLogo(B_002DEA00, &xf, alpha);
            CloseFrame__Fv();
            g_2be538++;
        }
        CloseFrame__Fv();
        g_2be538++;
        do {
            ReferSemaStatus(g_2deb18, &status);
        } while (status.count == 0);
        WaitSema(B_003D3A40);
        SignalSema(B_003D3A44);
    }
}
