typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InitPipe__FP4PIPE {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

M2C_UNK InitCrv();                                  /* extern */
void bevy_player_p6_182c70(s32);                 /* extern */
extern s128 g_2a2da0;

void InitPipe__FP4PIPE(s8 *arg0) {
    InitCrv();
    bevy_player_p6_182c70((int)(arg0 + 0x190));
    M2C_FIELD(arg0, s128 *, 0x1C0) = (s128) g_2a2da0;
    M2C_FIELD(arg0, s32 *, 0x1D4) = 9;
    M2C_FIELD(arg0, s32 *, 0x1D0) = 8;
    M2C_FIELD(arg0, s32 *, 0x1AC) = 1;
}

}
