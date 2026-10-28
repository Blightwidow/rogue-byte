extern "C" int GrfsgsFromSgs(long sgs)
{
    if (sgs == -1)
        return 0;
    return 1 << sgs;
}