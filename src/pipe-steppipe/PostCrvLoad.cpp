#include "types.h"
struct Curve {
    char pad[0x38];
    f32 radius;
};
extern "C" {
void PostLoLoad();
f32 SRadiusCrv(Curve *);
extern f32 RO_002C0D00;

void PostCrvLoad(Curve *curve) {
    PostLoLoad();
    if (curve->radius == 1e10f) {
        curve->radius = (f32) (SRadiusCrv(curve) + RO_002C0D00);
    }
}

}
