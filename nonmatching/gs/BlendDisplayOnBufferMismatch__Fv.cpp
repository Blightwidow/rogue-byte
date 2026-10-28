struct Q8 { char b[8]; };
struct DISPENV { Q8 pmode; Q8 smode2; Q8 dispfb; Q8 display; Q8 bgcolor; };
struct GSREGS { Q8 pmode; char pad0[0x68]; Q8 dispfb1; char pad1[0x8]; Q8 display1; char pad2[0xF80]; unsigned csr; };
#define GS ((GSREGS *)0x12000000)
extern "C" int g_2dedb0;
extern "C" int g_2dedb8;
extern "C" DISPENV B_002DEB80[];
union U8 { Q8 raw; unsigned long v; };
extern "C" void BlendDisplayOnBufferMismatch__Fv(void)
{
    int index = g_2dedb0 & 1;
    int field = g_2dedb8;
    DISPENV *env = &B_002DEB80[index];
    U8 pmode, display, dispfb;
    pmode.raw = env->pmode;
    if (field != ((GS->csr >> 13) & 1)) {
        display.raw = env->display;
        dispfb.raw = env->dispfb;
        int dh = (display.v >> 44) & 0x7FF;
        display.v = (display.v & 0xFF800FFFFFFFFFFFUL) | ((unsigned long)((dh - 1) & 0x7FF) << 44);
        if (field != 0) {
            int dy = (long)(display.v << 20) >> 32;
            dy &= 0x7FF;
            display.v = (display.v & 0xFFFFFFFFFF800FFFUL) | ((unsigned long)((dy + 1) & 0x7FF) << 12);
        } else {
            int dby = (dispfb.v >> 43) & 0x7FF;
            dispfb.v = (dispfb.v & 0xFFC007FFFFFFFFFFUL) | ((unsigned long)((dby + 1) & 0x7FF) << 43);
        }
        GS->display1 = display.raw;
        GS->dispfb1 = dispfb.raw;
        pmode.v |= 1;
    }
    GS->pmode = pmode.raw;
}
