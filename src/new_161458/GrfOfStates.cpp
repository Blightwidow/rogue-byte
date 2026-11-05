extern "C" {
int GrfOfState(int);

int GrfOfStates(int count, int *states) {
    int *cursor;
    int remaining;
    int flags;

    flags = 0;
    if (count > 0) {
        cursor = states;
        remaining = count;
        do {
            int state = *cursor;
            remaining -= 1;
            cursor += 1;
            flags |= GrfOfState(state);
        } while (remaining != 0);
    }
    return flags;
}
}
