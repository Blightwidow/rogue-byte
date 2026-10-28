/* SPDX-License-Identifier: GPL-3.0-or-later */
extern "C" void PsmaApplySmInternal(int, int, int, int, int, int);
extern "C" void PsmaApplySmInternal_thunk(int a, int b, int c, int d, int e) { PsmaApplySmInternal(a, b, c, d, 4, e); }
