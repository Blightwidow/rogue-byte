// SPDX-License-Identifier: GPL-3.0-or-later
struct TASK_2036E8;
struct RECON_2036E8 { char pad[0xEC]; TASK_2036E8 *ptask; int fDone; };
extern int B_003DD490;
extern "C" void RequestTaskState(TASK_2036E8 *, int, RECON_2036E8 *);
extern "C" char *PpoSwFocusBase(int *);
extern "C" int FIsBasicDerivedFrom(char *, int);
extern "C" void func_0019D948(char *);
extern "C" void SetReconTargetDone(RECON_2036E8 *precon, int fDone)
{
    if (precon->ptask != 0) {
        RequestTaskState(precon->ptask, 2, precon);
        char *ppo = PpoSwFocusBase(&B_003DD490);
        if (ppo != 0 && FIsBasicDerivedFrom(ppo, 0x34))
            func_0019D948(ppo + 0xF24);
    } else {
        precon->fDone = fDone;
    }
}
