extern "C" int FIsBasicDerivedFrom(void *, int);

extern "C" char *PmemberFromLo(char *lo)
{
    if (lo == 0) return 0;
    if (FIsBasicDerivedFrom(lo, 0x58)) return lo + 0x150;
    if (FIsBasicDerivedFrom(lo, 0x1B)) return lo + 0x130;
    if (FIsBasicDerivedFrom(lo, 0x22)) return lo + 0xE0;
    if (FIsBasicDerivedFrom(lo, 0xC)) return lo + 0x190;
    if (FIsBasicDerivedFrom(lo, 0x23)) return lo + 0xE0;
    if (FIsBasicDerivedFrom(lo, 0x13)) return lo + 0x100;
    if (FIsBasicDerivedFrom(lo, 0xB)) return lo + 0x190;
    if (FIsBasicDerivedFrom(lo, 0xD)) return lo + 0x190;
    if (FIsBasicDerivedFrom(lo, 0x27)) return lo + 0xE0;
    return 0;
}
