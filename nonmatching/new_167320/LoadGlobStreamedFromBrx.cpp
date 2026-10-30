typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadGlobStreamedFromBrx {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x30];
    /* 0x040 */ M2C_UNK sp40;                       /* inferred */
    /* 0x040 */ char pad40[0x10];
    /* 0x050 */ s32 sp50;                           /* inferred */
    /* 0x054 */ char pad54[0xC];                    /* maybe part of sp50[4]? */
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[4];
    /* 0x064 */ u16 *sp64;                          /* inferred */
    /* 0x068 */ M2C_UNK sp68;                       /* inferred */
    /* 0x068 */ char pad68[4];
    /* 0x06C */ s8 *sp6C;                         /* inferred */
    /* 0x070 */ s8 *sp70;                         /* inferred */
    /* 0x074 */ s32 sp74;                           /* inferred */
    /* 0x078 */ s32 sp78;                           /* inferred */
    /* 0x07C */ s32 sp7C;                           /* inferred */
    /* 0x080 */ s32 sp80;                           /* inferred */
    /* 0x084 */ M2C_UNK *sp84;                      /* inferred */
    /* 0x088 */ M2C_UNK *sp88;                      /* inferred */
    /* 0x08C */ s8 *sp8C;                         /* inferred */
    /* 0x090 */ s8 *sp90;                         /* inferred */
    /* 0x094 */ char pad94[0xAC];
};                                                  /* size = 0x140 */
M2C_UNK AddDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddDmaRet__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddVifMscal__4VIFSPv(M2C_UNK *, M2C_UNK);   /* extern */
M2C_UNK AddVifStcycl__4VIFSii(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddVifStmask__4VIFSUi(M2C_UNK *, s32);      /* extern */
M2C_UNK AddVifStrow__4VIFSP2QW(M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK AllocStack__4DMASi(M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK DMAS_DetachCopyPermanent(M2C_UNK *, s8 *, M2C_UNK *, s8 *); /* extern */
M2C_UNK EndDmaCnt__4DMAS(M2C_UNK *);                /* extern */
s8 *PshdFromIndex(s32);                           /* extern */
s32 PvAllocSwClearImpl__Fi(s32 *, s32 *, M2C_UNK);  /* extern */
s32 S16Read__18CBinaryInputStream(s32);             /* extern */
s32 S32Read__18CBinaryInputStream(s32);             /* extern */
s32 U16Read__18CBinaryInputStream(s32);             /* extern */
s8 U8Read__18CBinaryInputStream(s32);               /* extern */
M2C_UNK UnpackHelper__4VIFS3UPKiiPiPPUi(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u16 **); /* extern */
M2C_UNK VIFS_AddVifUnpackFromStream(M2C_UNK *, s32, s8, s32, u16); /* extern */
M2C_UNK __4VIFS(M2C_UNK *);                         /* extern */
M2C_UNK func_001699E8(s8 *, s8 *, s8 *, s32, s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_001EC688(s8 *, s32, u16, M2C_UNK *);     /* extern */
M2C_UNK memset(u16 *, M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK B_002DEB60;
extern M2C_UNK D_002BE540;
extern M2C_UNK D_002BE558;
void LoadGlobStreamedFromBrx(s8 *arg0, s8 *arg1, s8 *arg2, s32 arg4, s32 arg5, s32 arg6) {
    M2C_UNK sp10;
    M2C_UNK sp40;
    s32 sp50;
    M2C_UNK sp60;
    u16 *sp64;
    M2C_UNK sp68;
    s8 *sp6C;
    s8 *sp70;
    s32 sp74;
    s32 sp78;
    s32 sp7C;
    s32 sp80;
    M2C_UNK *sp84;
    M2C_UNK *sp88;
    s8 *sp8C;
    s8 *sp90;
    s16 temp_s2_2;
    s16 temp_s2_3;
    s32 temp_a0;
    s32 temp_s1;
    s32 temp_s3;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;
    s32 var_s2_2;
    s8 temp_s5;
    s8 temp_v0;
    s8 temp_v0_5;
    s8 temp_v0_6;
    u16 *temp_a1;
    u16 temp_s2;
    u16 var_v0;
    s8 *temp_s0;
    s8 *temp_v0_3;
    var_s2 = 0;
    sp6C = arg0;
    sp70 = arg2;
    sp74 = arg4;
    sp78 = arg5;
    M2C_FIELD(arg0, s64 *, 0x50) = (s64) (M2C_FIELD(arg0, s64 *, 0x50) | (0x8000 << 0x12));
    __4VIFS(&sp10);
    CStackFrame_Construct(&sp40);
    AllocStack__4DMASi(&sp10, 0x2000);
    AddDmaCnt__4DMAS(&sp10);
    temp_v0 = U8Read__18CBinaryInputStream(arg6);
    M2C_FIELD(arg1, s8 *, 1) = temp_v0;
    sp50 = temp_v0 * 0x50;
    M2C_FIELD(&sp50, s32 *, 4) = 0x10;
    temp_v0_2 = PvAllocSwClearImpl__Fi(&sp50, &sp50, 0x10);
    sp88 = &sp68;
    M2C_FIELD(sp70, s32 *, 0x18) = temp_v0_2;
    var_s1 = 0;
    if (M2C_FIELD(arg1, s8 *, 1) > 0) {
        do {
            var_s2 += 1;
            temp_s0 = (s8 *)(M2C_FIELD(sp70, s32 *, 0x18) + var_s1);
            var_s1 += 0x50;
            M2C_FIELD(temp_s0, s32 *, 0) = S32Read__18CBinaryInputStream(arg6);
            M2C_FIELD(temp_s0, s32 *, 8) = S16Read__18CBinaryInputStream(arg6);
        } while (var_s2 < M2C_FIELD(arg1, s8 *, 1));
    }
    sp7C = 0x1B;
    if (M2C_FIELD(arg1, s8 *, 1) != 0) {
        M2C_FIELD(arg1, s32 *, 0xC) = 0x1B;
        sp7C = (M2C_FIELD(arg1, s8 *, 1) * 4) + 0x1B;
    }
    var_s1_2 = 0;
    sp80 = S16Read__18CBinaryInputStream(arg6);
    sp8C = arg1 + 0x10;
    sp90 = sp70 + 0x10;
    if (sp80 > 0) {
        sp84 = &sp60;
        do {
            CStackFrame_Construct(&sp60);
            UnpackHelper__4VIFS3UPKiiPiPPUi(&sp10, 0xD, 4, 0xA, 0, &sp64);
            memset(sp64, 0, 0x20);
            switch (var_s1_2) {                     /* irregular */
            case 0:
                M2C_FIELD(sp64, u16 *, 0) |= 1;
                if (sp80 == 1) {
                    var_v0 = M2C_FIELD(sp64, u16 *, 0) | 8;
block_14:
                    M2C_FIELD(sp64, u16 *, 0) = var_v0;
                }
                break;
            case 1:
                var_v0 = M2C_FIELD(sp64, u16 *, 0) | 2;
                goto block_14;
            }
            if (M2C_FIELD(arg1, s8 *, 1) != 0) {
                M2C_FIELD(sp64, u16 *, 0) |= 4;
            }
            var_s2_2 = sp7C;
            var_s0 = 0;
            M2C_FIELD(sp64, s16 *, 2) = (s16) var_s2_2;
            temp_v0_3 = PshdFromIndex(U16Read__18CBinaryInputStream(arg6));
            if (M2C_FIELD(temp_v0_3, s32 *, 0x1C) > 0) {
                do {
                    M2C_FIELD(&sp64[var_s0], s16 *, 0x14) = (s16) var_s2_2;
                    temp_v0_4 = func_001EC688(temp_v0_3, var_s0, (u16) var_s2_2, &sp10);
                    var_s0 += 1;
                    var_s2_2 += temp_v0_4;
                } while (var_s0 < M2C_FIELD(temp_v0_3, s32 *, 0x1C));
            }
            temp_s5 = U8Read__18CBinaryInputStream(arg6);
            AddVifStcycl__4VIFSii(&sp10, 1, 2);
            VIFS_AddVifUnpackFromStream(&sp10, 8, temp_s5, arg6, var_s2_2 + 1);
            M2C_FIELD(sp64, u16 *, 8) = (u16) var_s2_2;
            temp_s2 = var_s2_2 + (temp_s5 * 2);
            M2C_FIELD(sp64, u16 *, 0xA) = temp_s2;
            if (M2C_FIELD(arg1, s8 *, 1) != 0) {
                var_s0_2 = 0;
                temp_v0_5 = U8Read__18CBinaryInputStream(arg6);
                if (temp_v0_5 > 0) {
                    do {
                        temp_a1 = &sp64[var_s0_2];
                        var_s0_2 += 1;
                        M2C_FIELD(temp_a1, s16 *, 0x18) = (s16) ((u16) M2C_FIELD(arg1, s32 *, 0xC) + (U8Read__18CBinaryInputStream(arg6) * 4));
                    } while (var_s0_2 < temp_v0_5);
                }
                temp_s3 = temp_v0_5 * 4;
                temp_s1 = temp_v0_5 < 4;
                if (var_s0_2 < 4) {
                    do {
                        temp_a0 = var_s0_2 * 2;
                        var_s0_2 += 1;
                        M2C_FIELD((sp64 + temp_a0), u16 *, 0x18) = (u16) M2C_FIELD(sp64, u16 *, 0x18);
                    } while (var_s0_2 < 4);
                }
                if (temp_s1 != 0) {
                    AddVifStrow__4VIFSP2QW(&sp10, &B_002DEB60);
                    AddVifStmask__4VIFSUi(&sp10, *(temp_s3 + &D_002BE540));
                }
                VIFS_AddVifUnpackFromStream(&sp10, *(temp_s3 + &D_002BE558), temp_s5, arg6, M2C_FIELD(sp64, u16 *, 8));
                if (temp_s1 != 0) {
                    AddVifStmask__4VIFSUi(&sp10, 0);
                }
            }
            var_s1_2 += 1;
            AddVifStcycl__4VIFSii(&sp10, 1, 1);
            temp_v0_6 = U8Read__18CBinaryInputStream(arg6);
            VIFS_AddVifUnpackFromStream(&sp10, 0xE, temp_v0_6, arg6, temp_s2);
            M2C_FIELD(sp64, u16 *, 0xC) = temp_s2;
            temp_s2_2 = temp_s2 + temp_v0_6;
            M2C_FIELD(sp64, s16 *, 0xE) = temp_s2_2;
            temp_s2_3 = temp_s2_2 + 1;
            M2C_FIELD(sp64, s16 *, 0x10) = temp_s2_3;
            M2C_FIELD(sp64, s16 *, 0x12) = temp_s2_3;
            AddVifMscal__4VIFSPv(&sp10, 0);
            AddVifMscal__4VIFSPv(&sp10, 0x1910);
            AddVifMscal__4VIFSPv(&sp10, 0x1A68);
            CStackFrame_Destructor(sp84, 2);
        } while (var_s1_2 < sp80);
    }
    EndDmaCnt__4DMAS(&sp10);
    AddDmaRet__4DMAS(&sp10);
    DMAS_DetachCopyPermanent(&sp10, sp8C, sp88, sp90);
    func_001699E8(sp6C, arg1, sp70, sp74, sp78, 0, 0, 0, arg6);
    CStackFrame_Destructor(&sp40, 2);
}
}
