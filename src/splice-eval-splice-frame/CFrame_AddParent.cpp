// SPDX-License-Identifier: GPL-3.0-or-later
struct CFrame { int unk0; int unk4; int cparent; int aparent[1]; };
extern "C" void CFramePtr_Assign(int *);
extern "C" void CFrame_AddParent(CFrame *pframe)
{
    int index = pframe->cparent;
    pframe->cparent = index + 1;
    CFramePtr_Assign((int *)(index * 4 + (int)pframe + 12));
}
