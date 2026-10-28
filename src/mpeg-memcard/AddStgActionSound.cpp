extern "C" int *PactAddStgAction(void *, int);
extern "C" void AddStgActionSound(void *self, int value)
{
    int *action = PactAddStgAction(self, 0xA);
    action[1] = value;
}
