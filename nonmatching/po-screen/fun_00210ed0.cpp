// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; int n; };
extern "C" char B_003D4A60[];
extern "C" const char RO_002A8AA0[];
extern "C" CRef *RefGetGameSaveValue(CRef *, int *, void *);
extern "C" void CRef_Destruct(CRef *);
extern "C" int sprintf(char *, const char *, ...);

extern "C" void func_00210ED0(char *out, int **pkey)
{
    int *key = *pkey;
    if (key && *key) {
        const char *format = RO_002A8AA0;
        CRef ref;
        RefGetGameSaveValue(&ref, key, B_003D4A60);
        int value = ref.n;
        CRef_Destruct(&ref);
        sprintf(out, format, value);
    }
}
