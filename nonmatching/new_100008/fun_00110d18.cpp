extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D26F8;
extern "C" char D_002D2738;
struct Obj110D18 {
    int a;
    int b;
    int c;
    char *vt;
    char pad[416];
    char *vt2;
    char pad2[12];
    Obj110D18 *init()
    {
        vt = &D_002D2738;
        vt2 = &D_002D26F8;
        a = 0;
        b = 0;
        return this;
    }
};
void *func_00110D18(void)
{
    Obj110D18 *object = (Obj110D18 *)__builtin_new(0x1c0);
    object->init();
}
