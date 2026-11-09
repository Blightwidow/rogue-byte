// SPDX-License-Identifier: GPL-3.0-or-later
#include "cref.h"
extern "C" char B_003D4A60[];
extern "C" const char RO_002A8AA0[];
extern "C" CRef RefGetGameSaveValue(int *, void *);
extern "C" int sprintf(char *, const char *, ...);

extern "C" void func_00210ED0(char *out, int **pkey)
{
    int *key = *pkey;
    if (key && *key) {
        const char *format = RO_002A8AA0;
        int value = RefGetGameSaveValue(key, B_003D4A60).m_tag.m_n;
        sprintf(out, format, value);
    }
}
