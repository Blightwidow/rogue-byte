struct VT212880 { char pad[0x188]; short delta; short index; void (*fn)(char *, int); };
struct Blot212880 { char pad[0xC]; VT212880 *vt; char pad2[0xBC]; int labels[10]; };
extern "C" {
void SetBlotLabelList(Blot212880 *blot, int count, int *labels) {
    int *dest = blot->labels;
    int index = 0;
    if (count > 0) {
        dest = blot->labels;
        do {
            *dest++ = *labels++;
            index++;
        } while (index < count && (unsigned)index < 10);
    }
    blot->vt->fn((char *)blot + blot->vt->delta, -1);
}
}
