#include "sly2.h"
struct JOB { char pad[0x54]; int jobs; };
struct TARGET { char pad0[0xEC]; JOB *pjob; char pad1[0x08]; int idList; };
struct RECON { char pad[0x30]; int ctarget; TARGET *aptarget[16]; int clist; TARGET *aptargetList[5]; };
extern "C" void bevy_ui_binoc_recon_202030(RECON *precon)
{
    precon->clist = 0;
    for (int itarget = 0; itarget < precon->ctarget; ++itarget) {
        TARGET *ptarget = precon->aptarget[itarget];
        if (ptarget->idList == -1)
            continue;
        JOB *pjob = ptarget->pjob;
        if (pjob != 0) {
            int jobs = pjob->jobs;
            if (jobs != 1) {
                if (jobs != 2)
                    continue;
            }
        }
        unsigned count = precon->clist;
        if (count < 5) {
            precon->aptargetList[count] = ptarget;
            precon->clist = count + 1;
        }
    }
}
