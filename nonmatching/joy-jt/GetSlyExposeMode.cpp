struct Sly_189488 { char pad[0x18C8]; int state; };
extern "C" {
int func_001409B8();
int GetSlyExposeMode(Sly_189488 *self) {
    int mode = func_001409B8();
    if (mode == -1) {
        int state = self->state;
        if (state < 7) {
            if (state < 5 && state != 1)
                return -1;
            goto one;
        }
        if (state == 9) {
one:
            return 1;
        }
        return -1;
    }
    return mode;
}
}
