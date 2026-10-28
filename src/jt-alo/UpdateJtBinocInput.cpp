extern "C" int bevy_player_p15_binoc_active();
extern "C" int FButtonPressedWithin(void*, int, float);
extern "C" void StopBinoc(void*);
extern "C" void UpdateBinoc(void*);
struct Jt { char pad0[0x150]; void* joy; char pad1[0xF00 - 0x154]; char binoc[4]; int state; char pad2[0xF20 - 0xF08]; int phase; char pad3[0x1D40 - 0xF24]; int mode; };
extern "C" void UpdateJtBinocInput(Jt* jt)
{
    if (bevy_player_p15_binoc_active()) {
        void* binoc = jt->binoc;
        if (jt->state == 1 && jt->phase == 0) {
            int buttons = (jt->mode == 7) ? 0x410 : 0x4F0;
            if (FButtonPressedWithin(jt->joy, buttons, 0.25f)) StopBinoc(binoc);
        }
        UpdateBinoc(binoc);
    }
}
