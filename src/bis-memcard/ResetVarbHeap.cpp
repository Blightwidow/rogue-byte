typedef int s32;
extern "C" {
void ResetSlotheap(void *);
extern s32 B_002DD290;
extern s32 B_002DD294;
extern s32 B_002DD298;
extern s32 B_002DD29C;
extern char B_004520D0;

void ResetVarbHeap(void)
{
    B_002DD290 = 0;
    B_002DD298 = 0;
    B_002DD29C = 0;
    B_002DD294 = 0;
    ResetSlotheap(&B_004520D0);
}
}
