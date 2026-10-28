extern "C" int ClassifyMcStart(int);
extern "C" int ClassifyMcSync(int);
extern "C" int McErrorFromResult(int, int);
extern "C" int sceMcSync(int, int *, int *);
int McSync(void *pmc, int nStart, int nFuncNo, int *pnResult)
{
    int nError = ClassifyMcStart(nStart);
    if (nError != 0x1D) return nError;
    int sync[2];
    int nSync = sceMcSync(0, &sync[0], &sync[1]);
    nError = ClassifyMcSync(nSync);
    if (pnResult != 0)
        *pnResult = sync[1];
    if (nError == 0x22)
        nError = McErrorFromResult(nFuncNo, sync[1]);
    return nError;
}
