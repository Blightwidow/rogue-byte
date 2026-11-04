typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s128 bevy_classes_k30_cam_150780();                 /* extern */
s128 bevy_classes_k30_cam_1507f8(s8 *);           /* extern */

void bevy_classes_k30_cam_150ef0(s8 *arg0) {
    f32 temp_f1;

    M2C_FIELD(arg0, s128 *, 0x20) = bevy_classes_k30_cam_150780();
    M2C_FIELD(arg0, s128 *, 0x30) = bevy_classes_k30_cam_1507f8(arg0);
    temp_f1 = M2C_FIELD(arg0, f32 *, 0x18);
    if (temp_f1 >= 0.0f) {
        M2C_FIELD(arg0, f32 *, 0xAC) = temp_f1;
    }
    M2C_FIELD(arg0, s128 *, 0x50) = (s128) M2C_FIELD(arg0, s128 *, 0x80);
    M2C_FIELD(arg0, s128 *, 0x60) = (s128) M2C_FIELD(arg0, s128 *, 0x90);
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) M2C_FIELD(arg0, f32 *, 0xA0);
}

}
