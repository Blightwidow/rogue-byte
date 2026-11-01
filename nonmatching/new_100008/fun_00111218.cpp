extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D2518;
extern "C" char D_002D2558;
struct Obj111218 {
    int a;
    int b;
    int c;
    char *vt;
    char pad[240];
    char *vt2;
    char pad2[12];
    Obj111218 *init()
    {
        vt = &D_002D2558;
        vt2 = &D_002D2518;
        a = 0;
        b = 0;
        return this;
    }
};
void *func_00111218(void)
{
    Obj111218 *object = (Obj111218 *)__builtin_new(0x110);
    return object->init();
}
