extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D1EA8;
extern "C" char D_002CB9F8;
struct Obj1112F0 {
    int a;
    int b;
    int c;
    char *vt;
    char pad[240];
    char *vt2;
    char pad2[156];
    Obj1112F0 *init()
    {
        vt = &D_002CB9F8;
        vt2 = &D_002D1EA8;
        a = 0;
        b = 0;
        return this;
    }
};
void *func_001112F0(void)
{
    Obj1112F0 *object = (Obj1112F0 *)__builtin_new(0x1a0);
    object->init();
}
