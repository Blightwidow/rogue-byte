typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0016DA48 {
    /* 0x0000 */ char pad0[4];
    /* 0x0004 */ s32 sp4;                           /* inferred */
    /* 0x0008 */ char pad8[4];
    /* 0x000C */ s32 spC;                           /* inferred */
    /* 0x0010 */ char pad10[0x20];                  /* maybe part of spC[9]? */
    /* 0x0030 */ M2C_UNK sp30;                      /* inferred */
    /* 0x0030 */ char pad30[0x1000];
    /* 0x1030 */ s32 sp1030;                        /* inferred */
    /* 0x1034 */ s32 sp1034;                        /* inferred */
    /* 0x1038 */ char pad1038[0x98];
};                                                  /* size = 0x10D0 */
#define sp4 (*(s32 *)(sp + 0x0004))
#define spC (*(s32 *)(sp + 0x000C))
void AddDmaCall__4DMASP2QW(s32, M2C_UNK *);
s32 AddDmaCnt__4DMAS(s32);
void AddPrimList__4GIFSiUl(s8 *, M2C_UNK, M2C_UNK);
void AddPrimPack__4GIFSiiUl(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 AddVifBaseOffset__4VIFSii(s32, M2C_UNK, M2C_UNK);
s32 AddVifFlush__4VIFS(s32);
s32 AddVifFlusha__4VIFS(s32);
s32 AddVifMscal__4VIFSPv(s32, M2C_UNK);
void AddVifUnpack__4VIFS3UPKiPvi(s32, M2C_UNK, u32, s32, M2C_UNK);
void AllocStatic__4DMASiP2QW(s8 *, M2C_UNK, M2C_UNK *);
void EndDmaCnt__4DMAS(s32);
s32 EndPrim__4GIFSi(s8 *, M2C_UNK);
void EnsureVu1Code__FP4VIFSPvT1(M2C_UNK *, M2C_UNK *);
void GIFS_ListXYZ(s8 *, s32, M2C_UNK, M2C_UNK);
void PackAD__4GIFSll(s8 *, M2C_UNK, s64);
void UnpackHelper__4VIFS3UPKiiPiPPUi(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32 *);
void __4GIFS(s8 *);
s32 func_0016D698(M2C_UNK, s8 *, s32 *);
void func_0016D6C8(s8 *, M2C_UNK, s32 *);
extern M2C_UNK B_002DF800;
extern s32 B_003E12C8;
extern M2C_UNK RO_0025C1C0;
extern M2C_UNK RO_0025E040;
extern M2C_UNK g_2deb70;
void func_0016DA48(s32 arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10D0] __attribute__((aligned(16)));
    M2C_UNK sp30;
    s32 sp1030;
    s32 sp1034;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    EnsureVu1Code__FP4VIFSPvT1(&RO_0025C1C0, &RO_0025E040);
    AddDmaCnt__4DMAS(arg0);
    if ((arg2 != 7) && (B_003E12C8 != 0)) {
        AddVifFlush__4VIFS(arg0);
        AddDmaCall__4DMASP2QW(arg0, &B_002DF800);
        AddVifBaseOffset__4VIFSii(arg0, 0x32, 0x1E7);
    }
    UnpackHelper__4VIFS3UPKiiPiPPUi(arg0, 5, 5, 0x1B, 0, &sp1030);
    sp1034 = sp1030;
    __4GIFS(sp);
    AllocStatic__4DMASiP2QW(sp, 0x100, &sp30);
    if (arg2 != 7) {
        func_0016D6C8(sp, 0x299, &sp1034);
    }
    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
    func_0016D698(0, sp, &sp1034);
    if ((arg1 == 7) || (arg2 != 7)) {
        PackAD__4GIFSll(sp, 0x4C, 0x807F8000 << 0x11);
    } else {
        PackAD__4GIFSll(sp, 0x4C, 0x80FF0000 << 0x10);
    }
    PackAD__4GIFSll(sp, 0x46, 0);
    PackAD__4GIFSll(sp, 0x47, 0x31001);
    if (arg1 == 7) {
        PackAD__4GIFSll(sp, 1, (0x8000 << 0x11) | 0x7E00);
    } else {
        PackAD__4GIFSll(sp, 1, (0x8000 << 0x11) | 0x3E00);
    }
    PackAD__4GIFSll(sp, 0, 6);
    var_s2 = 0x7200;
    var_s1 = 0x7000;
    AddPrimList__4GIFSiUl(sp, 2, 0x55);
    var_s0 = 0x1E0;
    do {
        GIFS_ListXYZ(sp, var_s1, 0x7900, 0);
        var_s1 += 0x200;
        GIFS_ListXYZ(sp, var_s2, 0x8700, 0);
        var_s0 -= 0x20;
        var_s2 += 0x200;
    } while (var_s0 >= 0);
    if ((arg1 == 8) && (arg2 == 7)) {
        AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
        func_0016D698(0, sp, &sp1034);
        PackAD__4GIFSll(sp, 0x4C, 0x807F8000 << 0x11);
    }
    EndPrim__4GIFSi(sp, 1);
    func_0016D698(-1, sp, &sp1034);
    AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, (u32) (spC - sp4) >> 4, sp4, 0x23);
    AddVifFlusha__4VIFS(arg0);
    AddVifMscal__4VIFSPv(arg0, 0x1AA0);
    AddVifFlusha__4VIFS(arg0);
    EndDmaCnt__4DMAS(arg0);
    *((((arg1 ^ 8) != 0) ? 0 : 4) + &g_2deb70) = 1;
}
}
