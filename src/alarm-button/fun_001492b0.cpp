extern "C" {
typedef unsigned int u32;
typedef int s32;
void RemoveSoLoHierarchy(void *);
void SetButtonButtons(void *, s32);
void func_001492B0(void *arg0)
{
    RemoveSoLoHierarchy(arg0);
    if ((u32)(*(s32 *)((char *)arg0 + 0x1E0) - 1) < 2U) {
        SetButtonButtons(arg0, 0);
    }
}
}
