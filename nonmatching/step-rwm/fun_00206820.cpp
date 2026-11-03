struct OBJ { int pad0[3]; virtual void p0(); virtual void p1(); virtual void Call(int, int, int, void *, int); virtual void p3(); virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8(); virtual void p9(); virtual void p10(); virtual void p11(); virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15(); virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19(); virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23(); virtual void p24(); virtual void StopB(int); virtual int StopA(int); };
struct LOC { int zero; int *self; };
extern "C" void func_00206820(OBJ *object)
{
    LOC l;
    l.self = &l.zero;
    l.zero = 0;
    object->StopA(0);
    object->Call(0xF, 0, 1, &l.self, 0);
    object->StopB(0);
    object->Call(0xE, 0, 1, &l.self, 0);
}
