extern "C" {
extern unsigned char RO_002AA6A1[];

int NHashPchz(unsigned char *arg0) {
    int hash = 0;
    unsigned char *cursor = arg0;
    while (*cursor != 0) {
        int current = *cursor;
        int adjusted = current;
        if (RO_002AA6A1[current] & 2) {
            adjusted = current - 0x20;
        }
        cursor += 1;
        hash = (hash * 0x21) + adjusted;
    }
    return hash;
}
}
