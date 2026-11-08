typedef struct SlotEntry {
    int fourth;
    int fifth;
    int sixth;
    int seventh;
    int first;
    int second;
    int third;
} SlotEntry;
extern char B_00450580[];
extern SlotEntry B_004505D0[];
extern int B_004507C0[];
extern int func_00239450(void);
extern void func_002394A0(void);
extern void func_0023ADA8(int, void (*)(void), int);
extern void func_00242E48(void);
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, int, int);
int func_00242E90(void)
{
    int index;
    int state;
    for (index = 0; index < 4; index++) {
        B_004505D0[index].first = 0;
        B_004505D0[index].third = 0;
        B_004505D0[index].second = 0;
        B_004505D0[index + 4].first = 0;
        B_004505D0[index + 4].third = 0;
        B_004505D0[index + 4].second = 0;
    }
    B_004507C0[0] = 0x10;
    B_004507C0[4] = 0;
    if (sceSifCallRpc(B_00450580, 1, 0, B_004507C0, 0x80, B_004507C0, 0x80, 0, 0) < 0)
        return 0;
    state = func_00239450();
    func_0023ADA8(0x80000019, func_00242E48, 0);
    if (state == 1)
        func_002394A0();
    return B_004507C0[3];
}
