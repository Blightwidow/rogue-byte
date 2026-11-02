// new() factory of a class with two bases: the primary base keeps its vptr at +0xC after three words (the first two
// zeroed by its constructor), the second base sits at +0xF4 with its vptr at +0x100. The inline constructor of the
// derived class (compiler-generated, multiple inheritance) gives retail's copy of the new object into $v1.
// Link: gcc names the two vtables _vt$<derived> and _vt$<derived>$<second base>; they are retail's
// D_ symbols of this function (primary at +0xC, secondary at +0x100).
struct CPrimary111218 {
    int unk0x0;
    int unk0x4;
    int unk0x8;
    CPrimary111218()
    {
        unk0x0 = 0;
        unk0x4 = 0;
    }
    virtual void Virtual0();
};
struct CPrimaryBody111218 : CPrimary111218 {
    char pad[0xE4];
};
struct CSecondary111218 {
    int unk0x0[3];
    virtual void Virtual0();
};
struct CObject111218 : CPrimaryBody111218, CSecondary111218 {
    char pad2[0xC];
    virtual void Virtual0();
};
void *func_00111218(void)
{
    return new CObject111218;
}
