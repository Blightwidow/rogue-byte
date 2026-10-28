// 0x13CEB8 InitCrfodb
extern "C" void func_00183F08();

void InitCrfodb__FP6CRFODB(void *arg0)
{
    func_00183F08();
    int *f = (int *)((char *)arg0 + 0x184);
    *f = 0x2BC;
    *(int *)((char *)arg0 + 0x188) = -1;
    *(float *)((char *)arg0 + 0x18C) = 15.0f;
}