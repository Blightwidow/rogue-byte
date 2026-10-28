// 0x258458 FUN_00258458
typedef struct { char b[4]; } Unaligned4 __attribute__((packed));
void CTextBox_SetTextColor(void *arg0, void *arg1)
{
    Unaligned4 *src = (Unaligned4 *)arg1;
    Unaligned4 *dst = (Unaligned4 *)((unsigned char *)arg0 + 0x10);
    *dst = *src;
}