#include "types.h"
extern "C" {
typedef char *va_list;
s32 func_00239450(void);
void func_002394A0(void);
s32 func_00235B08(s32 (*)(s32, s32, s32), s32 *, u32, s32, va_list);
s32 func_00236878(s32, s32, s32);
void func_00236960(s32 ctx, ...) {
    s32 state[4];
    s32 interruptsWereEnabled;
    state[0] = 0;
    interruptsWereEnabled = func_00239450();
    func_00235B08(func_00236878, state, 0xFFFFFFFF, ctx, (va_list)__builtin_next_arg(ctx) - 56);
    if (interruptsWereEnabled != 0) {
        func_002394A0();
    }
}
}
