extern "C" int *PactAddStgAction(void *, int);
extern "C" void func_001BBA60(void *self, int value)
{
    int *action = PactAddStgAction(self, 6);
    action[1] = value;
}
