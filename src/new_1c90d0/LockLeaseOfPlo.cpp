extern "C" int *PleaseFromPlo(void *);
extern "C" void LockLeaseOfPlo(void *plo)
{
    int *lease = PleaseFromPlo(plo);
    if (lease)
        lease[2] = 1;
}
