# SPDX-License-Identifier: GPL-3.0-or-later
# Macros used by the Splat-generated assembly (build/splat/asm).

.macro glabel label
    .global \label
    .type \label, @function
    \label:
.endm

.macro dlabel label
    .global \label
    \label:
.endm

.macro jlabel label
    \label:
.endm
