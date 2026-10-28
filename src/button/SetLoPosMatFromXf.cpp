// 0x1A6BC8 SetLoPosMatFromXf
void SetLoPosMatFromXf(int arg1, int arg2);
void SetLoPosMat(int arg1, int arg2);
void SetLoPosMatFromXf(int arg1, int arg2)
{
    SetLoPosMat(arg1, arg2 + 0x40);
}