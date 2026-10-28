extern "C" int *PactAddStgAction(void *, int);
extern "C" void AddStgActionShow(void *self, int value)
{
    int *action = PactAddStgAction(self, 0);
    action[1] = value;
}
