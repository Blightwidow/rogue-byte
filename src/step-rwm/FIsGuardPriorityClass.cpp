struct Guard_2087E8 { char pad[0x394]; int count; int classes[1]; };
extern "C" {
int FIsBasicDerivedFrom(int, int);
int FIsGuardPriorityClass(Guard_2087E8 *self, int cls) {
    int i;
    for (i = 0; i < self->count; i++) {
        if (FIsBasicDerivedFrom(cls, self->classes[i]) != 0) return 1;
    }
    return 0;
}
}
