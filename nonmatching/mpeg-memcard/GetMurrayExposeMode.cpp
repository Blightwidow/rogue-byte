struct Murray_1B8100 { char pad[0x13D0]; int state; char pad2[0x17F4 - 0x13D4]; int flag; };
extern "C" {
int func_001409B8();
int GetMurrayExposeMode(Murray_1B8100 *self) {
    int result; int var_v0;
    int mode = func_001409B8();
    var_v0 = mode;
    if (mode == -1) {
        int state = self->state;
        if (state == 9) {
            var_v0 = self->flag == 0 ? mode : 1;
            return var_v0;
        }
        if (state < 10) {
            if (state != 1) { return -1; }
            goto one;
        }
        var_v0 = -1;
        if (state == 12) {
one:
            var_v0 = 1;
            return var_v0;
        }
        { result = var_v0; goto done; }
    }
    return var_v0;
done:
    return result;
}
}
