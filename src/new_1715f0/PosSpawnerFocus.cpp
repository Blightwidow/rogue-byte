typedef int s32; typedef int s128 __attribute__((mode(TI)));
extern "C" {
s128 PosLoWorld(s32);
s32 PpoSwFocusBase(void *);
struct Focus { char pad[0x90]; s128 position; };
extern Focus B_002DDF40;
extern char B_003DD490;

s128 PosSpawnerFocus(void) {
    if (PpoSwFocusBase(&B_003DD490) != 0) {
        return PosLoWorld(PpoSwFocusBase(&B_003DD490));
    }
    return B_002DDF40.position;
}
}
