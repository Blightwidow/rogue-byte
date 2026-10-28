extern "C" void SetMeterState(int *, int);
extern "C" void ReleaseMeter(int *meter)
{
    SetMeterState(meter, 0);
    meter[0xE] = 0;
}
