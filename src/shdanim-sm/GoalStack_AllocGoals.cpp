struct AllocRequest_1EEC70 { int size; int alignment; };
extern "C" int CbGoalMax();
extern "C" void *PvAllocSwImpl__Fi(AllocRequest_1EEC70 *);
extern "C" void GoalStack_AllocGoals(char *stack)
{
    void **slot = (void **)(stack + 8);
    for (unsigned int index = 0; index < 8; index++) {
        AllocRequest_1EEC70 request;
        request.size = CbGoalMax();
        request.alignment = 0x10;
        *slot++ = PvAllocSwImpl__Fi(&request);
    }
}
