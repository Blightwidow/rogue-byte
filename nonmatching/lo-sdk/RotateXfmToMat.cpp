typedef int s32; typedef int s128 __attribute__((mode(TI)));
extern "C" {
struct Rows_231300 { s128 r0; s128 r1; s128 r2; };
void ConvertXfMat(Rows_231300 *, s32, s32, s32);
void InvalidateXfmMatWorld(char *, s128);
void RotateXfmToMat(char *arg0, s32 arg1) {
    Rows_231300 local;
    ConvertXfMat(&local, 0, *(s32 *)(arg0 + 0x50), arg1);
    char *temp = arg0 + 0x60;
    *(s128 *)(temp + 0x10) = local.r1;
    *(s128 *)(arg0 + 0x60) = local.r0;
    *(s32 *)(temp + 0xC) = 0;
    *(s128 *)(temp + 0x20) = local.r2;
    *(s32 *)(temp + 0x1C) = 0;
    *(s32 *)(temp + 0x2C) = 0;
    InvalidateXfmMatWorld(arg0, local.r1);
}
}
