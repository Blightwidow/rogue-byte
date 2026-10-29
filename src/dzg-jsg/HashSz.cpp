extern "C" {
extern unsigned char RO_002AA6A1[];
extern unsigned char RO_002A4150[];

int HashSz(unsigned char *arg0) {
    unsigned char *cursor;
    int hash;
    int current;
    int adjusted;

    cursor = arg0;
    if (cursor == 0) {
        cursor = RO_002A4150;
    }
    hash = 0;
    if (*cursor != 0) {
        do {
            current = *cursor;
            adjusted = current;
            if (RO_002AA6A1[current] & 2) {
                adjusted = current - 0x20;
            }
            hash = (hash * 0x21) + adjusted;
            cursor += 1;
        } while (*cursor != 0);
    }
    return hash;
}

}
