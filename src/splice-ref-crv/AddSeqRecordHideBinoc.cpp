/* SPDX-License-Identifier: GPL-3.0-or-later */
extern "C" void* PjsgeAllocJsg(void*, int, int);
extern "C" void* AddSeqRecordHideBinoc(void* a, int b) { return PjsgeAllocJsg(a, 60, b); }
