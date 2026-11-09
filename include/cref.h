/* SPDX-License-Identifier: GPL-3.0-or-later */
/* CRef, a value of the Splice script language: a tag and a payload, 8 bytes (docs/ROADMAP.md "Next", item 1).

   Names from the Sly 1 decompilation (source: sly1 include/splice/ref.h, CC0; THIRD_PARTY_NOTICES.md). The size is Sly 2's
   own: func_001239D8 reads aref[1].m_tag at 0xC, so an array of CRef steps by 8. The 16-byte local copies that 300 matched
   bindings used were frame scaffolding: 244 of them match as real C++ with this CRef (docs/ROADMAP.md item 1).

   Sly 2's tags are not Sly 1's values: each one below is the constant that Sly 2's setter of that kind writes (CRef_SetS32
   0x15, CRef_SetF32 0x16, CRef_SetBool 0x17, CRef_SetSymid 0x18, CRef_SetBifk 0x19, CRef_SetVector 0x1A, CRef_SetMatrixPtr
   0x1B, CRef_SetClqPtr 0x1C, CRef_SetLmPtr 0x1D, CRef_SetSmpPtr 0x1E, CRef_ConstructPair 0x1F, CRef_SetProc 0x20,
   CRef_SetBasic 0x21, CRef_SetMethod 0x22). 0x24 is what the bindings of functions with no result return (Void); 0x23 is a
   kind CRef's operator== knows but no setter names yet. C and C++. */
#ifndef SLY2_CREF_H
#define SLY2_CREF_H
#include "sly2.h"

enum TAGK {
    TAGK_S32 = 0x15,
    TAGK_F32 = 0x16,
    TAGK_Bool = 0x17,
    TAGK_Symid = 0x18,
    TAGK_Bifk = 0x19,
    TAGK_Vector = 0x1A,
    TAGK_Matrix = 0x1B,
    TAGK_Clq = 0x1C,
    TAGK_Lm = 0x1D,
    TAGK_Smp = 0x1E,
    TAGK_Pair = 0x1F,
    TAGK_Proc = 0x20,
    TAGK_Basic = 0x21,
    TAGK_Method = 0x22,
    TAGK_Void = 0x24
};

struct CPair;
struct CProc;
struct CLQ;
struct LM;
struct SMP;
struct BASIC;
struct CMethod;

union TAG {
    s32 m_n;
    f32 m_g;
    s32 m_bool;
    u32 m_symid;
    s32 m_bifk;
    struct CPair *m_ppair;
    struct CProc *m_pproc;
    struct VECTOR *m_pvector;
    struct MATRIX4 *m_pmatrix;
    struct CLQ *m_pclq;
    struct LM *m_plm;
    struct SMP *m_psmp;
    struct BASIC *m_pbasic;
    struct CMethod *m_pmethod;
};

#ifdef __cplusplus
/* The special members as retail shows them in the Splice bindings: a default constructor that does nothing (no call), an
   out-of-line copy constructor (0x1291A8: copies the two words and calls Incref) used to return a CRef by value, and an inline
   destructor that calls Decref (0x129EC8) with `this` alone; an out-of-line destructor would also pass g++'s in-charge flag,
   which retail's calls lack. */
struct CRef {
    TAGK m_tagk;
    TAG m_tag;
    CRef() {}
    CRef(const CRef &ref);
    ~CRef() { Decref(); }
    CRef &operator=(const CRef &ref);
    int operator==(const CRef &ref);
    void Incref();
    void Decref();
    void SetTag(TAGK tagk);
    void SetS32(int n);
    void SetBool(int fBool);
    void SetBasic(struct BASIC *pbasic);
};
#else
struct CRef {
    enum TAGK m_tagk;
    union TAG m_tag;
};
#endif
typedef struct CRef CRef;

#if defined(__mips__)
typedef char check_CRef_size[(sizeof(struct CRef) == 8) ? 1 : -1];
#endif
#endif
