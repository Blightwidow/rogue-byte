// SPDX-License-Identifier: GPL-3.0-or-later
struct CRITSECT { int cEnter; int thread; int sema; };
extern "C" int GetThreadId();
extern "C" int WaitSema(int);
void EnterCritSect(CRITSECT *pcritsect)
{
    int thread = GetThreadId();
    if (thread != pcritsect->thread) {
        WaitSema(pcritsect->sema);
        pcritsect->thread = thread;
        pcritsect->cEnter = 1;
    } else {
        pcritsect->cEnter++;
    }
}
