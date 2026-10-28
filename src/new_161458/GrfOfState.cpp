extern "C" int GrfOfState(int state)
{
    if (state == -1)
        return 0;
    return (int)(1UL << state);
}
