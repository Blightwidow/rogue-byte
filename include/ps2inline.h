/* SPDX-License-Identifier: GPL-3.0-or-later */
/* Shared inline-assembly helpers for the instructions GCC cannot emit (ruled 2026-11-11, docs/build/inline-asm-helpers.md): each wraps
   one such instruction (plus the register move it needs), reused across retail's functions, never one function's own code. No
   register pins and no "memory" clobber; only the barriers (`sync`, `ei`) are volatile, so they do not move. A matched source includes
   this header and writes no asm of its own (scripts/matching/record.py). VU0 macro instructions: include/vu0inline.h. C and C++.

   A quadword held in a 128-bit register (a vector returned or passed by value) is a QW (include/types.h): GCC cannot shift it (no
   TImode shifts) and a union or struct goes through memory, so a lane comes out through these helpers. Measured in the pilot of
   2026-11-11: one instruction per helper lets the scheduler place each as retail does (LaneX after RotateWords3 matched 0x1430C8). */
#ifndef SLY2_PS2INLINE_H
#define SLY2_PS2INLINE_H
#include "types.h"

/* lane 0 (x) of a quadword as a float: mtc1 reads the register's low word */
static inline float LaneX(QW q)
{
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(q));
    return f;
}

/* lane 2 (z) of a quadword as a float: pextuw puts word 2 low, mtc1 moves it */
static inline float LaneZ(QW q)
{
    float f;
    u32 word;
    asm("pextuw %1, $0, %2\n\tmtc1 %1, %0" : "=f"(f), "=&r"(word) : "r"(q));
    return f;
}

/* word 2 of a quadword in a general register (pextuw with $zero): the caller moves it where it needs it */
static inline u32 LaneWordZ(QW q)
{
    u32 word;
    asm("pextuw %0, $0, %1" : "=&r"(word) : "r"(q));
    return word;
}

/* lane 2 (z) as a float held in a general register: pextuw only. GCC emits the mtc1 itself where the float is needed, so it schedules
   that move by its latency as retail does (FJtLandsWithin, UpdateStreamAmbPositional, SetHbskHbsks); LaneZ keeps the two together */
static inline float LaneZInGeneralRegister(QW q)
{
    float z;
    asm("pextuw %0, $0, %1" : "=r"(z) : "r"(q));
    return z;
}

/* lane 1 (y) as a float held in a general register: prot3w only, the mtc1 left to GCC as for LaneZInGeneralRegister */
static inline float LaneYInGeneralRegister(QW q)
{
    float y;
    asm("prot3w %0, %1" : "=r"(y) : "r"(q));
    return y;
}

/* mtc1 from a 32-bit word: the word's bits as a float. Paired with LaneWordZ it lets the scheduler place pextuw and mtc1 apart, as
   retail does when it extracts several lanes before moving them (0x184510, 0x18A350, 0x1E1238, 0x1E12E0, 0x1E57A0, 0x20D1F8, ...) */
static inline float FloatFromWord(u32 word)
{
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(word));
    return f;
}

/* prot3w: rotate the three low words, word 1 lands in word 0 (LaneX(RotateWords3(q)) is lane y) */
static inline QW RotateWords3(QW q)
{
    QW rotated;
    asm("prot3w %0, %1" : "=r"(rotated) : "r"(q));
    return rotated;
}

/* pextlw: interleave the low words of two registers, `low` in word 0 and `high` in word 1 */
static inline QW InterleaveLowWords(float high, float low)
{
    QW packed;
    asm("pextlw %0, %1, %2" : "=r"(packed) : "r"(high), "r"(low));
    return packed;
}

/* pcpyld: `high`'s low doubleword above `low`'s low doubleword */
static inline QW JoinLowDoublewords(float high, QW low)
{
    QW joined;
    asm("pcpyld %0, %1, %2" : "=r"(joined) : "r"(high), "r"(low));
    return joined;
}

/* pand: the 128-bit AND of two quadwords in general registers (a plain C `&` on QW fails: "unsupported wide integer operation"). Retail ANDs two
   axis bitsets of sixteen bytes each in one instruction (CobstacleFindPathzoneBox); the same instruction appears in three SDK-range functions that
   stay assembly (0x233470, 0x233638, 0x2401D8) */
static inline QW QuadAnd(QW first, QW second)
{
    QW both;
    asm("pand %0, %1, %2" : "=r"(both) : "r"(first), "r"(second));
    return both;
}

/* mfc1 into a quadword: a float in the low word of a general register, from where GCC moves it to a VU0 register (qmtc2) or stores it
   (FRenderRipPosMat; the scale of PresetJtAccelPipe and UpdateMurrayCarry) */
static inline QW QuadFromFloat(float value)
{
    QW quad;
    asm("mfc1 %0, %1" : "=r"(quad) : "f"(value));
    return quad;
}

/* sync: a memory barrier, volatile so that it stays where it is */
static inline void MemoryBarrier(void)
{
    asm volatile("sync");
}

/* ei: enable interrupts, volatile like sync so that it stays where it is. An interrupt handler ends with MemoryBarrier(); EnableInterrupts();
   (sly1-decomp's SyncAndEnableInterrupts: ResetGs, VBlankS_Interrupt) */
static inline void EnableInterrupts(void)
{
    asm volatile("ei");
}

#endif
