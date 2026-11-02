void *memset(void *, int, unsigned int);
extern "C" {
struct SPRBUF_2019F0 { int word[20]; };
void CreateSlotheapSwAlign(void *, int, int, int);
extern int B_002DD2E0, B_002DD2E4, B_002DD2E8, B_002DD2EC, B_002DD2F0, B_002DD2F4;
extern SPRBUF_2019F0 B_003DD2C0[2];
extern char B_003DD380[], B_003DD400[];
extern char B_004520A8[], B_004520D0[], B_004520F8[], B_00452120[], B_00452148[], B_00452170[];
void sprbuf__static_initialization_and_destruction_0(int arg0, int arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        SPRBUF_2019F0 *slot = B_003DD2C0;
        SPRBUF_2019F0 buffer;
        memset(&buffer, 0, 0x50);
        buffer.word[0] = (int)B_003DD380 | 0x20000000;
        buffer.word[1] = 0x70000000;
        *slot = buffer;
        memset(&buffer, 0, 0x50);
        buffer.word[0] = (int)B_003DD400 | 0x20000000;
        buffer.word[1] = 0x70002000;
        slot++;
        *slot = buffer;
        if (++B_002DD2E0 == 1) CreateSlotheapSwAlign(B_004520A8, 0x14, 0x2000, 0x10);
        if (++B_002DD2E4 == 1) CreateSlotheapSwAlign(B_004520D0, 0x18, 0x800, 0x10);
        if (++B_002DD2E8 == 1) CreateSlotheapSwAlign(B_004520F8, 0x28, 0x200, 0x10);
        if (++B_002DD2EC == 1) CreateSlotheapSwAlign(B_00452120, 0x1C, 0x800, 0x10);
        if (++B_002DD2F0 == 1) CreateSlotheapSwAlign(B_00452148, 0xC, 0xC8, 0x10);
        if (++B_002DD2F4 == 1) CreateSlotheapSwAlign(B_00452170, 0x14, 0x100, 0x10);
    }
}
}
