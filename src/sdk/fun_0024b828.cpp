struct Pic { char pad28[0x28]; int fDone; };
struct Mpeg {
    char pad0[0x130];
    int fOdd;
    char pad134[0x184 - 0x134];
    int structure;
    char pad188[0x1D0 - 0x188];
    Pic *pTop;
    char pad1D4[0x1E0 - 0x1D4];
    Pic *pField1;
    char pad1E4[0x1F0 - 0x1E4];
    Pic *pField2;
};
extern "C" {
extern char RO_002AC3D8[];
extern char RO_002AC3F8[];
void func_0024FA38(Mpeg *, char *);
int func_00250C58(Mpeg *);
}

int func_0024B828(Mpeg *pmpeg)
{
    Pic *ppic;
    if (pmpeg->structure == 3) {
        if (pmpeg->fOdd != 0) {
            func_0024FA38(pmpeg, RO_002AC3D8);
            pmpeg->fOdd = 0;
        }
    }
    switch (pmpeg->structure) {
    case 3:
        ppic = pmpeg->pTop;
        break;
    case 1:
        ppic = pmpeg->pField1;
        break;
    case 2:
        ppic = pmpeg->pField2;
        break;
    default:
        ppic = pmpeg->pTop;
        func_0024FA38(pmpeg, RO_002AC3F8);
        break;
    }
    int result = func_00250C58(pmpeg);
    if (result != 0) {
        ppic->fDone = 1;
    }
    return result;
}
