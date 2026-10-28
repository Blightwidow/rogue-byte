// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SAFEPOINT { QW a; QW b; };
struct SAFEPOINTLIST { void *pjt; int count; int pad[2]; SAFEPOINT items[1]; };
struct SW;
extern "C" char B_003DD490[];
extern "C" const float RO_002A66A0;
extern "C" int CploFindSwObjectsByClass(void *, int, int, int, int, void **);
extern "C" float ScoreSafePoint(SAFEPOINTLIST *, SAFEPOINT *, int, void **);
extern "C" QW PosLoWorld(void *);
struct JTV { char pad[0x240]; QW grab; };

extern "C" void FindBestSafePoint(SAFEPOINTLIST *list, SAFEPOINT *out)
{
    void *aplo[16];
    int cplo = CploFindSwObjectsByClass(B_003DD490, 0x505, 0x33, 0, 16, aplo);
    float best = RO_002A66A0;
    for (int index = 0; index < list->count; index++) {
        SAFEPOINT *point = &list->items[index];
        float score = ScoreSafePoint(list, point, cplo, aplo);
        if (score < best) {
            best = score;
            *out = *point;
            if (score == 0.0f)
                return;
        }
    }
    if (best == RO_002A66A0) {
        memset(out, 0, 0x20);
        QW pos = PosLoWorld(list->pjt);
        asm("qmtc2.ni %1, vf3\n\tlqc2 vf1, %0" : : "m" (((JTV *)list->pjt)->grab), "r" (pos));
        asm("vadd.xyzw vf2, vf3, vf1");
        asm("sqc2 vf2, %0" : "=m" (out->b));
    }
}
