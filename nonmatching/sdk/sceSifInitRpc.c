/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef struct RpcServerState {
    int field00;
    unsigned int field04;
    int field08;
    int field0C;
    int field10;
    unsigned int field14;
    int field18;
    unsigned int field1C;
    int field20;
    int field24;
} RpcServerState;

extern void func_00239450(void);
extern void func_002394A0(void);
extern void func_0023AAF0(void);
extern int func_0023ADA8(unsigned int commandId, void* handler, void* argument);
extern int func_0023AFA8(unsigned int commandId, void* packet, int size, int extra, int extraSize, int extraAddress);
extern int func_0023AAC8(int channel);
extern int sceSifGetReg(unsigned int index);
extern void sceSifSetReg(unsigned int index, int value);
extern void func_00236D60(void);
extern void func_00236E70(void);
extern void func_00236FD8(void);
extern void func_002371F8(void);
extern int D_002C49F0;
extern char B_00448E00[];
extern char B_00449600[];
extern char B_00449E00[];
extern RpcServerState B_0044A600;

void sceSifInitRpc(void) {
    func_00239450();
    if (D_002C49F0 != 0) {
        func_002394A0();
        return;
    }
    D_002C49F0 = 1;
    func_002394A0();
    func_0023AAF0();
    func_00239450();
    B_0044A600.field00 = 1;
    B_0044A600.field04 = (unsigned int)B_00448E00 | 0x20000000;
    B_0044A600.field08 = 0x20;
    B_0044A600.field0C = 0;
    B_0044A600.field10 = 0;
    B_0044A600.field14 = (unsigned int)B_00449600 | 0x20000000;
    B_0044A600.field18 = 0x20;
    B_0044A600.field1C = (unsigned int)B_00449E00 | 0x20000000;
    B_0044A600.field20 = 0x20;
    B_0044A600.field24 = 0;
    func_0023ADA8(0x80000008, func_00236D60, &B_0044A600);
    func_0023ADA8(0x80000009, func_00236FD8, &B_0044A600);
    func_0023ADA8(0x8000000A, func_002371F8, &B_0044A600);
    func_0023ADA8(0x8000000C, func_00236E70, &B_0044A600);
    func_002394A0();
    if (sceSifGetReg(0x80000002) != 0) {
        return;
    }
    *(int*)(B_00448E00 + 0x4C) = 1;
    func_0023AFA8(0x80000002, B_00448E00 + 0x40, 0x10, 0, 0, 0);
    while (func_0023AAC8(0) == 0) {
    }
    sceSifSetReg(0x80000002, 1);
}
