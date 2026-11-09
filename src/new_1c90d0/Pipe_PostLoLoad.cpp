#include "types.h"

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
