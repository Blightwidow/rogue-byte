extern "C" int *PactAddStgAction(void *, int);
extern "C" void func_001BBB50(void *self, int value)
{
    int *action = PactAddStgAction(self, 0xB);
    action[1] = value;
}
