#include "sly2.h"
struct TEXT { char pad[0x64]; float xOffset; float yOffset; };

void CMovieText_BuildGsMatrix(TEXT *text, float *out, float *affine)
{
    memset(out, 0, 0x40);
    out[0] = affine[0] * 0.8f;
    out[1] = affine[1] * 0.45454547f;
    out[4] = affine[2] * 0.8f;
    out[5] = affine[3] * 0.45454547f;
    out[8] = affine[4] * 0.8f + text->xOffset + 786432.0f;
    out[9] = affine[5] * 0.45454547f + text->yOffset + 786432.0f;
    out[10] = 1.0f;
    out[15] = 1.0f;
}
