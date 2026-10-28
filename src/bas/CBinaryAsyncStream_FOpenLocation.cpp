// SPDX-License-Identifier: GPL-3.0-or-later
struct CBinaryAsyncStream { int FOpenSector(unsigned int, unsigned int); };
struct LOCATION { unsigned int isector; unsigned int cb; int kind; };
extern "C" int CBinaryAsyncStream_FOpenLocation(CBinaryAsyncStream *pstream, LOCATION *ploc)
{
    int fOpened = 0;
    if (ploc->kind == 2)
        fOpened = pstream->FOpenSector(ploc->isector, ploc->cb);
    return fOpened;
}
