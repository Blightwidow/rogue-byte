// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; float *pv; };
struct CPair;
struct PairHandle {
    CPair *p;
    int pad[3];
    PairHandle(CPair *) asm("PairHandle_Init");
    inline ~PairHandle();
    PairHandle &operator=(CPair *) asm("PairHandle_Assign");
};
struct CPair { int cref; int pad4; CRef ref; PairHandle next; };
struct SLOTHEAP;
struct CBinaryInputStream;
extern "C" {
CPair *PpairNew(void);
void CRef_Destruct(CRef *);
void CPairPtr_Destructor(PairHandle *, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
extern SLOTHEAP B_004520A8;
extern int B_003E1C34;
unsigned int U8Read__18CBinaryInputStream(CBinaryInputStream *);
int S16Read__18CBinaryInputStream(CBinaryInputStream *);
int S32Read__18CBinaryInputStream(CBinaryInputStream *);
unsigned int U32Read__18CBinaryInputStream(CBinaryInputStream *);
float F32Read__18CBinaryInputStream(CBinaryInputStream *);
void SetTag__4CRef4TAGK(CRef *, int);
void CRef_SetS32(CRef *, int);
void CRef_SetF32(CRef *, float);
void CRef_SetBool(CRef *, int);
void CRef_SetBasic(CRef *, unsigned int);
void CRef_SetSymid(CRef *, unsigned int);
void CRef_SetBifk(CRef *, unsigned int);
void bevy_splice_value_list_ref(CRef *, CPair *);
}
static inline void ReleasePair(CPair *ppair)
{
    if (ppair) {
        if (--ppair->cref == 0) {
            CPairPtr_Destructor(&ppair->next, 2);
            CRef_Destruct(&ppair->ref);
            UnlinkPairNode(ppair);
            FreeSlotheapPv(&B_004520A8, ppair);
        }
    }
}

PairHandle::~PairHandle() { ReleasePair(p); }

extern "C" PairHandle PpairSerializeIn(CBinaryInputStream *pbis)
{
    unsigned int code = U8Read__18CBinaryInputStream(pbis);
    if (code == 0xFF) {
        return PairHandle(0);
    }
    PairHandle h(PpairNew());
    if (B_003E1C34 != 0) {
        S32Read__18CBinaryInputStream(pbis);
        S16Read__18CBinaryInputStream(pbis);
        S16Read__18CBinaryInputStream(pbis);
        S16Read__18CBinaryInputStream(pbis);
        S16Read__18CBinaryInputStream(pbis);
        S16Read__18CBinaryInputStream(pbis);
        S16Read__18CBinaryInputStream(pbis);
    }
    CPair *ppairNew = h.p;
    int tagk = code & 0x7F;
    unsigned char fNext = code >> 7;
    CRef *pref = &ppairNew->ref;
    int i;
    switch (tagk) {
    case 0: case 1: case 2: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14:
    case 15: case 16: case 17: case 18: case 20:
        CRef_Destruct(pref);
        SetTag__4CRef4TAGK(pref, tagk);
        break;
    case 21:
        CRef_SetS32(pref, S32Read__18CBinaryInputStream(pbis));
        break;
    case 22:
        CRef_SetF32(pref, F32Read__18CBinaryInputStream(pbis));
        break;
    case 23:
        CRef_SetBool(pref, U32Read__18CBinaryInputStream(pbis) != 0);
        break;
    case 33:
        CRef_SetBasic(pref, U32Read__18CBinaryInputStream(pbis));
        break;
    case 24:
        CRef_SetSymid(pref, U32Read__18CBinaryInputStream(pbis));
        break;
    case 25:
        CRef_SetBifk(pref, U32Read__18CBinaryInputStream(pbis));
        break;
    case 26:
        CRef_Destruct(pref);
        SetTag__4CRef4TAGK(pref, 0x1A);
        for (i = 0; i < 3; i++) {
            float *pv = &pref->pv[i];
            *pv = F32Read__18CBinaryInputStream(pbis);
        }
        break;
    case 27:
        CRef_Destruct(pref);
        SetTag__4CRef4TAGK(pref, 0x1B);
        for (i = 0; i < 16; i++)
        {
            float *pv = pref->pv;
            float value = F32Read__18CBinaryInputStream(pbis);
            pv += i;
            *pv = value;
        }
        break;
    case 28:
        CRef_Destruct(pref);
        SetTag__4CRef4TAGK(pref, 0x1C);
        for (i = 0; i < 3; i++)
        {
            float *pv = pref->pv;
            float value = F32Read__18CBinaryInputStream(pbis);
            pv += i;
            *pv = value;
        }
        break;
    case 29:
        CRef_Destruct(pref);
        SetTag__4CRef4TAGK(pref, 0x1D);
        for (i = 0; i < 2; i++)
        {
            float *pv = pref->pv;
            float value = F32Read__18CBinaryInputStream(pbis);
            pv += i;
            *pv = value;
        }
        break;
    case 30:
        CRef_Destruct(pref);
        SetTag__4CRef4TAGK(pref, 0x1E);
        for (i = 0; i < 3; i++)
        {
            float *pv = pref->pv;
            float value = F32Read__18CBinaryInputStream(pbis);
            pv += i;
            *pv = value;
        }
        break;
    case 31:
        bevy_splice_value_list_ref(pref, PpairSerializeIn(pbis).p);
        break;
    }
    if (fNext) {
        CPair *ppair = h.p;
        ppair->next = PpairSerializeIn(pbis).p;
    }
    return PairHandle(h.p);
}
