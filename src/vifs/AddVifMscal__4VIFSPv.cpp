class VIFS {
public:
    char pad[0xC];
    unsigned *cursor;
    void AddVifMscal(void *program);
};
void VIFS::AddVifMscal(void *program)
{
    int address = (int)program / 8; unsigned *slot = cursor; cursor = slot + 1; *slot = address | 0x14000000;
}
