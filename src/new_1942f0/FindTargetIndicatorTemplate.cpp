extern "C" int PloFindSwObject_thunk(char *, int, int, int);
void FindTargetIndicatorTemplate(char *self)
{
    *(int *)(self + 0x4744) = PloFindSwObject_thunk(self, 0x405, 0x624, 0);
}
