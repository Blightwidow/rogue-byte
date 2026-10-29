extern "C" void InitJt(void *);
extern "C" void func_0020B840(void *, void *, int);
extern "C" void *g_2dd5bc;
#define I(off) (*(int *)((char *)p + (off)))
#define F(off) (*(float *)((char *)p + (off)))
extern "C" void InitBentley(void *p)
{
    InitJt(p);
    // BEGIN
    I(0x1040) = 0;
    I(0x1800) = -1;
    F(0x1048) = 125.0f;
    F(0x103C) = 45.0f;
    I(0x16B0) = -1;
    I(0x16BC) = -1;
    I(0x13D0) = -1;
    func_0020B840((char *)p + 0x1320, p, 0x73);
    func_0020B840((char *)p + 0x1600, p, 0x73);
    F(0x3D8) = -70.0f;
    F(0x1098) = -100.0f;
    F(0x109C) = 100.0f;
    F(0x10A0) = 50.0f;
    F(0x10A4) = -10.0f;
    F(0x10A8) = 250.0f;
    char *q = (char *)p + 0x10A8;
    *(float *)(q + 8) = 1.0f;
    *(int *)(q + 4) = 0;
    *(float *)(q + 0xC) = 4500.0f;
    I(0x1000) = 2;
    I(0x1830) = 7;
    I(0x183C) = 9;
    I(0x1848) = 0xB;
    I(0x1854) = 0xD;
    I(0x1860) = 4;
    I(0x1824) = 5;
    I(0x1870) = 5;
    // END
    g_2dd5bc = p;
}
