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
void VIFS::AddVifStmask(unsigned maskValue)
{
    if (maskValue != 0) {
        Push(this, 0x20000000);
        Push(this, maskValue);
    }
    mask = maskValue;
}
