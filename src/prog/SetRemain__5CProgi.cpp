struct CProg1C8D40 { int f0; int f4; int f8; int fC; char pad[0x40]; int f50; };
extern "C" {
void ClearFrameBuffers__Fv(void);
void Draw__5CProg(CProg1C8D40 *);
void SetRemain__5CProgi(CProg1C8D40 *prog, int remain)
{
    if (prog->f0 != 0) {
        if (prog->f8 == 0) {
            prog->f8 = remain;
            prog->f4 = remain * 2;
            ClearFrameBuffers__Fv();
            prog->fC = remain;
        } else {
            if (prog->fC == remain)
                prog->f50++;
            else
                prog->f50 = 0;
            prog->fC = remain;
        }
        Draw__5CProg(prog);
    }
}
}
