#include "sly2.h"
#include "vu0inline.h"

struct JT;
struct ACTADJ;
struct CRV {
    u8 unknown_0x0[0xE4];
    /* 0xE4 */ s32 fLoop;
};
struct JTRAIL {
    u8 unknown_0x0[0x4D4];
    /* 0x4D4 */ CRV *pcrv;
    u8 unknown_0x4D8[0x8];
    /* 0x4E0 */ f32 s;
    /* 0x4E4 */ s32 fReverse;
};
struct XMG {
    u8 unknown_0x0[0x4];
    /* 0x04 */ s32 fRail;
    /* 0x08 */ f32 radius;
    u8 unknown_0xC[0x4];
    union {
        /* 0x10 */ QW posA;
        /* 0x10 */ f32 ds;
    };
    /* 0x20 */ QW posB;
};
struct LSG {
    u8 unknown_0x0[0x10];
    /* 0x10 */ QW posClip;
    u8 unknown_0x20[0x40];
};

extern "C" {
extern QW g_2a2dd0;
void SetActadjOffset(ACTADJ *, QW);
f32 SMinCrv(CRV *);
f32 SMaxCrv(CRV *);
f32 GModPositive__Fff(f32, f32);
void GetPathPosFromS(CRV *, f32, QW *, int);
QW ConvertAloPos(int, JT *, QW);
int ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(QW, f32, QW, QW, int, LSG *);
}

void MatchJtXmgRail__FP2JTP3XMGP6ACTADJ(JT *pjt, XMG *pxmg, ACTADJ *pactadj)
{
    if (pxmg->fRail == 0) {
        SetActadjOffset(pactadj, g_2a2dd0);
        return;
    }
    JTRAIL *prail = (JTRAIL *)pjt;
    CRV *pcrv = prail->pcrv;
    f32 ds = pxmg->ds;
    if (prail->fReverse != 0)
        ds = -ds;
    f32 sMin = SMinCrv(pcrv);
    f32 sMax = SMaxCrv(pcrv);
    f32 s;
    if (pcrv->fLoop != 0) {
        s = GModPositive__Fff(prail->s + ds, sMax);
    } else {
        s = prail->s + ds;
        if (s < sMin)
            s = sMin;
        else if (sMax < s)
            s = sMax;
    }
    union { QW qw; VECTOR vec; } pos;
    LSG lsg;
    GetPathPosFromS(pcrv, s, &pos.qw, 0);
    pos.qw = ConvertAloPos(0, pjt, pos.qw);
    if (ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(pxmg->posB, pxmg->radius, pxmg->posA, pos.qw, 1, &lsg) > 0)
        SetActadjOffset(pactadj, VectorSub(lsg.posClip, pxmg->posA));
}
