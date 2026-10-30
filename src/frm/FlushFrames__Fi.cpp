// g_2deb20 is set by the render thread (FrameRenderLoop) and polled here, hence volatile (the only volatile)
struct FRM { char pad0[0x30]; unsigned grf; char pad1[0x50 - 0x34]; };
extern "C" int WaitSema(int);
extern "C" int SignalSema(int);
extern "C" void func_001C2BA8(int);
void RenderFrame__FP3FRMi(FRM *, int);
void BlendPrevFrame__Fv();
void SwapGsBuffers__Fv();
void ClearPendingFrame__FP3FRM(FRM *);
extern int g_2deb1c;
extern volatile int g_2deb20;
extern FRM *g_2deb14;
extern int g_2dedbc;
extern FRM B_002DEA50[2];
void FlushFrames__Fi(int fRedraw)
{
    unsigned index = 0;
    do {
        WaitSema(g_2deb1c);
        index++;
    } while (index < 2);
    index = 0;
    do {
        SignalSema(g_2deb1c);
        index++;
    } while (index < 2);
    while (g_2deb20 == 0) {
    }
    if (fRedraw != 0) {
        if (g_2deb14 != 0) {
            for (int count = 0; count < 3; count++) {
                RenderFrame__FP3FRMi(g_2deb14, 1);
                if (g_2deb14->grf & 1)
                    BlendPrevFrame__Fv();
                SwapGsBuffers__Fv();
            }
            g_2dedbc = 3;
        }
        if (fRedraw != 0) {
            FRM *pfrm = B_002DEA50;
            do {
                ClearPendingFrame__FP3FRM(pfrm);
                pfrm++;
            } while (pfrm < B_002DEA50 + 2);
        }
    }
    func_001C2BA8(3);
    g_2deb14 = 0;
}
