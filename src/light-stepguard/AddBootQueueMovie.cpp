// SPDX-License-Identifier: GPL-3.0-or-later
struct MOVIE { int unk0; int id; char pad[0x34]; int idLast; };
struct ENTRY { int unk0; MOVIE *pmovie; };
extern "C" ENTRY *PentryAddBootQueue(void *pbq, int type);
extern "C" void AddBootQueueMovie(void *pbq, MOVIE *pmovie)
{
    int f; if (pmovie == 0) f = 0; else f = pmovie->id != pmovie->idLast;
    if (f)
        PentryAddBootQueue(pbq, 0)->pmovie = pmovie;
}
