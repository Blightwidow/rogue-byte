extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D56B8;
extern "C" char D_002D56F8;
struct Obj110CD0 {
    int a;
    int b;
    int c;
    char *vt;
    char pad[416];
    char *vt2;
    char pad2[44];
    Obj110CD0 *init()
    {
        vt = &D_002D56F8;
        vt2 = &D_002D56B8;
        a = 0;
        b = 0;
        return this;
    }
};
void *func_00110CD0(void)
{
    Obj110CD0 *object = (Obj110CD0 *)__builtin_new(0x1e0);
    object->init();
}
