extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D2938;
extern "C" char D_002D2978;
struct Obj110EC0 {
    int a;
    int b;
    int c;
    char *vt;
    char pad[272];
    char *vt2;
    char pad2[28];
    Obj110EC0 *init()
    {
        vt = &D_002D2978;
        vt2 = &D_002D2938;
        a = 0;
        b = 0;
        return this;
    }
};
void *func_00110EC0(void)
{
    Obj110EC0 *object = (Obj110EC0 *)__builtin_new(0x140);
    return object->init();
}
