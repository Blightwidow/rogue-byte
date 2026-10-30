struct Guard_2089F0 { char pad[0x3A8]; int count; int classes[1]; };
extern "C" {
int FIsBasicDerivedFrom(int, int);
int func_002089F0(Guard_2089F0 *self, int cls) {
    int i;
    for (i = 0; i < self->count; i++) {
        if (FIsBasicDerivedFrom(cls, self->classes[i]) != 0) return 1;
    }
    return 0;
}
}
