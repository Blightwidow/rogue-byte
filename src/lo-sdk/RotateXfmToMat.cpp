#include "sly2.h"
struct ROWS3 { VECTOR row[3]; };
struct XF;
struct XFM { char pad0[0x50]; XF *parent; char pad54[0x60 - 0x54]; ROWS3 mat; };
static inline void CopyRotation(ROWS3 *destination, ROWS3 *source) {
    destination->row[0] = source->row[0];
    destination->row[1] = source->row[1];
    destination->row[2] = source->row[2];
    destination->row[0].w = 0.0f;
    destination->row[1].w = 0.0f;
    destination->row[2].w = 0.0f;
}
extern "C" {
ROWS3 ConvertXfMat(int, XF *, ROWS3 *);
void InvalidateXfmMatWorld(XFM *);
// Retail loads rows 0 and 1 of the converted matrix, stores them, and only then loads row 2 into the register row 0 used
// ($v0 reused), with the destination held as a pointer ($v1 = xfm + 0x60) and the three w lanes cleared after the copies.
// Copying through a pointer pair (an inline helper taking destination and source pointers) makes the row loads depend on
// the earlier row stores; a direct copy from the local lets gcc hoist all three loads and allocate three registers.
// ConvertXfMat returns the 3x4 matrix by value (hidden pointer in $a0), as in src/new_1c90d0/fun_001cd308.cpp;
// InvalidateXfmMatWorld takes only the transform (its disassembly reads $a0 alone).
void RotateXfmToMat(XFM *xfm, ROWS3 *matrix) {
    ROWS3 local = ConvertXfMat(0, xfm->parent, matrix);
    CopyRotation(&xfm->mat, &local);
    InvalidateXfmMatWorld(xfm);
}
}
