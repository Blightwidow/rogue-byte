extern "C" int OidFromICheer(int cheer) {
    switch (cheer) {
    case 0: return 0x626;
    case 1: return 0x627;
    case 2: return 0x628;
    }
    return -1;
}
