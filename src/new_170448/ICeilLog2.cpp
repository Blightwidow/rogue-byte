extern "C" {
int ICeilLog2(int value) {
    if (value >= 9) {
        if (value >= 0x21) {
            if (value < 0x41) return 6;
            return 7;
        }
        if (value < 0x11) return 4;
        return 5;
    }
    if (value >= 3) {
        if (value < 5) return 2;
        return 3;
    }
    if (value == 0) return -1;
    return value >= 2;
}
}
