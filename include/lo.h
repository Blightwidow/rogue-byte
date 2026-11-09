/* SPDX-License-Identifier: GPL-3.0-or-later */
/* BASIC and LO, the roots of the game's object classes (docs/ROADMAP.md "Next", item 1).

   Retail's class table (0x2BAAE8, config/recovered/class_diff.tsv) gives each class its parent, size and vtable: class 0
   (0x10 bytes) is the root, class 2 (0x50 bytes, 48 slots) is LO. g++ 2.95 puts the vtable pointer after the own fields of
   the first class that declares a virtual, and retail reads it at 0xC: so BASIC has 0xC bytes of fields and declares the
   first virtuals. Class 155, the other branch from the root, shares slots 1, 2, 4 and 5 with LO and overrides 3 and 6, so
   slots 1 to 6 are BASIC's. A vtable entry is 8 bytes (delta, index, function); slot n sits at 8 * n, after the type-info
   entry, so the virtuals are declared here in slot order and their order must not change.

   A virtual is named after the function retail puts in its slot (the base class's, then the first override with a name),
   without the class in the name; Slot<n> where none has a name yet. A signature is written only where a matched caller
   shows it; the others are `void ()` placeholders.

   A field is here when a matched function reads it at that offset, and no matched function reads the offset as another type.
   One reader is enough when it is a method of the class (its vtable holds it) or the class is otherwise certain; two are
   needed when the class of the object is only a guess from a local struct's name. The readers are listed. C++ only. */
#ifndef SLY2_LO_H
#define SLY2_LO_H
#ifndef __cplusplus
#error "lo.h declares C++ classes"
#endif
#include "types.h"

struct SO;

struct BASIC {
    u8 unknown_0x0[0xC];
    /* 0xC: the vtable pointer */
    virtual void OnAdd();               /*  1: OnLoAdd */
    virtual void Slot2();               /*  2: func_00132B08 */
    virtual void HandleSpliceEvent();   /*  3: HandleLoSpliceEvent (LO) */
    virtual void PostMessage();         /*  4: PostLoMessage */
    virtual void HandleMessage();       /*  5: HandleLoMessage */
    virtual void Slot6();               /*  6: func_00113A30 (LO), func_00113D10 (SO) */
};

struct LO : BASIC {
    virtual void Init();                /*  7: InitLo, InitSo */
    virtual void Slot8();
    virtual void Remove();              /*  9: RemoveLo; called without arguments (UpdateSo, InitFragile) */
    virtual void SetParent(struct LO *ploParent, void *pv, int grf); /* 10: SetLoParent, SetSoParent; func_001CD308 and
                                           Carry_Attach pass a pointer second */
    virtual void AddHierarchy();        /* 11: AddLoHierarchy, AddSoLoHierarchy */
    virtual void RemoveHierarchy();     /* 12: RemoveLoHierarchy */
    virtual void Slot13();              /* 13: func_001A5B80 */
    virtual void LoadFromBrx();         /* 14: LoadLoFromBrx, CSo_LoadFromBrx */
    virtual void PostLoad();            /* 15: PostLoLoad, PostSoLoad */
    virtual void Update();              /* 16: UpdateLo, UpdateSo */
    virtual void ProjectTransform();    /* 17: func_001A5E80, ProjectSoTransform */
    virtual void UpdateXfWorldHierarchy(); /* 18: func_0022FBD8, UpdateAloXfWorldHierarchy; called without arguments (TranslateSoToPos) */
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void RemoveAloHierarchy();  /* 22: RemoveAloHierarchy */
    virtual void Slot23();
    virtual void Slot24();
    virtual void SetCloneId();          /* 25: ALO_SetCloneId (SO) */
    virtual void Slot26(void *pv);      /* 26: func_001CB4E0, func_001CB518 (SO); func_001CB518 calls it on each child */
    virtual void Slot27(void *pv);      /* 27: func_001CB5C8, func_001CB5D0 (SO); func_001CB5D0 calls it on each child */
    virtual void CReturnZero();         /* 28: CReturnZeroLo */
    virtual void TranslateToPos(QW pos); /* 29: TranslateSoToPos (SO); func_001B0D90 passes a quadword */
    virtual void Slot30();
    virtual struct MATRIX4 *PmatWorld(); /* 31: LO_PmatWorld, PmatWorldSo; Carry_Attach copies four quadwords from it */
    virtual void *Slot32(void *pmat);   /* 32: func_001A6B30, func_001F3FB0; func_001CD308 passes a matrix buffer, keeps the result as an XF */
    virtual QW GetVelocityVec();        /* 33: GetSoVelocityVec (SO); MatchSoOtherObject, func_001F7950 keep the quadword */
    virtual QW Slot34();                /* 34: MatchSoOtherObject */
    virtual void Slot35(QW vec);        /* 35: MatchSoOtherObject passes slot 33's result */
    virtual void Slot36(QW vec);        /* 36: MatchSoOtherObject passes slot 34's result */
    virtual void Slot37();
    virtual void SetPosMatFromLo();     /* 38: SetLoPosMatFromLo */
    virtual void SetPosMatFromXf();     /* 39: SetLoPosMatFromXf */
    virtual void CloneVirtual();        /* 40: CloneLoVirtual */
    virtual void Slot41();
    virtual void Slot42();
    virtual void FReturnFalse();        /* 43: FReturnFalseLo */
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void SetGrfField();         /* 47: SetLoGrfField */
    virtual void ClearGrfField();       /* 48: ClearLoGrfField */

    /* 0x10 */ struct SO *psoParent;   /* InitSo, FFilterSensorSight (followed up to the root) */
    /* 0x14 */ s32 proot;              /* FFilterSensorSight (compared as an id), PoxaAllocSw (a list entry) */
    u8 unknown_0x18[0xC];
    /* 0x24 */ struct LO *ploNext;     /* the next child of the same parent: func_001CB518, func_001CB5D0, func_001F3CC8 */
    /* 0x28 */ u64 grfo;               /* RecalcSoLocked, func_001C4BD8, UpdateRip */
    u8 unknown_0x30[0x20];
};

/* Retail's layout, checked by the PS2 build: a field or a size that moves fails to compile. */
#if defined(__mips__)
#define SLY2_OFFSET_CHECK(type, field, offset) \
    typedef char check_##type##_##field[((unsigned int)&((type *)0)->field == (offset)) ? 1 : -1]
#define SLY2_SIZE_CHECK(type, size) typedef char check_##type##_size[(sizeof(type) == (size)) ? 1 : -1]
SLY2_SIZE_CHECK(BASIC, 0x10);
SLY2_SIZE_CHECK(LO, 0x50);
SLY2_OFFSET_CHECK(LO, psoParent, 0x10);
SLY2_OFFSET_CHECK(LO, proot, 0x14);
SLY2_OFFSET_CHECK(LO, ploNext, 0x24);
SLY2_OFFSET_CHECK(LO, grfo, 0x28);
#endif
#endif
