extern "C" void *func_001F4C58(char *arg0, int arg1, int arg2) {
    char *var_a0;
    int var_v0;
    int var_v1;
    int temp_a3;

    temp_a3 = *(int *)(arg0 + 0x50);
    var_v1 = 0;
    if (temp_a3 > 0) {
        var_a0 = *(char **)(arg0 + 0x54);
        do {
            var_v1++;
            if (*(int *)(var_a0 + 0x9C) == arg1) {
                if (*(int *)(var_a0 + 0x94) == arg2) {
                    return var_a0;
                }
            }
            var_v0 = var_v1 < temp_a3;
            var_a0 += 0x100;
        } while (var_v0 != 0);
    }
    return 0;
}
