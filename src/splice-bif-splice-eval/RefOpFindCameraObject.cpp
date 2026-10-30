/* SPDX-License-Identifier: GPL-3.0-or-later */
struct CRef_1246E0 { int tag; int value; int pad[2]; };
struct BASIC_1246E0;
extern "C" void CRef_CopyConstruct(CRef_1246E0 *, CRef_1246E0 *);
extern "C" void CRef_Destruct(CRef_1246E0 *);
extern "C" CRef_1246E0 *CRef_SetBasic(CRef_1246E0 *, BASIC_1246E0 *);
extern BASIC_1246E0 B_002DDF40;
extern "C" CRef_1246E0 *RefOpFindCameraObject(CRef_1246E0 *presult) {
    CRef_1246E0 ref;
    ref.tag = -1;
    CRef_SetBasic(&ref, &B_002DDF40);
    CRef_CopyConstruct(presult, &ref);
    CRef_Destruct(&ref);
    return presult;
}
