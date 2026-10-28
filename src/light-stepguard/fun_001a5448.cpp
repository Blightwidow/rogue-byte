extern "C" char B_003DD4A0;
void func_001A5448(char *self, char **first, char **second)
{
    if (self) {
        *first = self + 0x64;
        *second = self + 0x70;
        return;
    }
    *first = &B_003DD4A0;
    *second = &B_003DD4A0 + 0xC;
}
