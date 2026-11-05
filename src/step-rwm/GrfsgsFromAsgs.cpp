extern "C" {
int GrfsgsFromSgs(int);

int GrfsgsFromAsgs(int count, int *items) {
    int *cursor;
    int remaining;
    int flags;

    flags = 0;
    if (count > 0) {
        cursor = items;
        remaining = count;
        do {
            int item = *cursor;
            remaining -= 1;
            cursor += 1;
            flags |= GrfsgsFromSgs(item);
        } while (remaining != 0);
    }
    return flags;
}
}
