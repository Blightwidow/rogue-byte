extern "C" void *__builtin_new(unsigned int);
extern "C" char D_002D1EA8;
extern "C" char D_002D1D00;
struct Obj1112A8 {
    int a;
    int b;
    int c;
    char *vt;
    char pad[240];
    char *vt2;
    char pad2[156];
    Obj1112A8 *init()
    {
        vt = &D_002D1D00;
        vt2 = &D_002D1EA8;
        a = 0;
        b = 0;
        return this;
    }
};
void *func_001112A8(void)
{
    Obj1112A8 *object = (Obj1112A8 *)__builtin_new(0x1a0);
    object->init();
}
