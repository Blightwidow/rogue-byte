typedef int s32;
typedef unsigned int u32;
struct UnalignedWord { s32 value __attribute__((packed)); };
extern "C" {
struct SifClient { char pad0[0x24]; int serverReady; };
struct ClientWord { int first; int second; };
struct RingEntry { int first; int second; int third; int fourth; };
struct TwoPointers { char *first; char *second; };
void sceSifInitRpc(int mode);
int func_00239450();
void func_0023ADA8(u32 id, void *function, void *argument);
void func_00237740();
void func_00237B90();
void func_002394A0();
int sceSifBindRpc(SifClient *client, u32 serverId, int mode);
void func_002374E0();
int WaitSema(int id);
int SignalSema(int id);
int func_002375E0(SifClient *client, int a1, int a2, TwoPointers *a3, int a4, char *a5, int a6, int a7, int a8, int a9);
extern ClientWord B_0044BE00;
extern char B_0044BDC0[];
extern SifClient B_0044BD80;
extern RingEntry B_0044BB80[0x20];
extern char B_0044B300[];
extern char B_0044B2C0[];
extern TwoPointers B_0044A640;
extern UnalignedWord B_0044BDA8;
extern int D_002C4A88;
extern int D_002C4A7C;
extern int D_002C4A80;
int func_00237BD8() {
    ClientWord *words = &B_0044BE00;
    SifClient *client;
    int count;
    RingEntry *entry;
    int hasModule;
    sceSifInitRpc(0);
    words->second = 0;
    B_0044BE00.first = 0;
    hasModule = func_00239450();
    func_0023ADA8(0x80000011, (void *)func_00237740, B_0044BDC0);
    func_0023ADA8(0x80000013, (void *)func_00237B90, words);
    if (hasModule != 0) {
        func_002394A0();
    }
    for (;;) {
        client = &B_0044BD80;
        if (sceSifBindRpc(client, 0x80000001, 0) < 0) {
            return -0x16;
        }
        if (client->serverReady != 0) {
            break;
        }
        for (count = 0x100000; count != -1; count--) {
        }
    }
    func_002374E0();
    WaitSema(D_002C4A88);
    for (entry = B_0044BB80; entry < B_0044BB80 + 0x20; entry++) {
        entry->second = 0;
    }
    SignalSema(D_002C4A88);
    B_0044A640.first = B_0044B300;
    B_0044A640.second = B_0044B300 + 0x440;
    if (func_002375E0(&B_0044BD80, 0xFF, 0, &B_0044A640, 8, B_0044B2C0, 8, 0, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    B_0044BDA8 = *(UnalignedWord *)((u32)B_0044B2C0 | 0x20000000);
    UnalignedWord word = *(UnalignedWord *)(((u32)B_0044B2C0 + 4) | 0x20000000);
    D_002C4A80 = word.value == 2;
    D_002C4A7C = 1;
    return 0;
}
}
