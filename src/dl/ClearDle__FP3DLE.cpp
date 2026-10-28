// ClearDle__FP3DLE
// 0x11A210
extern "C" void ClearDle__FP3DLE(void *a0);

extern "C" void ClearDle__FP3DLE(void *a0)
{
    *(int *)((char *)a0 + 4) = 0;
    *(int *)((char *)a0 + 0) = 0;
}
