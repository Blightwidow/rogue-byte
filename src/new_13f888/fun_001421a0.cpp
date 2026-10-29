typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64;

extern "C" {
void Carry_Attach(s32, s32);
void Carry_Detach(s32);
void SetJtAttach5(s32, s32);

void func_001421A0(s32 arg0, s32 arg1) {
    SetJtAttach5(arg0, 0);
    if (arg1 != 0) {
        Carry_Attach(arg0 + 0x900, arg1);
        return;
    }
    Carry_Detach(arg0 + 0x900);
}

}
