extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D6FA8;
extern "C" char D_002D6FE8;
struct Obj110D60 {
    int a;
    int b;
    int c;
    char *vt;
    char pad[416];
    char *vt2;
    char pad2[28];
    Obj110D60 *init()
    {
        vt = &D_002D6FE8;
        vt2 = &D_002D6FA8;
        a = 0;
        b = 0;
        return this;
    }
};
void *func_00110D60(void)
{
    Obj110D60 *object = (Obj110D60 *)__builtin_new(0x1d0);
    return object->init();
}
