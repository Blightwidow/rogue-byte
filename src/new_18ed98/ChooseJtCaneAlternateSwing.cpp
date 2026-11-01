struct JT { char pad[0x18D8]; int swing; };
extern "C" int FCheckJtCaneSide(JT *);
extern "C" int ChooseJtCaneAlternateSwing(JT *jt)
{
    int next;
    switch (jt->swing) {
    case 0x16: next = 0x17; break;
    case 0x17: next = 0x16; break;
    default: next = FCheckJtCaneSide(jt) ? 0x17 : 0x16; break;
    }
    return next;
}
