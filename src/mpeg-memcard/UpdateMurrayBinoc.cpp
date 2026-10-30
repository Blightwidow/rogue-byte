extern "C" int FButtonPressedWithin(int, int, float);
extern "C" int StopBinoc(char *);
extern "C" void UpdateBinoc(char *);
extern "C" int bevy_player_p15_binoc_active();

extern "C" void UpdateMurrayBinoc(char *obj) {
    if (bevy_player_p15_binoc_active() != 0) {
        char *binoc = obj + 0xF00;
        if (*(int *)(obj + 0xF04) == 1 && *(int *)(obj + 0xF20) == 0 &&
            FButtonPressedWithin(*(int *)(obj + 0x150), 0x4F0, 0.25f) != 0) {
            StopBinoc(binoc);
        }
        UpdateBinoc(binoc);
    }
}
