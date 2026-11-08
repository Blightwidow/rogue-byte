// SPDX-License-Identifier: GPL-3.0-or-later
struct PO {
    char pad0[0x40];
    int flags40; // tagged: bit 0 clear means it holds a pointer to the flag word
    char pad44[0x180 - 0x44];
    int field180;
    char pad184[0x194 - 0x184];
    int field194;
    char pad198[0x1F0 - 0x198];
    int field1F0;
    int field1F4;
    int field1F8;
    int field1FC;
    int field200;
};
extern "C" void InitPo(PO *po);

// Tag test of the word at +0x40: true when bit 0 is clear (the word is a pointer).
static inline bool FIsPointer(int flags) { return (flags & 1) == 0; }

// Retail: InitPo(po), then +0x1F0 = 0x7B and six fields = -1, and bit 2 set
// in the tagged word at +0x40 (through the pointer when bit 0 is clear, in
// place otherwise). The test is `xori 1; andi 1; beqz` with the andi
// scheduled two slots after the xori: the tag test is a bool returned by an
// inline helper. A direct `(flags & 1) == 0` gives andi + bnez, and the
// open-coded `(flags ^ 1) & 1` keeps the andi right after the xori (score 2).
extern "C" void func_001C8280(PO *po)
{
    InitPo(po);
    po->field1F0 = 0x7B;
    po->field1FC = -1;
    po->field1F8 = -1;
    po->field1F4 = -1;
    po->field200 = -1;
    po->field180 = -1;
    po->field194 = -1;
    int flags = po->flags40;
    if (FIsPointer(flags)) {
        *(int *)flags |= 2;
    } else {
        po->flags40 = flags | 2;
    }
}
