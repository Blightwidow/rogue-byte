extern "C" int ICheerFromOid(int oid) {
    switch (oid) {
    case 0x626: return 0;
    case 0x627: return 1;
    case 0x628: return 2;
    }
    return -1;
}
