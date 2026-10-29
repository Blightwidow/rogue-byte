typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void AddSoAcceleration(s32, s128);
void AddSoAngularAcceleration(s32, s128);

void AddJtHangBodyReaction(void *arg0) {
    AddSoAcceleration(M2C_FIELD(M2C_FIELD(arg0, void **, 0x1900), s32 *, 4), M2C_FIELD(arg0, s128 *, 0x1930));
    AddSoAngularAcceleration(M2C_FIELD(M2C_FIELD(arg0, void **, 0x1900), s32 *, 4), M2C_FIELD(arg0, s128 *, 0x1940));
}

}
