struct Slot_201998 { char pad[0x4C]; int mode; };
extern "C" {
void func_002417F0(int, int, int);
extern Slot_201998 B_003DD2C0[];
extern int g_2c3c5c;
extern int g_2de5a0;
void func_00201998(void)
{
    func_002417F0(g_2de5a0, 0, 0);
    int index = 1 - g_2c3c5c;
    g_2c3c5c = index;
    B_003DD2C0[index].mode = 2;
}
}
