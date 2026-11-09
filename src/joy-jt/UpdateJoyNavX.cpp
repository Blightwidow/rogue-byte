#include "types.h"
extern "C" {
s32 FJoyButtonPressed(char *, int);
struct CLOCK_G { char pad[0x3C]; float f3C; };
extern CLOCK_G g_2dded0;
extern float g_2ddf0c;
float fabsf(float);
#define F(t, o) (*(t *)(self + (o)))
s32 UpdateJoyNavX(char *self)
{
    float c;
    float base;
    if (F(s32, 0x1024) == 0) {
        s32 pressed = FJoyButtonPressed(self, 0xA000);
        if (pressed & 0x8000) {
            F(s32, 0x1024) = -1;
        } else if (pressed & 0x2000) {
            F(s32, 0x1024) = 1;
        } else if (0.8f <= F(float, 0x1044)) {
            float a = fabsf(F(float, 0x103C));
            float b = fabsf(F(float, 0x1040));
            if (b < a) {
                if (F(float, 0x103C) < 0.0f) {
                    F(s32, 0x1024) = -1;
                } else {
                    F(s32, 0x1024) = 1;
                }
            }
        }
        if (F(s32, 0x1024) == 0)
            goto done;
        c = 0.3333f;
        F(float, 0x1030) = c;
        base = g_2ddf0c;
    } else {
        s32 v1 = 0;
        if (F(s32, 0x1024) < 0) {
            if (F(s32, 0x10B4) & 0x8000) {
                v1 = 1;
            } else if (0.25f <= F(float, 0x1044)) {
                float a = fabsf(F(float, 0x103C));
                float b = fabsf(F(float, 0x1040));
                if (b < a) {
                    if (F(float, 0x103C) < 0.0f) v1 = 1;
                }
            }
        } else {
            if (F(s32, 0x10B4) & 0x2000) {
                v1 = 1;
            } else if (0.25f <= F(float, 0x1044)) {
                float a = fabsf(F(float, 0x103C));
                float b = fabsf(F(float, 0x1040));
                if (b < a) {
                    if (0.0f < F(float, 0x103C)) v1 = 1;
                }
            }
        }
        if (v1 == 0) {
            F(s32, 0x1024) = 0;
            goto done;
        }
        if (F(float, 0x102C) <= g_2dded0.f3C) {
            float lo = 0.1f;
            float hi = 0.3333f;
            float t = (F(float, 0x1030) + F(float, 0x1030)) * 0.33333334f;
            if (t < lo) {
                c = lo;
            } else if (hi < t) {
                c = hi;
            } else {
                c = t;
            }
            F(float, 0x1030) = c;
            base = g_2dded0.f3C;
        } else {
            return 0;
        }
    }
    F(float, 0x102C) = base + c;
done:
    return F(s32, 0x1024);
}
}
