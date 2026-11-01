extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D9D90;
extern "C" char D_002D9DD0;
struct Obj111380 {
    int a;
    int b;
    int c;
    char *vt;
    char pad[240];
    char *vt2;
    char pad2[12];
    Obj111380 *init()
    {
        vt = &D_002D9DD0;
        vt2 = &D_002D9D90;
        a = 0;
        b = 0;
        return this;
    }
};
void *func_00111380(void)
{
    Obj111380 *object = (Obj111380 *)__builtin_new(0x110);
    object->init();
}
