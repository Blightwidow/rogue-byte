/* SPDX-License-Identifier: GPL-3.0-or-later */
struct ALLOCREQ_1BBD48 { int cb; int cbAlign; };
struct STGACTION_1BBD48 { int unk0; int *args; };
extern "C" STGACTION_1BBD48 *PactAddStgAction(void *, int);
extern "C" int *PvAllocStackImpl__Fi(ALLOCREQ_1BBD48 *);
extern "C" void func_001BBD48(void *stg, int arg1, int arg2) {
    STGACTION_1BBD48 *action = PactAddStgAction(stg, 0xC);
    ALLOCREQ_1BBD48 req;
    req.cb = 8;
    req.cbAlign = 0x10;
    action->args = PvAllocStackImpl__Fi(&req);
    action->args[0] = arg1;
    action->args[1] = arg2;
}
