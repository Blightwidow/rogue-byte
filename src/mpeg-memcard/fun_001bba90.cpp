extern "C" int *PactAddStgAction(void *, int);
extern "C" void func_001BBA90(void *self, int value)
{
    int *action = PactAddStgAction(self, 7);
    action[1] = value;
}
