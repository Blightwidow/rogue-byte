extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D1B20;
extern "C" char D_002D1B60;
struct Obj111090 {
    int a;
    int b;
    int c;
    char *vt;
    char pad[320];
    char *vt2;
    char pad2[12];
    Obj111090 *init()
    {
        vt = &D_002D1B60;
        vt2 = &D_002D1B20;
        a = 0;
        b = 0;
        return this;
    }
};
void *func_00111090(void)
{
    Obj111090 *object = (Obj111090 *)__builtin_new(0x160);
    return object->init();
}
