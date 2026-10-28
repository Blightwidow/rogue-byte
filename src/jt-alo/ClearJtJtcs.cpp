// 0x18D548 ClearJtJtcs
extern "C" void SetJtJtcs(int, int);
void ClearJtJtcs(int pjt)
{
    SetJtJtcs(pjt, -1);
}