#include "sly2.h"
struct CM { char pad0[0x40]; float xRange; float yRange; char pad48[4]; float nearLimit; };
struct LM;
struct UNA { int v; } __attribute__((packed));
struct LOCALS {
    char text[0xA0];
    float x; float y; float w; float h;
    int b0; int pad14[3]; int c0; int pad24[3];
    float extW; float extH;
};
static inline float Lane0(QW v) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (v)); return f; }
static inline float Lane1(QW v) { float f; QW t; asm("prot3w %1, %2\n\tmtc1 %1, %0" : "=f" (f), "=&r" (t) : "r" (v)); return f; }
static inline float Lane2(QW v) { float f; QW t; asm("pextuw %1, $0, %2\n\tmtc1 %1, %0" : "=f" (f), "=&r" (t) : "r" (v)); return f; }
extern "C" {
QW ConvertCmWorldToScreen(CM *, QW);
float GLimitLm__FP2LMf(LM *, float);
void func_00215AC0(void *, int, float);
void CTextBox_SetPos(void *, float, float);
void CTextBox_SetSize(void *, float, float);
void CTextBox_SetTextColor(void *, void *);
void CTextBox_SetHorizontalJust(void *, int);
void CTextBox_SetVerticalJust(void *, int);
void CMovieText_GetExtents(void *, float *, float *);
void CMovieText_Draw(void *, void *, int, int);
extern CM B_002DDF40;
static inline void BoxSetSize(void *box, float w, float h) { CTextBox_SetSize(box, w, h); }
extern char D_002C1F28[];
extern float D_002C1F20;
extern int D_002C1F30;
extern int D_002C1F34;
void bevy_camera_cm_screen_px_ps2(QW world, int arg1, int arg2, void *arg3, float scale)
{
    LOCALS l;
    QW screen = ConvertCmWorldToScreen(&B_002DDF40, world);
    float depth = Lane2(screen);
    if (depth < B_002DDF40.nearLimit)
        return;
    {
        int color = 0xFF808080;
        func_00215AC0(l.text, arg1, GLimitLm__FP2LMf((LM *)D_002C1F28, scale * (D_002C1F20 / (B_002DDF40.xRange * depth))));
        CTextBox_SetPos(&l.x, 0.0f, 0.0f);
        BoxSetSize(&l.x, 640.0f, 492.80002f);
        l.c0 = color;
        CTextBox_SetTextColor(&l.x, &l.c0);
        CTextBox_SetHorizontalJust(&l.x, 0);
        CTextBox_SetVerticalJust(&l.x, 0);
        CMovieText_GetExtents(l.text, &l.extW, &l.extH);
        float padY2 = (float)(D_002C1F34 * 2);
        float padX = (float)D_002C1F30;
        l.w = l.extW + (float)(D_002C1F30 * 2);
        l.h = l.extH + padY2;
        l.x = (((Lane0(screen) * 0.5f + 0.5f) * 640.0f - l.extW * 0.5f) - padX) + padX;
        l.y = (((0.5f - Lane1(screen) * 0.5f) * 492.80002f - l.extH) - padY2) + (float)D_002C1F34;
        int argColor = ((UNA *)arg3)->v;
        ((UNA *)&l.c0)->v = argColor;
        int value = ((UNA *)&l.c0)->v;
        ((UNA *)&l.b0)->v = value;
        CMovieText_Draw(l.text, &l.x, 6, value);
    }
}
}
