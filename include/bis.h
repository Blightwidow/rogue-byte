/* SPDX-License-Identifier: GPL-3.0-or-later */
/* CBinaryInputStream, the reader every Load*FromBrx function takes (0x1177A8-0x118454). C++ only.

   The readers named by their mangled symbol (U8Read__18CBinaryInputStream and the rest, config/matching/symbol_addrs.txt)
   are member functions; the ones with a plain C symbol (CBinaryInputStream_Read, _Skip, _ReadMatrix...) are declared
   extern "C" with the stream first. Return types are what each reader loads: lbu, lb, lhu, lh, lw, lwc1. The layout is
   left out: the loaders call the readers and never read the stream's fields. */
#ifndef SLY2_BIS_H
#define SLY2_BIS_H
#include "sly2.h"

class CBinaryInputStream {
public:
    void Align(int cb);
    void Decompress();
    u8 U8Read();
    u16 U16Read();
    u32 U32Read();
    s8 S8Read();
    s16 S16Read();
    s32 S32Read();
    f32 F32Read();
    void ReadVector(VECTOR *pvec);
    void Unknown1();
};

extern "C" {
int CBinaryInputStream_Read(CBinaryInputStream *pbis, int cb, void *pv);
void CBinaryInputStream_Read_thunk(CBinaryInputStream *pbis, int cb, void *pv); /* 0x117968: the Read the loaders call */
void CBinaryInputStream_Skip(CBinaryInputStream *pbis, int cb);
void CBinaryInputStream_ReadMatrix(CBinaryInputStream *pbis, MATRIX3 *pmat);
void CBinaryInputStream_ReadMatrix4(CBinaryInputStream *pbis, MATRIX4 *pmat);
void CBinaryInputStream_ReadVector4(CBinaryInputStream *pbis, VECTOR *pvec);
}
#endif
