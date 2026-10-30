typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
typedef struct Request_2544C8 {
    s32 kind;
    s64 low;
    s64 high;
} Request_2544C8;
int func_0024B670(s32, Request_2544C8 *);
u32 func_00252148(s8 *, int);
s32 func_00252230(s8 *, int);
void func_002539D0(s8 *);
void func_00253C80(s8 *);
void func_00253D20(s8 *);
void func_002544C0(s8 *, int);
void func_00254628(s8 *);
s32 func_002544C8(s8 *arg0) {
    Request_2544C8 request;
    u32 code;
    for (;;) {
        if (M2C_FIELD(arg0, s32 *, 0x878) != 0) {
            return -1;
        }
        func_00254628(arg0);
        while (func_00252230(arg0, 0x18) != 1 && M2C_FIELD(arg0, s32 *, 0x878) == 0) {
            func_002544C0(arg0, 8);
        }
        code = func_00252148(arg0, 0x20);
        switch (code) {
        case 0x1B3:
            func_002539D0(arg0);
            break;
        case 0x1B8:
            func_00253C80(arg0);
            break;
        case 0x100:
            func_00253D20(arg0);
            request.kind = 5;
            request.low = -1;
            request.high = -1;
            func_0024B670(M2C_FIELD(arg0, s32 *, 0x868), &request);
            M2C_FIELD(arg0, s64 *, 0x838) = request.low;
            M2C_FIELD(arg0, s64 *, 0x840) = request.high;
            return M2C_FIELD(arg0, s32 *, 0x160);
        case 0x1B7:
            return 0;
        }
    }
}
