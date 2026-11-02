struct SB { char pad[0x14C]; float volB; float volA; };
struct GSR { char pad0[0x18]; long r18; char pad1[0x20]; long r40; };
extern "C" {
float GLimitLm__FP2LMf(void *, float);
void SetSndbankVolumeFactor(SB *, int, int, float);
void SeekBlotLabel(int, int, float);
int UpdateJoyNavX(int);
int UpdateJoyNavY(int);
int func_0023E1C8(float);
extern GSR D_002DEB80;
extern SB D_003DD040;
extern float D_002F6468;
extern float D_002F646C;
extern float D_002C01C8;
extern float D_002C01CC;
extern char g_2bbb60[];
extern float g_2ddf10;
}
struct PAD { char pad[0x10]; int nav; };
struct PAUSE { char pad[8]; int label; };
void PauseMenu_AdjustOption(PAD *pad, PAUSE *menu, int *pkind)
{
    int kind = *pkind;
    float vol;
    int bank;
    switch (kind) {
    case 0x67: {
        float stick = (float)UpdateJoyNavX(pad->nav);
        if (stick != 0.0f) {
            vol = GLimitLm__FP2LMf(g_2bbb60, D_003DD040.volA + stick * g_2ddf10 * 1.5f);
            bank = 1;
            SetSndbankVolumeFactor(&D_003DD040, bank, 1, vol);
            SeekBlotLabel(menu->label, 0x315, vol);
        }
        break;
    }
    case 0x68: {
        float stick = (float)UpdateJoyNavX(pad->nav);
        if (stick != 0.0f) {
            vol = GLimitLm__FP2LMf(g_2bbb60, D_003DD040.volB + stick * g_2ddf10 * 1.5f);
            SetSndbankVolumeFactor(&D_003DD040, 0, 1, vol);
            SetSndbankVolumeFactor(&D_003DD040, 3, 1, vol);
            SeekBlotLabel(menu->label, 0x315, vol);
        }
        break;
    }
    case 0x3F: {
        float stickX = (float)UpdateJoyNavX(pad->nav);
        float stickY = (float)UpdateJoyNavY(pad->nav);
        if (stickX != 0.0f || stickY != 0.0f) {
            float x = D_002F6468 + stickX * D_002C01C8;
            if (x < 424.0f) x = 424.0f;
            else if (x > 848.0f) x = 848.0f;
            D_002F6468 = x;
            float y = D_002F646C + stickY * D_002C01CC;
            if (y < 10.0f) y = 10.0f;
            else if (y > 90.0f) y = 90.0f;
            D_002F646C = y;
            long lo = func_0023E1C8(D_002F6468) & 0xFFF;
            long a = (D_002DEB80.r40 & ~0xFFFL) | lo;
            long b = (D_002DEB80.r18 & ~0xFFFL) | lo;
            D_002DEB80.r40 = a;
            D_002DEB80.r18 = b;
            long hi = func_0023E1C8(y) & 0x7FE;
            D_002DEB80.r40 = (a & ~0x7FF000L) | (hi << 12);
            D_002DEB80.r18 = (b & ~0x7FF000L) | (hi << 12);
        }
        break;
    }
    }
}
