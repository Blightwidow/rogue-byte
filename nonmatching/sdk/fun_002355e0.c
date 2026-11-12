typedef int QW __attribute__((mode(TI)));

typedef struct ThreadStatus {
    int state;
    int field04;
    int base;
    int offset;
    char rest[0x20];
} ThreadStatus;

extern int func_00235100(int threadId, int priority);
extern int func_00239450(void);
extern void func_002394A0(void);
extern int ReferThreadStatus(int threadId, ThreadStatus *status);
extern int StartThread(int threadId, int priority);

int func_002355E0(int threadId, int priority)
{
    ThreadStatus status;
    int result;
    int zeroIndex;
    char *block;

    if (func_00235100(threadId, priority) != 0)
        return -1;
    if (func_00239450() == 0)
        return -1;
    result = ReferThreadStatus(threadId, &status);
    if (result < 0) {
        func_002394A0();
        return result;
    }
    if (status.state != 0x10) {
        func_002394A0();
        return -1;
    }
    block = (char *)(status.base + status.offset - 0x2A0);
    for (zeroIndex = 0; zeroIndex < 0x28; zeroIndex++)
        ((QW *)block)[zeroIndex] = 0;
    *(long long *)(block + 0x40) = priority;
    *(long long *)(block + 0x1C0) = *(int *)(block + 0x1C0);
    *(long long *)(block + 0x1C8) = 0;
    *(long long *)(block + 0x1D0) = *(int *)(block + 0x1D0);
    *(long long *)(block + 0x1D8) = 0;
    *(long long *)(block + 0x1E0) = *(int *)(block + 0x1E0);
    *(long long *)(block + 0x1E8) = 0;
    *(long long *)(block + 0x1F0) = *(int *)(block + 0x1F0);
    *(long long *)(block + 0x1F8) = 0;
    func_002394A0();
    return StartThread(threadId, priority);
}
