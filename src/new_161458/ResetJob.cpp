// SPDX-License-Identifier: GPL-3.0-or-later
struct TASK_162940 { char pad[0x64]; int state; char pad2[0x84 - 0x68]; TASK_162940 *ptaskNext; };
struct JOB_162940 { char pad[0x7C]; int state; TASK_162940 *ptaskFirst; };
extern "C" void SaveTaskVariables(TASK_162940 *);
extern "C" void SaveJobVariables(JOB_162940 *);
extern "C" void ResetJob(JOB_162940 *pjob)
{
    for (TASK_162940 *ptask = pjob->ptaskFirst; ptask != 0; ptask = ptask->ptaskNext) {
        ptask->state = 0;
        SaveTaskVariables(ptask);
    }
    pjob->state = 0;
    SaveJobVariables(pjob);
}
