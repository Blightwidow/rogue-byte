extern "C" int *PactAddStgAction(void *, int);
extern "C" void AddStgActionHide(char *self, int value)
{
    if (value == -1)
        value = *(int *)(self + 0x18);
    int *action = PactAddStgAction(self, 1);
    action[1] = value;
}
