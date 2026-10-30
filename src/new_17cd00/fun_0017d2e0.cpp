/* SPDX-License-Identifier: GPL-3.0-or-later */
struct VT_17D2E0 { char pad[0x40]; short delta; short unused; void (*fn)(void *); };
struct OBJ_17D2E0 { char pad[0xC]; VT_17D2E0 *vt; char pad2[0x3C - 0x10]; int state; };
struct GOAL_17D2E0 { char pad[0x10]; void *pguard; };
extern "C" void func_001EEF70(GOAL_17D2E0 *);
extern "C" OBJ_17D2E0 *func_00205438(void *, int);
extern "C" void func_0017D2E0(GOAL_17D2E0 *pgoal) {
    func_001EEF70(pgoal);
    OBJ_17D2E0 *pobj = func_00205438(pgoal->pguard, 0x9D);
    pobj->state = 2;
    pobj->vt->fn((char *)pobj + pobj->vt->delta);
}
