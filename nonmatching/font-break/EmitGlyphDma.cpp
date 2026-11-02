struct VIFS { char pad[0xC]; char *p; };
extern "C" {
extern VIFS g_2dea28;
static inline void Skip(VIFS *pv, int n) { pv->p = pv->p + n; }
static inline void Pad(VIFS *pv) { while ((int)pv->p & 0xF) { *(int *)pv->p = 0; pv->p = pv->p + 4; } }
static inline void Tail(VIFS *pv, char *tail)
{
    *(int *)pv->p = 0x6C03C004;
    int *to = (int *)(pv->p += 4);
    int *from = (int *)tail;
    int n = 8;
    do {
        n -= 4;
        int w0 = from[0]; int w1 = from[1]; int w2 = from[2]; int w3 = from[3];
        from += 4;
        to[0] = w0; to[1] = w1; to[2] = w2; to[3] = w3;
        to += 4;
    } while (n >= 0);
    pv->p = pv->p + 0x30;
}
void EmitGlyphDma(char *self, char *src, char *tail, int flags)
{
    char *tag = g_2dea28.p;
    *(long *)tag = 0x10000000;
    g_2dea28.p = g_2dea28.p + 0x10;
    int *to;
    int *from;
    int n;
    if (flags & 1) {
        *(int *)(g_2dea28.p) = 0x6C04C000;
        from = (int *)src;
        to = (int *)(g_2dea28.p += 4);
        flags &= 2;
        n = 0xC;
        do {
            n -= 4;
            int w0 = from[0]; int w1 = from[1]; int w2 = from[2]; int w3 = from[3];
            from += 4;
            to[0] = w0; to[1] = w1; to[2] = w2; to[3] = w3;
            to += 4;
        } while (n >= 0);
        g_2dea28.p = g_2dea28.p + 0x40;
    } else {
        *(int *)(g_2dea28.p) = 0x6C01C002;
        from = (int *)(src + 0x20);
        to = (int *)(g_2dea28.p += 4);
        flags &= 2;
        n = 0;
        do {
            n -= 4;
            int w0 = from[0]; int w1 = from[1]; int w2 = from[2]; int w3 = from[3];
            from += 4;
            to[0] = w0; to[1] = w1; to[2] = w2; to[3] = w3;
            to += 4;
        } while (n >= 0);
        g_2dea28.p = g_2dea28.p + 0x10;
    }
    *(int *)(tail + 0xC) = 0x7FFF;
    if (*(unsigned short *)(self + 0x12) < 2U)
        *(int *)(tail + 4) = 0;
    else
        *(int *)(tail + 4) = 1;
    if (flags != 0 || *(int *)(tail + 4) != 0) {
        Tail(&g_2dea28, tail);
    }
    Pad(&g_2dea28);
    *(int *)tag |= (int)((g_2dea28.p - tag) >> 4) - 1;
    Pad(&g_2dea28);
    *(long *)g_2dea28.p = ((long)*(int *)(self + 0x1C) << 32) | 0x50000000;
    Skip(&g_2dea28, 0x10);
}
}
