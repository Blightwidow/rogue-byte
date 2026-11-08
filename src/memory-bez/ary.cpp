// SPDX-License-Identifier: GPL-3.0-or-later
// Retail 0x116CA0-0x117030: one source file, ending at constructor 5 of the list at 0x2C85C0 (config/us/whole_files.tsv).
// The functions in retail order; the bodies are the matched sources of src/MANIFEST.tsv, the rest come from assembly.
#include "include_asm.h"

extern "C" int memcmp(const void *, const void *, unsigned int);

int func_00116ca0(const void *a, const void *b)
{
    return memcmp(a, b, 4);
}

int func_00116CC0(const void *a, const void *b)
{
    return memcmp(a, b, 8);
}

int func_00116CE0(const void *a, const void *b)
{
    return memcmp(a, b, 12);
}

int CompareAb16(const void *pvA, const void *pvB)
{
    return memcmp(pvA, pvB, 16);
}

INCLUDE_ASM(0x116D20); // func_00116D20: two words, not a function compiled from C

struct VTable116D28 {
    char pad[0x18];
    short delta;
    short index;
    void (*function)(char *, int);
};
struct Object116D28 {
    VTable116D28 *vtable;
};
struct Holder116D28 {
    int first;
    int second;
    int third;
    int unk0xC;
    int unk0x10;
    Object116D28 *object;
};
void func_00116D28(Holder116D28 *self)
{
    Object116D28 *object = self->object;
    object->vtable->function((char *)object + object->vtable->delta, self->first);
    self->first = 0;
    self->third = 0;
    self->second = 0;
}

struct VT { char pad[0x10]; short delta; short index; void *(*fn)(void *, void *, int, int); };
struct ALLOC { VT *vt; };
struct CAry { void *data; int count; int max; int elemSize; ALLOC *alloc0; ALLOC *alloc; };

void CAry_Reserve(CAry *ary, int needed)
{
    int max = ary->max;
    if (max < needed) {
        int newMax;
        if (needed < 0x200) {
            newMax = 8;
            if (max) newMax = max;
            if (newMax < needed) {
                do newMax <<= 1; while (newMax < needed);
            }
        } else {
            newMax = (needed + 0x3FF) & ~0x3FF;
        }
        ALLOC *alloc = ary->alloc;
        VT *vt = alloc->vt;
        void *result = vt->fn((char *)alloc + vt->delta, ary->data, newMax * ary->elemSize, 4);
        ary->data = result;
        ary->max = newMax;
    }
}

extern "C" int memcpy(int, int, int);

void func_00116E30(char *arg0, int arg1, int arg2)
{
    int temp_v0;

    CAry_Reserve((CAry *)arg0, *(int *)(arg0 + 4) + arg2);
    temp_v0 = *(int *)(arg0 + 0xC);
    memcpy(*(int *)(arg0 + 0) + (temp_v0 * *(int *)(arg0 + 4)), arg1, temp_v0 * arg2);
    *(int *)(arg0 + 4) = *(int *)(arg0 + 4) + arg2;
}

INCLUDE_ASM(0x116EA8); // func_00116EA8: epilogue fragments, nonmatching/ at score 11

int CreateSlotheapSwAlign(int *, int, int, int);
extern int B_002DD2E0;
extern int B_002DD2E4;
extern int B_002DD2E8;
extern int B_002DD2EC;
extern int B_002DD2F0;
extern int B_002DD2F4;
extern int B_004520A8;
extern int B_004520D0;
extern int B_004520F8;
extern int B_00452120;
extern int B_00452148;
extern int B_00452170;

// __static_initialization_and_destruction_0 of the file
void func_00116ED8(int arg0, int arg1)
{
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v0_5;
    int temp_v0_6;

    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        temp_v0 = B_002DD2E0 + 1;
        B_002DD2E0 = temp_v0;
        if (temp_v0 == 1) {
            CreateSlotheapSwAlign(&B_004520A8, 0x14, 0x2000, 0x10);
        }
        temp_v0_2 = B_002DD2E4 + 1;
        B_002DD2E4 = temp_v0_2;
        if (temp_v0_2 == 1) {
            CreateSlotheapSwAlign(&B_004520D0, 0x18, 0x800, 0x10);
        }
        temp_v0_3 = B_002DD2E8 + 1;
        B_002DD2E8 = temp_v0_3;
        if (temp_v0_3 == 1) {
            CreateSlotheapSwAlign(&B_004520F8, 0x28, 0x200, 0x10);
        }
        temp_v0_4 = B_002DD2EC + 1;
        B_002DD2EC = temp_v0_4;
        if (temp_v0_4 == 1) {
            CreateSlotheapSwAlign(&B_00452120, 0x1C, 0x800, 0x10);
        }
        temp_v0_5 = B_002DD2F0 + 1;
        B_002DD2F0 = temp_v0_5;
        if (temp_v0_5 == 1) {
            CreateSlotheapSwAlign(&B_00452148, 0xC, 0xC8, 0x10);
        }
        temp_v0_6 = B_002DD2F4 + 1;
        B_002DD2F4 = temp_v0_6;
        if (temp_v0_6 == 1) {
            CreateSlotheapSwAlign(&B_00452170, 0x14, 0x100, 0x10);
        }
    }
}

// _GLOBAL_$I$ of the file: constructor 5
void func_00117010(void)
{
    func_00116ED8(1, 0xFFFF);
}
