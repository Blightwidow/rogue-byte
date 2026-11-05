struct Blot { int word0; int word4; char pad8[4]; void *vtable; char pad10[0x7C - 0x10]; int word7C; char pad80[0xCC - 0x80]; int slots[10]; };
extern "C" {
void InitSl(void *, int);
extern char D_002DAF30;

Blot *Blot_Construct(Blot *blot) {
    blot->vtable = &D_002DAF30;
    blot->word7C = -1;
    unsigned index = 0;
    blot->word0 = 0;
    blot->word4 = 0;
    for (; index < 10U; index++)
        blot->slots[index] = -1;
    InitSl((char *)blot + 0xFC, 0x68);
    return blot;
}
}
