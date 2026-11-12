#include "types.h"

extern "C" {
struct SemaParam_238138 { int attr; int initCount; int maxCount; int field0C; int field10; const char *name; };
struct SemaState_238138 { int sema; int *result; int field8; int handle; int index; };
int CreateSema(SemaParam_238138 *);
void DeleteSema(int);
void WaitSema(int);
char *func_002376D0(void);
void func_00237B50(int);
void func_00237B80(void);
int func_002375E0(char *, int, int, SemaState_238138 *, int, char *, int, int, int, int);
extern SemaState_238138 B_0044A680;
extern char B_0044BB80[];
extern char B_0044B2C0[];
extern char B_0044BD80[];
extern int D_002C4A7C;

int sceClose(void)
{
    SemaState_238138 *state;
    int semaphore;
    char *record;
    SemaParam_238138 param;
    int result;
    int queued;
    int ret;

    state = &B_0044A680;
    record = func_002376D0();
    func_00237B50(1);
    if (D_002C4A7C == 0 || record == 0 || *(int *)(record + 4) == 0) {
        func_00237B80();
        return -9;
    }
    state->handle = *(int *)record;
    state->index = ((int)record - (int)B_0044BB80) >> 4;
    param.initCount = 1;
    param.name = "SceStdioCloseSema";
    param.maxCount = 0;
    semaphore = CreateSema(&param);
    B_0044A680.sema = semaphore;
    state->result = &result;
    state->field8 = 4;
    ret = func_002375E0(B_0044BD80, 1, 0, state, 0x14, B_0044B2C0, 4, 0, 0, 0);
    if (ret < 0) {
        DeleteSema(semaphore);
        func_00237B80();
        return -11;
    }
    *(int *)(record + 4) = 0;
    queued = *(int *)((int)B_0044B2C0 | 0x20000000);
    func_00237B80();
    if (queued == 0) {
        DeleteSema(semaphore);
        return -11;
    }
    WaitSema(semaphore);
    DeleteSema(semaphore);
    return (result > 0) ? 0 : result;
}
}
