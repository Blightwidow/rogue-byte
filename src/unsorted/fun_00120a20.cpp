// SPDX-License-Identifier: GPL-3.0-or-later
// Returns its CRef by value (hidden result pointer in $a0, returned in $v0), as the RefOp* functions of splice-bif do.
struct CFrame;
struct CRef
{
    int tagk;
    int n;
    CRef(int tagkNew, int nNew) { tagk = tagkNew; n = nNew; }
    ~CRef();
};
extern "C" CRef func_00120A20(int carg, CRef *aref, CFrame *pframe)
{
    return CRef(0x17, aref->tagk == 0x20 || aref->tagk == 0x19);
}
