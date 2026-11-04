typedef unsigned long u64;
extern "C" u64 GrfsgsFromSgs(int);
extern "C" int PpoSwFocusBase(char *);
extern "C" void func_001F17F8(char *, int);
extern "C" char B_003DD490;
extern "C" int g_2e1e40;

void func_001F1900(char *self)
{
    char *block = *(char **)(self + 0x494);
    if (block == 0)
        return;
    int mode;
    if (*(int *)(block + 0x158) == 0) {
        mode = -1;
    } else {
        u64 maskFirst = GrfsgsFromSgs(0x1D);
        u64 maskSecond = GrfsgsFromSgs(0x20);
        u64 maskThird = GrfsgsFromSgs(5);
        u64 maskFourth = GrfsgsFromSgs(6);
        u64 maskFifth = GrfsgsFromSgs(7);
        u64 maskSixth = GrfsgsFromSgs(0x17);
        u64 maskSeventh = GrfsgsFromSgs(0x16);
        u64 combined = maskFirst | maskSecond | maskThird | maskFourth | maskFifth | maskSixth | maskSeventh;
        int count = *(int *)(self + 0x484);
        if ((*(u64 *)(self + 0x2C0) & combined) != 0)
            mode = 0;
        else if (count == 0 || *(int *)(self + ((count - 1) << 4) + 0x404) == 0x2B3)
            mode = 1;
        else if (PpoSwFocusBase(&B_003DD490) == 0)
            mode = 1;
        else
            mode = (PpoSwFocusBase(&B_003DD490) == g_2e1e40) ? 2 : 1;
    }
    func_001F17F8(self, mode);
}
