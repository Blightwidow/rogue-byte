#include "types.h"
struct JOY_187998;
struct LM_187998;
struct CLOCK_187998 { char pad[0x3C]; float f3C; float f40; };
struct HELPER_187998 { char pad0[0x30C]; int f30C; int pad1; char *f314; };
extern "C" {
void *memset(void *, int, unsigned int);
s32 scePadRead(s32, s32, void *);
void CopyAb__FPvT0Ui(void *, void *, unsigned int);
void GetJoyXYDeflection__FP3JOYUcUcPfN23PUcT6PiP2LM(char *, u8, u8, float *, float *, float *, u8 *, u8 *, s32 *, void *);
void _MatchCodes__FP3JOYUs(void *, char *, unsigned short);
s32 PpoSwFocusBase(void *);
void bevy_camera_follow_activity(void *, s32, s32);
extern CLOCK_187998 g_2dded0;
extern HELPER_187998 D_002DDF40;
extern char D_002DDEC0[];
extern float D_002DEB30;
extern char D_003DD490[];
extern float g_2ddf0c;
// Sqrt: sqrt.s with an early-clobber output (=&f). Measured on every sqrt.s user (16 sources): none gets worse, six get closer, two reach 0 (a third holds VU0 asm and stays out);
// retail's helper keeps the result out of the operand's register. The one Sqrt helper form (docs/contributing/exceptions.md).
static inline float Sqrt(float x) { float r; asm volatile("sqrt.s %0, %1" : "=&f"(r) : "f"(x)); return r; }
#define F(type, off) (*(type *)(self + (off)))
s32 FReadJoy__FP3JOY(char *self)
{
    u8 buf[0x40];
    s32 res;
    s32 old;
    float prevX, prevY, prevX2, prevY2;

    res = 1;
    memset(buf, 0, 0x40);
    if (scePadRead(F(s32, 0x1000), F(s32, 0x1004), buf) > 0) {
        old = F(s32, 0x10B4);
        s32 cur = ((buf[2] << 8) | buf[3]) ^ 0xFFFF;
        s32 held = F(s32, 0x10BC);
        F(s32, 0x10B8) = cur & ~old & ~held;
        F(s32, 0x10BC) = held & cur;
        F(s32, 0x10B4) = cur;
        if (F(s32, 0x1008) != 0) {
            if (F(s32, 0x1008) != buf[1]) res = 0;
        }
        F(s32, 0x1008) = buf[1];
        if (F(s32, 0x1010) == 4)
            CopyAb__FPvT0Ui(self + 0x10C0, buf + 8, 0xC);
        prevX = F(float, 0x103C);
        prevY = F(float, 0x1040);
        prevX2 = F(float, 0x1070);
        prevY2 = F(float, 0x1074);
        if (F(s32, 0x1010) >= 2) {
            GetJoyXYDeflection__FP3JOYUcUcPfN23PUcT6PiP2LM(self, buf[6], buf[7], &F(float, 0x103C), &F(float, 0x1040), &F(float, 0x1044), &F(u8, 0x1048), &F(u8, 0x1049), &F(s32, 0x104C), &F(s32, 0x1050));
            GetJoyXYDeflection__FP3JOYUcUcPfN23PUcT6PiP2LM(self, buf[4], buf[5], &F(float, 0x1070), &F(float, 0x1074), &F(float, 0x1078), &F(u8, 0x107C), &F(u8, 0x107D), &F(s32, 0x1080), &F(s32, 0x1084));
        } else {
            float zero = 0.0f;
            F(float, 0x1044) = zero;
            F(float, 0x1040) = zero;
            F(float, 0x103C) = zero;
            F(float, 0x1078) = zero;
            F(float, 0x1074) = zero;
            F(float, 0x1070) = zero;
        }
        if (D_002DDF40.f30C == 0 || D_002DDF40.f314 != (char *)&D_002DDF40 + 0x3A0) {
            if ((F(s32, 0x10B4) & 0xF000) != 0) {
                float zero = 0.0f;
                F(float, 0x1044) = zero;
                F(float, 0x1040) = zero;
                F(float, 0x103C) = zero;
                if ((F(s32, 0x10B4) & 0x8000) != 0) {
                    F(float, 0x103C) = -F(float, 0x10EC);
                } else if ((F(s32, 0x10B4) & 0x2000) != 0) {
                    F(float, 0x103C) = F(float, 0x10EC);
                }
                if ((F(s32, 0x10B4) & 0x1000) != 0) {
                    F(float, 0x1040) = F(float, 0x10EC);
                } else if ((F(s32, 0x10B4) & 0x4000) != 0) {
                    F(float, 0x1040) = -F(float, 0x10EC);
                }
                if (F(float, 0x103C) * F(float, 0x1040) != 0.0f) {
                    F(float, 0x103C) = F(float, 0x103C) * Sqrt(0.5f);
                    F(float, 0x1040) = F(float, 0x1040) * Sqrt(0.5f);
                }
                F(float, 0x1044) = 1.0f;
            }
        }
        F(float, 0x10A4) = (F(float, 0x103C) - prevX) / g_2dded0.f40;
        F(float, 0x10A8) = (F(float, 0x1040) - prevY) / g_2dded0.f40;
        F(float, 0x10AC) = (F(float, 0x1070) - prevX2) / g_2dded0.f40;
        F(float, 0x10B0) = (F(float, 0x1074) - prevY2) / g_2dded0.f40;
        _MatchCodes__FP3JOYUs(D_002DDEC0, self, old & 0xFFFF);
        F(float, 0x1018) = g_2dded0.f3C;
        if (F(s32, 0x10B4) != 0 || F(float, 0x1044) != 0.0f || F(float, 0x1078) != 0.0f) {
            F(float, 0x101C) = g_2dded0.f3C;
            F(s32, 0x1020) = 0;
            if (g_2dded0.f3C - D_002DEB30 > 15.0f) {
                bevy_camera_follow_activity(&D_002DEB30, 0xE, PpoSwFocusBase(D_003DD490));
                D_002DEB30 = g_2dded0.f3C;
            }
        } else {
            F(s32, 0x1020) = (s32)(g_2dded0.f3C - F(float, 0x101C));
        }
    } else {
        if (g_2ddf0c - F(float, 0x1018) >= 2.0f) res = 0;
    }
    return res;
}
}
