typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64;

extern "C" {
struct Pipe {
    char pad0[0x38];
    f32 radius;
};

void PostLoLoad();
f32 SRadiusCrv(Pipe*);

extern f32 RO_002C1EC0;

void Pipe_PostLoLoad(Pipe* pipe) {
    PostLoLoad();
    if (pipe->radius == 1e10f) {
        pipe->radius = (f32)(SRadiusCrv(pipe) + RO_002C1EC0);
    }
}
}
