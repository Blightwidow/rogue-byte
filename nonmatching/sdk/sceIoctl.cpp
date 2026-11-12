extern "C" {
struct Slot { int field0; int state; int field8; int fieldC; };
struct SemaParam { int attr; int initCount; int maxCount; int field0C; int field10; const char *name; };
struct IoctlPacket {
    int semaphore;
    void *result;
    int resultSize;
    int field0C;
    int command;
    char data[0x400];
    int field414;
    int field418;
    int dataSize;
};
struct Mem { char bytes[0x440]; };
Slot *func_002376D0(unsigned int);
void func_00237B50(int);
void func_00237BD8(void);
void func_00237B80(void);
int CreateSema(SemaParam *);
int DeleteSema(int);
int WaitSema(int);
int SignalSema(int);
void func_0023B170(void *, int);
unsigned int func_002375E0(void *, int, int, void *, int, void *, int, int, int, int);
void *memcpy(void *, const void *, unsigned);
extern IoctlPacket B_0044A680;
extern int *B_0044A648;
extern unsigned int D_002C4A7C;
extern int D_002C4A8C;
extern unsigned int D_002C4A78;
extern int D_002C49F8[32];
extern Mem B_0044B310[];
extern char B_0044B2C0[];
extern char B_0044BD80[];
extern const char RO_002AAB28[];

int sceIoctl(int handle, int command, void *argument) {
    IoctlPacket *packet = &B_0044A680;
    Slot *slot = func_002376D0(handle);
    func_00237B50(5);
    B_0044A648 = (int *)argument;
    if (D_002C4A7C == 0) {
        func_00237BD8();
    }
    if (slot == 0 || slot->state == 0) {
        func_00237B80();
        return -9;
    }
    packet->field414 = 0;
    packet->field418 = 0;
    switch (command) {
    case 2:
        *(int *)argument = *(int *)((unsigned int)&B_0044B310[D_002C4A78] | 0x20000000);
        func_00237B80();
        return 0;
    case 1: {
        int index;
        WaitSema(D_002C4A8C);
        for (index = 0; index < 0x20; index++) {
            if (D_002C49F8[index] != -1) break;
        }
        if (index == 0x20) {
            *B_0044A648 = 0;
        } else {
            *B_0044A648 = 1;
        }
        SignalSema(D_002C4A8C);
        func_00237B80();
        return 0;
    }
    case 3:
        *(long *)argument = *(long *)((unsigned int)&B_0044B310[D_002C4A78] | 0x20000000);
        func_00237B80();
        return 0;
    }
    {
        int semaphore;
        int result;
        SemaParam param;
        int reply;
        packet->command = command;
        packet->field0C = slot->field0;
        if (argument == 0) {
            packet->dataSize = 0;
            argument = &reply;
        } else {
            packet->dataSize = 0x400;
            memcpy(packet->data, argument, 0x400);
        }
        param.initCount = 1;
        param.maxCount = 0;
        param.name = RO_002AAB28;
        semaphore = CreateSema(&param);
        packet->result = argument;
        packet->resultSize = 4;
        packet->semaphore = semaphore;
        func_0023B170(packet, 0x420);
        if ((int)func_002375E0(B_0044BD80, 5, 0, packet, 0x420, B_0044B2C0, 4, 0, 0, 0) < 0) {
            DeleteSema(semaphore);
            func_00237B80();
            return -11;
        }
        result = *(int *)((unsigned int)B_0044B2C0 | 0x20000000);
        func_00237B80();
        if (result == 0) {
            DeleteSema(semaphore);
            return -11;
        }
        WaitSema(semaphore);
        DeleteSema(semaphore);
        return reply;
    }
}
}
