extern "C" {
int ClassifyMcSync(int arg0) {
    switch (arg0) {
    case 0: return 0x21;
    case 1: return 0x22;
    case -1: return 0x20;
    }
    return 0x1F;
}
}
