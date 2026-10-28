extern "C" int *PentryFindSensorLo();
extern "C" int NGetSensorLoState()
{
    int *entry = PentryFindSensorLo();
    if (entry)
        return entry[1];
    return -1;
}
