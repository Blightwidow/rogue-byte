struct Vjoy1C42E8 { char pad[0x10]; float f10, f14, f18, f1c, f20, f24, f28, f2c; int i30; };
extern "C" void ClearVjoyPresses(Vjoy1C42E8 *, int);
extern "C" void ResetVjoy(Vjoy1C42E8 *vjoy)
{
    float zero = 0.0f;
    vjoy->f1c = zero;
    vjoy->f18 = zero;
    vjoy->f14 = zero;
    vjoy->f10 = zero;
    vjoy->f2c = zero;
    vjoy->f28 = zero;
    vjoy->f24 = zero;
    vjoy->i30 = 0;
    vjoy->f20 = zero;
    ClearVjoyPresses(vjoy, 0xFFFF);
}
