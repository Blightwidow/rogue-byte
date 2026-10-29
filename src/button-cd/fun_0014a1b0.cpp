extern "C" {
void AddGuardSgs(int, int);
void func_001EEF68();
int func_001FEE90(void *);
extern char B_003DD040;
}
struct Obj { int a0, a1, a2, a3; int guard; int p14, p18, p1c, p20, p24, p28, p2c; int f30; int p34, p38; int f3c; int f40; };
extern "C" void func_0014A1B0(Obj *self) {
    func_001EEF68();
    func_001FEE90(&B_003DD040);
    AddGuardSgs(self->guard, 0x24);
    self->f30 = -1;
    self->f40 = -1;
    self->f3c = -1;
}
