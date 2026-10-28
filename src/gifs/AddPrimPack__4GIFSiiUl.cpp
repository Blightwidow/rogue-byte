struct GIFS;
struct VSLOT { short delta; short index; void (*fn)(void *, int); };
struct GIFS {
    char pad0[0xC];
    unsigned long *cursor;
    char pad1[0x18 - 0x10];
    VSLOT *vtable;
    unsigned long *prim;
    int creg;
    int cregAll;
    void AddPrimPack(int, int, unsigned long);
};
void GIFS::AddPrimPack(int prim_, int creg_, unsigned long regs)
{
    VSLOT *slot = &vtable[1];
    slot->fn((char *)this + slot->delta, 0);
    unsigned long *tag = cursor;
    cursor = tag + 2;
    tag[0] = (((unsigned long)prim_ << 0x2F) | 0x400000000000UL) | ((unsigned long)creg_ << 0x3C);
    tag[1] = regs;
    creg = creg_;
    cregAll = 0;
    prim = tag;
}
