// SPDX-License-Identifier: GPL-3.0-or-later
struct SEQRECORD_1E09D0 { char pad0[0x10]; int iA; int iB; int iC; };
extern "C" void *PjsgeAllocJsg(void *, int, int);

extern "C" void AddSeqRecordToss(void *pOwner, int iA, int iB, int iC)
{
    SEQRECORD_1E09D0 *pRecord = (SEQRECORD_1E09D0 *)PjsgeAllocJsg(pOwner, 0x1E, 0);
    pRecord->iA = iA;
    pRecord->iB = iB;
    pRecord->iC = iC;
}
