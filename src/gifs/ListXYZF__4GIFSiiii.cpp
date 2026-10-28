struct GIFS {
    char pad0[0xC];
    unsigned long *cursor;
    void CheckReg(int, int);
    void ListXYZF(int, int, int, int);
};
void GIFS::ListXYZF(int x, int y, int z, int fog)
{
    CheckReg(0, 4);
    unsigned long *dword = cursor;
    cursor = dword + 1;
    *dword = (unsigned long)(x | (y << 16)) | ((unsigned long)(z & 0xFFFFFF) << 32) | ((unsigned long)fog << 56);
}
