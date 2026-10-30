struct Guard_208B38 { char pad[0x3C0]; int count; int classes[1]; };
extern "C" {
int FIsBasicDerivedFrom(int, int);
int func_00208B38(Guard_208B38 *self, int cls) {
    int i;
    for (i = 0; i < self->count; i++) {
        if (FIsBasicDerivedFrom(cls, self->classes[i]) != 0) return 1;
    }
    return 0;
}
}
