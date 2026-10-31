extern "C" {
int func_001EEFC0(char *);
int func_001EF038(char *);
extern float g_2dded0;
void func_00146E18(char *self, int state) {
    int old = *(int *)(self + 0x30);
    if (state != old) {
        if (old < 5) {
            if (old >= 2) {
                func_001EF038(self);
            }
        }
        *(int *)(self + 0x30) = state;
        *(float *)(self + 0x34) = g_2dded0;
        if (state < 5) {
            if (state >= 2) {
                func_001EEFC0(self);
            }
        }
    }
}
}
