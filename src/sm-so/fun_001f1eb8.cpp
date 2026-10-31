typedef int s32;
extern "C" {
struct E_1F1EB8 { s32 v; s32 p[3]; };
struct O_1F1EB8 { char pad[0x404]; E_1F1EB8 e[1]; };
void func_00200F58(s32, s32, s32, s32 *);
s32 func_001F1EB8(s32 arg0, char *arg1) {
    s32 buf[8] __attribute__((aligned(16)));
    s32 n = 0;
    s32 i;
    for (i = *(s32 *)(arg1 + 0x488); i < *(s32 *)(arg1 + 0x484); i++) {
        buf[n] = ((E_1F1EB8 *)(arg1 + 0x404))[i].v;
        n++;
    }
    func_00200F58(arg0, n, 6, buf);
    return arg0;
}
}
