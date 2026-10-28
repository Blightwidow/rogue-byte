// 0x1EECD0 GoalStack_Clear
extern "C" void Goal_Pop(void *a0, void *a1);

extern "C" void GoalStack_Clear(int *a0)
{
    if (*(int *)(a0 + 4) > 0) {
        Goal_Pop((void *)((char *)a0 - 0x30), *(int **)(a0 + 8));
    }
}
