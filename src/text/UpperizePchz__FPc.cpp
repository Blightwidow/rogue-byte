extern "C" const unsigned char RO_002AA6A1[];

void UpperizePchz(char *pch) {
    unsigned char *cursor = (unsigned char *)pch;
    if (*cursor != 0) {
        do {
            unsigned char ch = *cursor;
            int upper = ch - 0x20;
            if (!(RO_002AA6A1[ch] & 2)) upper = ch;
            *cursor = upper;
            cursor++;
        } while (*cursor != 0);
    }
}
