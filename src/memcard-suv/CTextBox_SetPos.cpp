// 0x258438 CTextBox::SetPos
void CTextBox_SetPos(void *arg0, float fparg0, float fparg1)
{
    *(float *)((char *)arg0 + 0) = fparg0;
    *(float *)((char *)arg0 + 4) = fparg1;
}
