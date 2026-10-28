/* SPDX-License-Identifier: GPL-3.0-or-later */
extern "C" void* PjsgeAllocJsg(void*, int, int);
extern "C" void* AddSeqRecordEndThread(void* a) { return PjsgeAllocJsg(a, 1, 1); }
