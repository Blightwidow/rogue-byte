// 0x116D00 FUN_00116d00
// memcmp of 16 bytes.
int CompareAb16(const void* pvA, const void* pvB)
{
    return memcmp(pvA, pvB, 16);
}