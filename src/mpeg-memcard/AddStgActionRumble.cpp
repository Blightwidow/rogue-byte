extern "C" int *PactAddStgAction(void *, int);
extern "C" void AddStgActionRumble(void *self, int value)
{
    int *action = PactAddStgAction(self, 9);
    action[1] = value;
}
