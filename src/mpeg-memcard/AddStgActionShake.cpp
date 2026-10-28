extern "C" int *PactAddStgAction(void *, int);
extern "C" void AddStgActionShake(void *self, int value)
{
    int *action = PactAddStgAction(self, 8);
    action[1] = value;
}
