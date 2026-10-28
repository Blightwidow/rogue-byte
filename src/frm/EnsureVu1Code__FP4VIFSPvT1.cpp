extern "C" void AddDmaRefs__4DMASiP2QW(void *, int, void *);
extern "C" void EnsureVu1Code__FP4VIFSPvT1(void *vif, char *start, char *end)
{
    AddDmaRefs__4DMASiP2QW(vif, (unsigned)(end - start + 15) >> 4, start);
}
