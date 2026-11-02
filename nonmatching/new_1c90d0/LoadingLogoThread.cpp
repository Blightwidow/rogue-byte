struct SEMA_1C9190 { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; };
struct XF2_1C9190 { float a, b, c, d, x, y, pad0, pad1; };
struct CLOCK_1C9190 { char pad[0x3C]; float tReal; };
struct DMAS_1C9190 { char pad[0xC]; int mark; char pad10[0x10]; int field20; };
struct DLI_1C9190 { char pad[0x24]; int mark; char pad28[8]; int grf; };
extern "C" {
void WaitSema(int);
void SignalSema(int);
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
extern DLI_1C9190 *g_2dea4c;
extern char B_002DF260[];
extern char B_002DEA00[];
}

static inline void SetMark(int mark)
{
    g_2dea4c->mark = mark;
}

static inline void InitXf(XF2_1C9190 *pxf)
{
    memset(pxf, 0, sizeof(*pxf));
    pxf->d = 1.0f;
}

extern "C" void LoadingLogoThread()
{
    SEMA_1C9190 status;
    XF2_1C9190 xf;
    for (;;) {
        WaitSema(B_003D3A3C);
        g_2dedbc = 0;
        while ((MarkClockTick__FP5CLOCK(&g_2dded0, 1),
                OpenFrame__Fv(),
                SetMark(g_2dea28.mark),
                g_2dea28.field20 = 1,
                AddDmaCnt__4DMAS(&g_2dea28),
                AddVifDirect__4VIFSiP2QWi(&g_2dea28, 0x25, B_002DF260, 0),
                EndDmaCnt__4DMAS(&g_2dea28),
                ReferSemaStatus(B_003D3A40, &status),
                status.count == 0)) {
            float t = g_2dded0.tReal - *g_2dd314;
            float scale = g_2c10b0 * sinf(t * g_2c10b4) + 1.0f;
            InitXf(&xf);
            xf.a = (float)g_2c10a0 * scale;
            xf.d = (float)g_2c10a4 * scale;
            xf.x = (float)g_2c10a8;
            xf.y = (float)g_2c10ac;
            float value = g_2c10c0[0] + t * (g_2c10c0[1] + t * g_2c10c0[2]);
            float low = g_2bbb60[0];
            float high = g_2bbb60[1];
            if (value < low)
                value = low;
            else if (high < value)
                value = high;
            DrawLoadingLogo(B_002DEA00, &xf, value);
            CloseFrame__Fv();
            g_2be538++;
        }
        g_2dea4c->grf &= ~1;
        CloseFrame__Fv();
        g_2be538++;
        do {
            ReferSemaStatus(g_2deb18, &status);
        } while (status.count == 0);
        WaitSema(B_003D3A40);
        SignalSema(B_003D3A44);
    }
}
