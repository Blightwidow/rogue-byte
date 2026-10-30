extern "C" {
struct Slot_1CD998 { char pad[8]; char data[8]; };
void *memset(void *, int, unsigned);
extern Slot_1CD998 *B_003D4A50;
Slot_1CD998 *OnGameLoad__FP4GAME(void) {
    memset(B_003D4A50->data, 0, 8);
    return B_003D4A50++;
}
}
