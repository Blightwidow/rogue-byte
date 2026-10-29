extern "C" {
int FStreamPlaying(char *arg0, int arg1)
{
    char *temp_v0;
    char *temp_v1;
    int var_a0;

    temp_v0 = *(char **)(arg0 + 0x200);
    if (temp_v0 != 0) {
        temp_v1 = *(char **)(temp_v0 + 0x60);
        var_a0 = 0;
        if (arg1 == -1 || *(int *)(temp_v1 + 0x40) == arg1) {
            var_a0 = 1;
        }
        return var_a0;
    }
    return 0;
}
}
