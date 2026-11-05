struct Animref { int pad[4]; };
extern "C" void CloneAnimref(Animref *);
extern "C" void CloneAnimrefArray(void *unused, Animref *refs) {
    int remaining = 0x19;
    do {
        remaining -= 1;
        CloneAnimref(refs);
        refs += 1;
    } while (remaining >= 0);
}
