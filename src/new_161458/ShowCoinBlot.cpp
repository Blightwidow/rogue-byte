struct Vt_161868 { char pad[0x188]; short delta; short pad2; void (*fn)(char *, int); };
struct Target_161868 { char pad[0xC]; Vt_161868 *vt; };
extern "C" {
void func_00212A30(Target_161868 *);
void ShowCoinBlot(char *arg0) {
    Target_161868 *target = *(Target_161868 **)(arg0 + 0x3BAC);
    if (target != 0) {
        target->vt->fn((char *)target + target->vt->delta, -1);
        func_00212A30(target);
    }
}
}
