struct S { int pad[0xFD50/4]; int value; };
extern "C" S B_002E65E0;
extern "C" void func_001B0848(int *out)
{
    if (B_002E65E0.value)
        *out = 0x47;
    else
        *out = 0x46;
}
