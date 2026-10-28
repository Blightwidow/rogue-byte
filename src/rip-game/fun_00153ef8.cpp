extern "C" void AddSensorLo(int, int);
extern "C" void func_00153EF8(int unused, int a, int b)
{
    if (a != b)
        AddSensorLo(unused, b);
}
