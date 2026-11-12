// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "bis.h"

struct LO_13FB40;

/* What LoadSwObjectsFromBrx hands each new object to: slot 1 takes the objects (PLOARRAY's is AppendPloarray). */
class CPloSink {
public:
    virtual void Append(int cplo, LO_13FB40 **aplo);
};

/* The sink for the objects of a clone (vtable 0x2CBE38, slot 1 0x13FA30): a flag and the clone id. */
class CCloneSink : public CPloSink {
public:
    int grf;
    int cloneid;
    CCloneSink() { grf = -1; cloneid = -1; }
    virtual void Append(int cplo, LO_13FB40 **aplo);
};

/* LO's slot 14 (include/lo.h LoadFromBrx) takes the stream, which lo.h does not declare yet: a local view of the vtable. */
struct VTLO { u8 unknown_0x0[0x70]; s16 delta; s16 index; void (*pfnLoadFromBrx)(void *, CBinaryInputStream *); };
struct LO_13FB40 { u8 unknown_0x0[0xC]; VTLO *pvtlo; u8 unknown_0x10[0x40]; int field_0x50; };

struct SW_13FB40 { char pad[0x3F0C]; int pcnodeRoot; int iwlLoading; };

extern "C" {
int FIsCidDerivedFrom(int cid, int cidBase);
int MakeCloneId(int iwl, int n);
void *PcnodeFindOrAddClonePath(int pcnode, int c, int *acloneid);
LO_13FB40 *PloFindSwObject(SW_13FB40 *psw, int grffso, int oid, LO_13FB40 *ploContext, void *pcnodeContext);
LO_13FB40 *PloFindSwObject_thunk(SW_13FB40 *psw, int grffso, int oid, LO_13FB40 *ploContext);
LO_13FB40 *PloNew(int cid, LO_13FB40 *ploParent, int oid, int isplice);
int func_0013FAD0(int c, s16 *aid);
void func_001C9B08(SW_13FB40 *psw, LO_13FB40 *ploParent, int cid, int oid, int isplice, CBinaryInputStream *pbis, CPloSink *psink);
extern SW_13FB40 B_003DD490;

void LoadSwObjectsFromBrx(LO_13FB40 *ploParent, CBinaryInputStream *pbis, CPloSink *psinkParent)
{
    CCloneSink sinkClone;
    s16 aid[0x80];
    int c = pbis->S16Read();
    for (int i = 0; i < c; i++) {
        int kind = pbis->S8Read();
        switch (kind) {
        case -2:
        case -1:
        case 0:
            break;
        default:
            CBinaryInputStream_Read_thunk(pbis, kind * 2, aid);
            break;
        }
        CPloSink *psink = psinkParent;
        int cid = pbis->S16Read();
        int oid = pbis->S32Read();
        int isplice = pbis->S16Read();
        int cb = pbis->S32Read();
        switch (kind) {
        case -2:
        case -1: {
            int cloneid = MakeCloneId(B_003DD490.iwlLoading, -1);
            void *pcnode = PcnodeFindOrAddClonePath(B_003DD490.pcnodeRoot, 1, &cloneid);
            if (kind == -2) {
                if (PloFindSwObject_thunk(&B_003DD490, 0x405, oid, 0))
                    goto skip;
                sinkClone.grf = 1;
            } else {
                if (PloFindSwObject(&B_003DD490, 0x805, oid, 0, pcnode))
                    goto skip;
                sinkClone.grf = 0;
            }
            sinkClone.cloneid = cloneid;
            psink = &sinkClone;
        }
        case 0:
            break;
        default:
            if (func_0013FAD0(kind, aid))
                break;
            if (cid == 0x84 || cid == 0x85) {
                LO_13FB40 *plo = PloNew(cid, ploParent, oid, -1);
                plo->field_0x50 = 1;
                plo->pvtlo->pfnLoadFromBrx((char *)plo + plo->pvtlo->delta, pbis);
                if (psinkParent)
                    psinkParent->Append(1, &plo);
                continue;
            }
            goto skip;
        }
        if (FIsCidDerivedFrom(cid, 6)) {
            func_001C9B08(&B_003DD490, ploParent, cid, oid, isplice, pbis, psink);
        } else {
            LO_13FB40 *plo = PloNew(cid, ploParent, oid, isplice);
            plo->pvtlo->pfnLoadFromBrx((char *)plo + plo->pvtlo->delta, pbis);
            if (psink)
                psink->Append(1, &plo);
        }
        continue;
    skip:
        CBinaryInputStream_Skip(pbis, cb);
    }
}
}
