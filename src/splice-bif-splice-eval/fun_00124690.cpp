/* SPDX-License-Identifier: GPL-3.0-or-later */
struct CRef_124690 { int tag; int value; int pad[2]; };
struct BASIC_124690;
extern "C" void CRef_CopyConstruct(CRef_124690 *, CRef_124690 *);
extern "C" void CRef_Destruct(CRef_124690 *);
extern "C" CRef_124690 *CRef_SetBasic(CRef_124690 *, BASIC_124690 *);
extern BASIC_124690 B_003DD040;
extern "C" CRef_124690 *func_00124690(CRef_124690 *presult) {
    CRef_124690 ref;
    ref.tag = -1;
    CRef_SetBasic(&ref, &B_003DD040);
    CRef_CopyConstruct(presult, &ref);
    CRef_Destruct(&ref);
    return presult;
}
