typedef int s128 __attribute__((mode(TI)));
extern "C" {
struct Cam_2DDF40 { char pad[0x90]; s128 position; };
extern Cam_2DDF40 B_002DDF40;
extern char B_003DD490;
s128 PosLoWorld(int);
int PpoSwFocus(char *);
s128 bevy_classes_k30_cam_150780(char *self) {
    s128 position;
    int target = *(int *)(self + 0x10);
    if (target != 0) {
        position = PosLoWorld(target);
    } else {
        int focus = PpoSwFocus(&B_003DD490);
        if (focus != 0) {
            position = PosLoWorld(focus);
            ((float *)&position)[2] += 150.0f;
        } else {
            position = B_002DDF40.position;
        }
    }
    return position;
}
}
