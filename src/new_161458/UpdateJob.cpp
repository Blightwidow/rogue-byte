#include "sly2.h"
struct JOB { char pad0[0xB0]; int fB0; int fB4; void *pB8; void *pBC; int fC0; int fC4; int pad; int fCC; };
extern "C" void UpdateLo(JOB *);
extern "C" int FBlotLabelPlaying(void *, int);
extern "C" void PublishJobEnd(JOB *);
extern "C" void SetJobEndSequence(JOB *, int);
extern "C" void AdvanceAfterJobEnd(JOB *);
extern "C" void UpdateJob(JOB *pjob)
{
    UpdateLo(pjob);
    switch (pjob->fC4) {
    case 1:
        if (FBlotLabelPlaying(pjob->pB8, pjob->fB0) == 0) {
            PublishJobEnd(pjob);
            if (pjob->fC0 != 0 || pjob->fCC != 0)
                SetJobEndSequence(pjob, 3);
            else
                SetJobEndSequence(pjob, 2);
        }
        break;
    case 2:
        if (FBlotLabelPlaying(pjob->pB8, pjob->fB4) == 0) {
            AdvanceAfterJobEnd(pjob);
            SetJobEndSequence(pjob, 0);
        }
        break;
    case 3:
        if (FBlotLabelPlaying(pjob->pBC, 0x30f) == 0)
            AdvanceAfterJobEnd(pjob);
        break;
    }
}
