class VIFS {
public:
    char pad[0xC];
    unsigned *cursor;
    char pad2[0xC];
    unsigned mask;
    void AddVifBaseOffset(int base, int offset);
    void AddVifMscal(void *program);
    void AddVifStmask(unsigned maskValue);
};
static inline void Push(VIFS *vifs, unsigned word)
{
    unsigned *slot = vifs->cursor;
    vifs->cursor = slot + 1;
    *slot = word;
}
void VIFS::AddVifBaseOffset(int base, int offset)
{
    Push(this, base | 0x3000000);
    Push(this, offset | 0x2000000);
}
