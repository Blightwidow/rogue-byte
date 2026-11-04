typedef signed char s8; typedef short s16; typedef int s32;
typedef float f32;

extern "C" {
void SetAsegaMasterSpeed(s8 *, f32);

void SetAsegsvtMaster(s8 *arg0, f32 fparg0) {
    /* stack area retail keeps at 0x0..0xF with no stores */
    s8 sp[0x10] __attribute__((aligned(16)));
    s8 *var_s0;

    var_s0 = *(s8 **)(arg0 + 0x50);
    if (var_s0 != 0) {
        do {
            SetAsegaMasterSpeed(var_s0, fparg0);
            var_s0 = *(s8 **)(var_s0 + 0x2C);
        } while (var_s0 != 0);
    }
    *(f32 *)(arg0 + 0x78) = fparg0;
}

}
