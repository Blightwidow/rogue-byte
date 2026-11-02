// new() factory of a class with two bases: the primary base keeps its vptr at +0xC after three words (the first two
// zeroed by its constructor), the second base sits at +0x114 with its vptr at +0x120. The inline constructor of the
// derived class (compiler-generated, multiple inheritance) gives retail's copy of the new object into $v1.
// Link: gcc names the two vtables _vt$<derived> and _vt$<derived>$<second base>; they are retail's
// D_ symbols of this function (primary at +0xC, secondary at +0x120).
struct CPrimary110EC0 {
    int unk0x0;
    int unk0x4;
    int unk0x8;
    CPrimary110EC0()
    {
        unk0x0 = 0;
        unk0x4 = 0;
    }
    virtual void Virtual0();
};
struct CPrimaryBody110EC0 : CPrimary110EC0 {
    char pad[0x104];
};
struct CSecondary110EC0 {
    int unk0x0[3];
    virtual void Virtual0();
};
struct CObject110EC0 : CPrimaryBody110EC0, CSecondary110EC0 {
    char pad2[0x1C];
    virtual void Virtual0();
};
void *func_00110EC0(void)
{
    return new CObject110EC0;
}
