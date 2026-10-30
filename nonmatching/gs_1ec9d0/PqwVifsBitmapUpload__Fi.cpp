typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PqwVifsBitmapUpload__Fi {
    /* 0x000 */ char pad0[0xC];
    /* 0x00C */ s8 *spC;                          /* inferred */
    /* 0x010 */ char pad10[0x20];                   /* maybe part of spC[9]? */
    /* 0x030 */ M2C_UNK sp30;                       /* inferred */
    /* 0x030 */ char pad30[0x30];
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0x10];
    /* 0x070 */ M2C_UNK sp70;                       /* inferred */
    /* 0x070 */ char pad70[0xA0];
    /* 0x110 */ s32 sp110;                          /* inferred */
    /* 0x114 */ s32 sp114;                          /* inferred */
    /* 0x118 */ s32 sp118;                          /* inferred */
    /* 0x11C */ s32 sp11C;                          /* inferred */
    /* 0x120 */ char pad120[0xA0];
};                                                  /* size = 0x1C0 */
#define spC (*(s8 * *)(sp + 0x00C))
M2C_UNK AddDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddDmaRet__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddPrimEnd__4GIFS(s8 *);                  /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(s8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifDirectRefs__4VIFSiP2QWi(M2C_UNK *, s32, s32, M2C_UNK); /* extern */
M2C_UNK AddVifDirect__4VIFSiP2QWi(M2C_UNK *, s32, s32, M2C_UNK); /* extern */
M2C_UNK AddVifFlush__4VIFS(M2C_UNK *);              /* extern */
M2C_UNK AllocStack__4DMASi(M2C_UNK *, s32, s32, M2C_UNK); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(s8 *, M2C_UNK, M2C_UNK *); /* extern */
s32 AllocZpr(s8 *, u16);                          /* extern */
M2C_UNK BuildBmpGifs__FP3BMPiP4GIFS(s8 *, s32, s8 *); /* extern */
M2C_UNK BuildBmpTex0__FP3BMPi(s8 *, s32);         /* extern */
M2C_UNK BuildClutGifs__FP4CLUTiP4GIFS(s8 *, s32, s8 *); /* extern */
M2C_UNK BuildClutTex2__FP4CLUTi(s8 *, s32);       /* extern */
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK DMAS_DetachCopyPermanent(M2C_UNK *, M2C_UNK, M2C_UNK, s32 *); /* extern */
M2C_UNK Detach__4DMASPiPP2QW(s8 *, s32 *, s32 *); /* extern */
M2C_UNK EndDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK PackAD__4GIFSll(s8 *, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK Reset__4DMAS(s8 *);                       /* extern */
M2C_UNK __4GIFS(s8 *);                            /* extern */
M2C_UNK __4VIFS(M2C_UNK *);                         /* extern */
extern s32 B_003DCF98;
extern s32 B_003DCF9C;
extern s32 B_003DCFF0;
extern s32 B_003DCFF4;
extern s32 B_003DCFF8;
extern s32 B_003DCFFC;
s32 PqwVifsBitmapUpload__Fi(s8 *arg0, s32 arg1) {
    s8 sp[0x100] __attribute__((aligned(16)));
    M2C_UNK sp30;
    M2C_UNK sp60;
    M2C_UNK sp70;
    s32 sp110;
    s32 sp114;
    s32 sp118;
    s32 sp11C;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s4;
    s8 *temp_s1;
    s8 *temp_s1_2;
    var_s2 = 0;
    __4GIFS(sp);
    sp118 = 0;
    __4VIFS(&sp30);
    sp11C = M2C_FIELD(arg0, s32 *, 4);
    CStackFrame_Construct(&sp60);
    AllocStack__4DMASi(&sp30, (((B_003DCF9C * 3) + B_003DCF98) * 0xA) + 4, B_003DCF9C, 0xA);
    AddDmaCnt__4DMAS(&sp30);
    AddVifFlush__4VIFS(&sp30);
    if (B_003DCFF8 > 0) {
        temp_v0 = B_003DCFFC;
        do {
            temp_s1 = (s8 *)(temp_v0 + (var_s2 << 5));
            if (M2C_FIELD(temp_s1, u8 *, 4) == arg1) {
                Reset__4DMAS(sp);
                AllocStatic__4DMASiP2QW(sp, 0xA, &sp70);
                temp_v0_2 = AllocZpr(arg0, M2C_FIELD(temp_s1, u16 *, 0xA));
                BuildClutTex2__FP4CLUTi(temp_s1, temp_v0_2);
                BuildClutGifs__FP4CLUTiP4GIFS(temp_s1, temp_v0_2, sp);
                M2C_FIELD(spC, s64 *, -0x10) = (s64) (M2C_FIELD(spC, s64 *, -0x10) | 0x8000);
                Detach__4DMASPiPP2QW(sp, &sp110, &sp114);
                AddVifDirect__4VIFSiP2QWi(&sp30, sp110, sp114, 0);
                AddVifDirectRefs__4VIFSiP2QWi(&sp30, M2C_FIELD(temp_s1, s32 *, 0x10), M2C_FIELD(temp_s1, s32 *, 0xC), 0);
            }
            var_s2 += 1;
        } while (var_s2 < B_003DCFF8);
    }
    var_s2_2 = 0;
    if (B_003DCFF0 > 0) {
        var_s4 = 0;
        do {
            temp_s1_2 = (s8 *)(B_003DCFF4 + var_s4);
            if (arg1 == M2C_FIELD(temp_s1_2, u8 *, 4)) {
                Reset__4DMAS(sp);
                AllocStatic__4DMASiP2QW(sp, 0xA, &sp70);
                temp_v0_3 = AllocZpr(arg0, M2C_FIELD(temp_s1_2, u16 *, 0xE));
                BuildBmpTex0__FP3BMPi(temp_s1_2, temp_v0_3);
                BuildBmpGifs__FP3BMPiP4GIFS(temp_s1_2, temp_v0_3, sp);
                M2C_FIELD(spC, s64 *, -0x10) = (s64) (M2C_FIELD(spC, s64 *, -0x10) | 0x8000);
                Detach__4DMASPiPP2QW(sp, &sp110, &sp114);
                AddVifDirect__4VIFSiP2QWi(&sp30, sp110, sp114, 0);
                AddVifDirectRefs__4VIFSiP2QWi(&sp30, M2C_FIELD(temp_s1_2, s32 *, 0x18), M2C_FIELD(temp_s1_2, s32 *, 0x14), 0);
            }
            var_s2_2 += 1;
            var_s4 += 0x28;
        } while (var_s2_2 < B_003DCFF0);
    }
    if (sp11C < M2C_FIELD(arg0, s32 *, 4)) {
        Reset__4DMAS(sp);
        AllocStatic__4DMASiP2QW(sp, 0xA, &sp70);
        AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
        PackAD__4GIFSll(sp, 0x3F, 0);
        AddPrimEnd__4GIFS(sp);
        Detach__4DMASPiPP2QW(sp, &sp110, &sp114);
        AddVifDirect__4VIFSiP2QWi(&sp30, sp110, sp114, 0);
        AddVifFlush__4VIFS(&sp30);
        EndDmaCnt__4DMAS(&sp30);
        AddDmaRet__4DMAS(&sp30);
        DMAS_DetachCopyPermanent(&sp30, 0, 0, &sp118);
    }
    CStackFrame_Destructor(&sp60, 2);
    return sp118;
}
}
