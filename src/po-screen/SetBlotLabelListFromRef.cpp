typedef signed char s8; typedef short s16; typedef int s32;

extern "C" {
void CRef_Destruct(s8 *);
void func_002013D8(s8 *, s32, s32, s32, s8 *, s8 *);

void SetBlotLabelListFromRef(s8 *arg0, s32 arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s8 *temp_v0;

    func_002013D8(sp, arg1, 0x10, 0xA, sp + 0x10, arg0 + 0xCC);
    CRef_Destruct(sp);
    temp_v0 = *(s8 **)(arg0 + 0xC);
    (*(void (**)(s8 *, s32))(temp_v0 + 0x18C))(arg0 + *(s16 *)(temp_v0 + 0x188), -1);
}

}
