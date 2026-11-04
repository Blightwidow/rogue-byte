struct VIFS { char pad[0xC]; char *p; };
struct SLOT { int a; float f; int c; int d; };
extern "C" {
extern VIFS g_2dea28;
extern char VU1_START_0[], VU1_ENTRY_C0[], VU1_ENTRY_100[];
SLOT *OnGameLoad__FP4GAME(void);
static inline void Pad(VIFS *pv) { while ((int)pv->p & 0xF) { *(int *)pv->p = 0; pv->p = pv->p + 4; } }
static inline void Emit(VIFS *pv, unsigned first, unsigned second)
{
    *(int *)pv->p = 0x13000000;
    *(unsigned *)(pv->p += 4) = first | 0x14000000;
    *(unsigned *)(pv->p += 4) = second | 0x14000000;
    *(int *)(pv->p += 4) = 0x13000000;
    pv->p += 4;
}
void func_00217298(char *self, int kind, int unused, float base)
{
    char *tag = g_2dea28.p;
    *(long *)tag = 0x10000000;
    g_2dea28.p = g_2dea28.p + 0x10;
    switch (kind) {
    case 1:
        *(int *)g_2dea28.p = 0x13000000;
        *(unsigned *)(g_2dea28.p += 4) = ((unsigned)VU1_START_0 >> 3) | 0x14000000;
        *(unsigned *)(g_2dea28.p += 4) = ((unsigned)(VU1_ENTRY_C0) >> 3) | 0x14000000;
        *(int *)(g_2dea28.p += 4) = 0x13000000;
        g_2dea28.p += 4;
        break;
    case 2:
        *(int *)g_2dea28.p = 0x13000000;
        *(unsigned *)(g_2dea28.p += 4) = ((unsigned)(VU1_START_0 + 0x30) >> 3) | 0x14000000;
        *(unsigned *)(g_2dea28.p += 4) = ((unsigned)(VU1_ENTRY_C0) >> 3) | 0x14000000;
        *(int *)(g_2dea28.p += 4) = 0x13000000;
        g_2dea28.p += 4;
        break;
    case 3:
        *(int *)g_2dea28.p = 0x13000000;
        *(unsigned *)(g_2dea28.p += 4) = ((unsigned)(VU1_ENTRY_100) >> 3) | 0x14000000;
        *(unsigned *)(g_2dea28.p += 4) = ((unsigned)(VU1_START_0 + 0x60) >> 3) | 0x14000000;
        *(int *)(g_2dea28.p += 4) = 0x13000000;
        g_2dea28.p += 4;
        break;
    case 4:
        *(int *)g_2dea28.p = 0x13000000;
        *(unsigned *)(g_2dea28.p += 4) = ((unsigned)(VU1_ENTRY_100) >> 3) | 0x14000000;
        *(unsigned *)(g_2dea28.p += 4) = ((unsigned)(VU1_START_0 + 0x90) >> 3) | 0x14000000;
        *(int *)(g_2dea28.p += 4) = 0x13000000;
        g_2dea28.p += 4;
        break;
    }
    Pad(&g_2dea28);
    *(int *)tag |= (int)((g_2dea28.p - tag) >> 4) - 1;
    *(long *)g_2dea28.p = 0x60000000;
    g_2dea28.p += 0x10;
    SLOT *slot = OnGameLoad__FP4GAME();
    slot->a = 0x15;
    float scaled = (float)(*(int *)(self + 0xA4) << 0x12);
    slot->c = (int)tag & 0x0FFFFFFF;
    slot->d = 0;
    slot->f = base + scaled;
}
}
