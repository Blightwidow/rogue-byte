// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
typedef char *va_list;
struct SemaParam_237EA8 { int attr; int initCount; int maxCount; int field0C; int field10; const char *name; };
struct OpenRequest_237EA8 { int sema; int *result; int field8; int flags; int mode; char path[0x400]; int index; };
int CreateSema(SemaParam_237EA8 *);
void DeleteSema(int);
void WaitSema(int);
void SignalSema(int);
struct Slot_237EA8 { int field0; int state; int field8; int fieldC; };
int func_002375E0(char *, int, int, OpenRequest_237EA8 *, int, char *, int, int, int, int);
Slot_237EA8 *func_00237558(void);
void func_00237B50(int);
void func_00237B80(void);
void func_00237BD8(void);
int func_00237DE0(void);
extern OpenRequest_237EA8 B_0044A680;
extern char B_0044BB80[];
extern char B_0044B2C0[];
extern char B_0044BD80[];
extern int D_002C4A7C;
extern int D_002C4A88;

int func_00237EA8(const unsigned char *path, int flags, ...)
{
    va_list args = (va_list)__builtin_next_arg(flags) - 48;
    SemaParam_237EA8 param;
    int result;
    Slot_237EA8 *slot;
    int semaphore;
    int queued;
    int index;
    int length;
    OpenRequest_237EA8 *request = &B_0044A680;

    func_00237B50(0);
    if (D_002C4A7C == 0) {
        func_00237BD8();
    }
    if (func_00237DE0() != 0) {
        func_00237B80();
        return 0xFFFEFFFC;
    }
    slot = func_00237558();
    if (slot == 0) {
        func_00237B80();
        return -0x13;
    }
    int mode = *(int *)args;
    for (length = 0; length < 0x400; length++) {
        unsigned char current = path[length];
        request->path[length] = current;
        if (current == 0) {
            break;
        }
    }
    if (length == 0x400) {
        request->path[0x3FF] = 0;
    }
    index = ((int)slot - (int)B_0044BB80) >> 4;
    request->flags = flags & 0x7FFFFFFF;
    request->mode = mode;
    param.initCount = 1;
    param.maxCount = 0;
    param.name = "SceStdioOpenSema";
    request->index = index;
    semaphore = CreateSema(&param);
    request->result = &result;
    request->sema = semaphore;
    request->field8 = 4;
    if (func_002375E0(B_0044BD80, 0, 0, &B_0044A680, 0x418, B_0044B2C0, 4, 0, 0, 0) < 0) {
        DeleteSema(semaphore);
        func_00237B80();
        return -0xB;
    }
    queued = *(int *)((int)B_0044B2C0 | 0x20000000);
    func_00237B80();
    if (queued == 0) {
        DeleteSema(semaphore);
        return -0xB;
    }
    WaitSema(semaphore);
    DeleteSema(semaphore);
    if (result < 0) {
        WaitSema(D_002C4A88);
        slot->state = 0;
        SignalSema(D_002C4A88);
        return result;
    }
    WaitSema(D_002C4A88);
    slot->state = slot->state | flags;
    slot->field0 = result;
    SignalSema(D_002C4A88);
    return index;
}
}
