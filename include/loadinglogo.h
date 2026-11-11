/* SPDX-License-Identifier: GPL-3.0-or-later */
/* The loading logo's mesh as DrawLoadingLogo (whole file 0x1C93E0) draws it: each part is a count and a run of LOGOTRIs, and each
   LOGOTRI names three LOGOVERTEXes by index into the vertex table (D_002C10D0), read as two floats. The tables are defined in
   src/data (typed from that reader). C and C++. */
#ifndef SLY2_LOADINGLOGO_H
#define SLY2_LOADINGLOGO_H
#include "types.h"

typedef struct LOGOVERTEX {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
} LOGOVERTEX;

typedef struct LOGOTRI {
    /* 0x0 */ s32 ipos[3]; /* indices into the vertex table */
} LOGOTRI;

#endif
