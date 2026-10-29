extern "C" void bevy_player_p7_damage_1a2160(char *arg0, char *arg1)
{
    int state = *(int *)(arg0 + 0x4);
    if (state == 5) {
        *(int *)(arg1 + 0x34) = 0;
    } else if (state >= 6) {
        if (state < 0xD) {
            if (state >= 8)
                *(int *)(arg1 + 0x34) = 0;
        }
    }
    *(int *)(arg1 + 0) = *(int *)(arg1 + 0) | 1;
}
