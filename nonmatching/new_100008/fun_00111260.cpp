extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D1EA8;
extern "C" char D_002D1EE8;
struct Obj111260 {
    int a;
    int b;
    int c;
    char *vt;
    char pad[240];
    char *vt2;
    char pad2[124];
    Obj111260 *init()
    {
        vt = &D_002D1EE8;
        vt2 = &D_002D1EA8;
        a = 0;
        b = 0;
        return this;
    }
};
void *func_00111260(void)
{
    Obj111260 *object = (Obj111260 *)__builtin_new(0x180);
    return object->init();
}
