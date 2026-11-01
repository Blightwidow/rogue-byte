extern "C" {
void InitCritSect__FP8CRITSECT(void *);
extern int B_002F638C;
extern int B_002F6390;
extern char D_0047220F;
extern int g_2f6380;
extern int g_2f6384;
extern int g_2f6388;
extern int g_2f639c;
void func_001AE168(void) {
    int base = (int)&D_0047220F & ~0xF;
g_2f6380 = g_2f6384 = base;
    g_2f6388 = B_002F638C = 0x02000000;
    g_2f639c = -1;
    InitCritSect__FP8CRITSECT(&B_002F6390);
}
}
