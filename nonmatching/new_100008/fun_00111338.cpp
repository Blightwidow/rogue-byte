extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D2338;
extern "C" char D_002D2378;
struct Obj111338 {
    int a;
    int b;
    int c;
    char *vt;
    char pad[240];
    char *vt2;
    char pad2[12];
    Obj111338 *init()
    {
        vt = &D_002D2378;
        vt2 = &D_002D2338;
        a = 0;
        b = 0;
        return this;
    }
};
void *func_00111338(void)
{
    Obj111338 *object = (Obj111338 *)__builtin_new(0x110);
    object->init();
}
