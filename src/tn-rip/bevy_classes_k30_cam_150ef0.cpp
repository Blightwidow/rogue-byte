typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
struct CameraState {
    char pad0[0x18];
    f32 minDistance;
    char pad1C[4];
    s128 position;
    s128 target;
    char pad40[0x10];
    s128 previousPosition;
    s128 previousTarget;
    f32 previousDistance;
    char pad74[0xC];
    s128 currentPosition;
    s128 currentTarget;
    f32 currentDistance;
    char padA4[8];
    f32 distance;
};

extern "C" {
s128 bevy_classes_k30_cam_150780();
s128 bevy_classes_k30_cam_1507f8(CameraState *);

void bevy_classes_k30_cam_150ef0(CameraState *camera) {
    camera->position = bevy_classes_k30_cam_150780();
    camera->target = bevy_classes_k30_cam_1507f8(camera);
    f32 minimum = camera->minDistance;
    if (minimum >= 0.0f) {
        camera->distance = minimum;
    }
    camera->previousPosition = camera->currentPosition;
    camera->previousTarget = camera->currentTarget;
    camera->previousDistance = camera->currentDistance;
}

}
