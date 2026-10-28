extern "C" void Sw_Construct(void *);
extern "C" void BASIC_Destruct(void *, int);
extern "C" void CreateSlotheapSwAlign(void *, int, int, int);
extern char B_003DD490[];
struct STR { int a; char *b; int c; char *d; };
extern STR B_003E1C20;
extern char B_003E1C60[];
extern char D_002C3EB8[];
extern int B_002DD2E0, B_002DD2E4, B_002DD2E8, B_002DD2EC, B_002DD2F0, B_002DD2F4;
extern char B_004520A8[], B_004520D0[], B_004520F8[], B_00452120[], B_00452148[], B_00452170[];

void StaticInitSw(int init, int prio)
{
    if (prio == 0xFFFF) {
        if (init) {
            Sw_Construct(B_003DD490);
            char *e = D_002C3EB8;
            char *f = B_003E1C60;
            B_003E1C20.a = 0;
            int n = B_002DD2E0 + 1;
            B_003E1C20.d = f;
            B_003E1C20.b = e;
            B_002DD2E0 = n;
            B_003E1C20.c = 0;
            if (n == 1) CreateSlotheapSwAlign(B_004520A8, 0x14, 0x2000, 0x10);
            if (++B_002DD2E4 == 1) CreateSlotheapSwAlign(B_004520D0, 0x18, 0x800, 0x10);
            if (++B_002DD2E8 == 1) CreateSlotheapSwAlign(B_004520F8, 0x28, 0x200, 0x10);
            if (++B_002DD2EC == 1) CreateSlotheapSwAlign(B_00452120, 0x1C, 0x800, 0x10);
            if (++B_002DD2F0 == 1) CreateSlotheapSwAlign(B_00452148, 0xC, 0xC8, 0x10);
            if (++B_002DD2F4 == 1) CreateSlotheapSwAlign(B_00452170, 0x14, 0x100, 0x10);
        } else {
            BASIC_Destruct(B_003DD490, 2);
        }
    }
}
