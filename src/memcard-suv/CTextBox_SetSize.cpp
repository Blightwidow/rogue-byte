void CTextBox_SetSize(void *arg0, float dx, float dy)
{
    *(float *)((unsigned char *)arg0 + 0x8) = dx;
    *(float *)((unsigned char *)arg0 + 0xC) = dy;
}
