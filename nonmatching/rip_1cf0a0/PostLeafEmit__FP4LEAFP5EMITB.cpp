#include "sly2.h"
struct MAT3 { QW r0, r1, r2; };
struct V4 { float x, y, z, w; };
extern "C" {
void func_001CE9B8();
float GRandInRange(float, float);
void LoadLookAtMatrix(MAT3 *, QW);
}
struct LEAF { char pad[0x40]; QW r0, r1, r2; };
struct EMITB;

void PostLeafEmit(LEAF *leaf, EMITB *emit)
{
    func_001CE9B8();
    V4 dir;
    float x = GRandInRange(-1.0f, 1.0f);
    float y = GRandInRange(-1.0f, 1.0f);
    float z = GRandInRange(0.1f, 0.9f) + 0.1f;
    dir.x = x;
    dir.y = y;
    dir.z = z;
    MAT3 mat;
    LoadLookAtMatrix(&mat, *(QW *)&dir);
    leaf->r0 = mat.r0;
    leaf->r1 = mat.r1;
    leaf->r2 = mat.r2;
}
