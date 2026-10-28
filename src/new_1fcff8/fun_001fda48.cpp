#include "sly2.h"
struct SWX { char pad[1]; };
struct SND { char pad0[0x10]; int on; char pad1[0x58]; int pending; float answer; char pad2[0xC]; float g[3]; char pad3[4]; float f[3]; };
struct CM { char pad[0x54]; float a; float b; float c; };
extern SWX B_003DD490;
extern "C" {
void func_001FCF70(void);
void func_002330D0(int, int, int, int, int, int, int, void *, long);
void *PpoSwFocusBase(void *);
int FIsBasicDerivedFrom(void *, int);
QW PosLoWorld(void *);
void ReplaceHitFx(void *, QW, void *, void *);
void func_001FDA48(SND *snd)
{
    if (snd->on == 0) {
        snd->answer = 0.0f;
    } else if (snd->pending == 0) {
        snd->pending = 1;
        func_002330D0(0x524B5553, 0xB, 0, 0, 0, 0, 0, (void *)func_001FCF70, (long)snd);
    }
    CM *cm = 0;
    QW pos;
    void *focus = PpoSwFocusBase(&B_003DD490);
    if (focus) {
        if (FIsBasicDerivedFrom(focus, 0x34)) {
            float half;
            asm("lui $1, 0x3F00\n\tmtc1 $1, %0\n\tnop" : "=f" (half) : : "$1");
            if (half < snd->answer) {
                cm = *(CM **)((char *)&B_003DD490 + 0x4034);
                pos = PosLoWorld(focus);
                float *gc = &snd->g[0];
                float *fc = &snd->f[0];
                cm->a = gc[0] + snd->answer * (gc[1] + snd->answer * gc[2]);
                float far = fc[0] + snd->answer * (fc[1] + snd->answer * fc[2]);
                cm->c = far;
                cm->b = -far;
            }
        }
    }
    ReplaceHitFx(cm, pos, focus, (char *)snd + 0x74);
}
}
