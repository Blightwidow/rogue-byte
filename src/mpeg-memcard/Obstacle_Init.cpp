struct DL;
void InitDl(DL *, int);
extern "C" void InitCrv(void *);
extern "C" void Obstacle_Init(char *self)
{
    InitCrv(self);
    *(int *)(self + 0x1E8) = -1;
    InitDl((DL *)(self + 0x1C4), 0x1D0);
}
