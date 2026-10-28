extern "C" void Vector_Init(void *, void *);
extern "C" void func_00256528(void *, void *, void *);
extern "C" char func_00119BC0[];
void func_00119BD0(void *self, void *owner)
{
    Vector_Init(self, owner);
    func_00256528((char *)self + 0x34, self, func_00119BC0 + 8);
}
