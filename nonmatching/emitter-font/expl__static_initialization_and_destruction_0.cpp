typedef int QW __attribute__((mode(TI)));
struct SA { char b[0x40]; } __attribute__((aligned(16)));
struct SB { char b[0x70]; } __attribute__((aligned(16)));
extern "C" {
extern SA g_2de5b0;
extern SB B_002DE5F0;
extern char g_2a2dd0[16];
extern char g_2a2da0[16];
extern char g_2a2dc0[16];
extern int B_002DD2E0, B_002DD2E4, B_002DD2E8, B_002DD2EC, B_002DD2F0, B_002DD2F4;
extern char B_004520A8[], B_004520D0[], B_004520F8[], B_00452120[], B_00452148[], B_00452170[];
void CreateSlotheapSwAlign(void *, int, int, int);
void *memset(void *, int, unsigned int);
}
extern "C" void expl__static_initialization_and_destruction_0(int fInit, int priority)
{
    if (priority == 0xFFFF && fInit != 0) {
        SA *pa = &g_2de5b0;
        SA a;
        memset(&a, 0, 0x40);
        *(int *)(a.b + 0x10) = -1;
        *(QW *)(a.b + 0x20) = *(QW *)g_2a2dd0;
        *(QW *)(a.b + 0x30) = *(QW *)g_2a2da0;
        *pa = a;
        SB *pb = &B_002DE5F0;
        SB b;
        memset(&b, 0, 0x70);
        *(float *)(b.b + 0x00) = 750.0f;
        *(float *)(b.b + 0x38) = 1.0f;
        *(float *)(b.b + 0x3C) = 1.0f;
        *(float *)(b.b + 0x04) = 750.0f;
        *(float *)(b.b + 0x0C) = 1.0f;
        *(QW *)(b.b + 0x20) = *(QW *)g_2a2dc0;
        *(float *)(b.b + 0x60) = 1.0f;
        *(float *)(b.b + 0x68) = -1.0f;
        *(float *)(b.b + 0x18) = -1500.0f;
        *(int *)(b.b + 0x34) = 200;
        *(float *)(b.b + 0x08) = -1.0f;
        *pb = b;
        if (++B_002DD2E0 == 1) CreateSlotheapSwAlign(B_004520A8, 0x14, 0x2000, 0x10);
        if (++B_002DD2E4 == 1) CreateSlotheapSwAlign(B_004520D0, 0x18, 0x800, 0x10);
        if (++B_002DD2E8 == 1) CreateSlotheapSwAlign(B_004520F8, 0x28, 0x200, 0x10);
        if (++B_002DD2EC == 1) CreateSlotheapSwAlign(B_00452120, 0x1C, 0x800, 0x10);
        if (++B_002DD2F0 == 1) CreateSlotheapSwAlign(B_00452148, 0xC, 0xC8, 0x10);
        if (++B_002DD2F4 == 1) CreateSlotheapSwAlign(B_00452170, 0x14, 0x100, 0x10);
    }
}
