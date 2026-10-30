typedef unsigned int u32;
extern "C" {
long func_00251FC8(char *);
void func_00252358(char *);
struct Ipu_252230 { int pad0[0x20A]; int field828; int field82C; int pad830[6]; unsigned field848; int field84C; };
unsigned func_00252230(Ipu_252230 *ipu, int count) {
    if (ipu->field828 != 0 || ipu->field84C < count) {
        func_00252358((char *)ipu);
        *(volatile u32 *)0x10002000 = 0x40000000;
        ipu->field828 = 0;
        ipu->field82C = 0x40000000;
        ipu->field848 = (int)func_00251FC8((char *)ipu);
        ipu->field84C = 32;
    }
    return ipu->field848 >> -count;
}
}
