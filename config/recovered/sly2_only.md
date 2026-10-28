# Sly 2-only code

Of 6355 Sly 2 functions: 727 matched to Sly 1, 548 in the SDK block, 2752 unmatched but similar to some Sly 1 function (best BSim cosine >= 0.3: likely changed counterparts not found yet), **2328 Sly 2-only** (best cosine under 0.3).

410 clusters of consecutive Sly 2-only functions (likely new source files or systems), 58 with 10 or more functions. Largest first; labels come from the Rust port's modules, referenced strings, named callees and the classes whose vtables point in.

| # | Address range | Functions | Instructions | Rust port modules | Calls (named) | Classes (cid) | Strings |
|---|---|---|---|---|---|---|---|
| 1 | 0x101608-0x110AB0 | 385 | 14789 | game/fields, classes/c2cf880, game/methods/cls | RefSetArgsFromSplice, SetTag, SetScrollerMasterSpeeds | - | - |
| 2 | 0x1E6660-0x1EA410 | 34 | 3773 | player/p5_target, player/p5_attach | CopyAb, GModPositive, FUN_001cdf78 | 106 | - |
| 3 | 0x167870-0x16E1A8 | 17 | 3553 | - | CopyAb, UnpackHelper, EndDmaCnt | - | - |
| 4 | 0x195368-0x1995D8 | 14 | 3143 | player/p18_gadget, player/p5_target, player/p5_states | LimitVectorLength, GSmooth, atan2f | - | - |
| 5 | 0x219400-0x21AA60 | 4 | 2519 | - | memset, GLimitLm | - | Widget Item 7, Widget Item 1 |
| 6 | 0x172018-0x1752F0 | 30 | 2406 | player/p4 | atan2f, _$_4CRef, SetLightHighlightColor | 158, 157, 159, 119 | - |
| 7 | 0x1B45D0-0x1B9130 | 30 | 2265 | - | SetVectorCylind, PvAllocSwClearImpl, PostStepLoadRun | - | - |
| 8 | 0x114680-0x116A58 | 6 | 2248 | - | CopyAb, strlen | - | - |
| 9 | 0x1BC198-0x1BE398 | 22 | 2188 | - | _$_4CRef, PvAllocStackImpl, memset | 14 | - |
| 10 | 0x1D6B00-0x1D8B20 | 23 | 1830 | game/flow | SetTag, memset, PvAllocSwImpl | 70 | oidPoCurrent, fVault |
| 11 | 0x1C3458-0x1C6308 | 34 | 1812 | player/mod | GetJtPipeGoalMat, SetVectorCylind, FUN_001e2840 | 50, 92, 95, 69 | oidPoCurrent |
| 12 | 0x2297F8-0x22B5C0 | 11 | 1731 | gfx/screen | SaveChkmgrCheckpoint, DecomposeRotateMatrixRad, TiltMatUpright | 107, 48, 49, 50 | - |
| 13 | 0x1D19A8-0x1D3450 | 6 | 1729 | - | atan2f, GSmooth, SetVectorCylind | 77 | - |
| 14 | 0x13E510-0x13FE18 | 11 | 1636 | - | S32Read, S16Read, U32Read | - | - |
| 15 | 0x18A350-0x18C120 | 8 | 1613 | player/p14, player/p15_binoc, player/mod | TFindAsegLabel, FCalculateMuzzleVelocity, GLimitLm | - | - |
| 16 | 0x142880-0x1449D0 | 28 | 1585 | player/loot, player/p18_gadget, player/p7_damage | , SetTag, SetVectorCylind | 55 | oidBooty, episode |
| 17 | 0x1FD0E8-0x1FEDF0 | 16 | 1511 | - | memset, , GLimitLm | - | - |
| 18 | 0x1C09A0-0x1C2920 | 21 | 1450 | - | memset, CopyAb, PvAllocSwClearImpl | 124 | - |
| 19 | 0x1CBAC0-0x1CDCD0 | 20 | 1379 | camera/cm | SetVectorCylind, MinimizeRange, FixStepAngularVelocity | 61 | - |
| 20 | 0x1E1B68-0x1E5628 | 14 | 1374 | - | FUN_00194f38, GLimitLm, MarkClockTickRealOnly | - | - |
| 21 | 0x213DB0-0x2159E0 | 11 | 1359 | - | , U16Read, PvAllocSlotheapClearImpl | - | - |
| 22 | 0x1FF4F0-0x200598 | 8 | 1284 | splice/serialize | , SetTag, FUN_00194f38 | - | - |
| 23 | 0x2242E0-0x225880 | 13 | 1221 | - | memset, PsoHitTestLineObjects, _$_4CRef | 102, 100, 101 | - |
| 24 | 0x1904E0-0x193DE8 | 9 | 1218 | player/p4, player/p5_attach, player/p5_target | PostStepLoadRun, FUN_001e2840, ResetJtDynamicTunnel | - | - |
| 25 | 0x1DE400-0x1DFB10 | 10 | 1196 | - | _$_4CRef, PvAllocSwCopyImpl, memset | 85, 114 | - |
| 26 | 0x14A248-0x14B508 | 10 | 1178 | - | SetVectorCylind, SetVectorSphere, RadBetweenVectors | 182, 63 | - |
| 27 | 0x100008-0x1012C0 | 29 | 1157 | - | RefSetArgsFromSplice, SetTag, FlushCache | - | - |
| 28 | 0x12AEB0-0x12C708 | 16 | 1152 | - | FFloatsNear, EvaluateBezierPos, U16Read | - | - |
| 29 | 0x1450E0-0x147410 | 24 | 1151 | - | atan2f, RadNormalize, GLimitAbs | 195, 196, 197, 198 | - |
| 30 | 0x1D54B8-0x1D66F0 | 8 | 1138 | - | SetTag, FUpdatableSaa | - | - |
| 31 | 0x21F188-0x220BE8 | 7 | 1132 | player/p26 | , RadNormalize, _$_4CRef | - | - |
| 32 | 0x120FB0-0x1223C0 | 12 | 1114 | splice/bif | SetTag, , memset | - | - |
| 33 | 0x1C9190-0x1CA118 | 9 | 1098 | - | memset, PvAllocSwClearImpl, WaitSema | 128, 129, 2, 3 | - |
| 34 | 0x19CCE8-0x19F290 | 20 | 1042 | ui/binoc_hud, player/p15_binoc, player/p14 | SetTimerTimers, _$_4CRef, qsort | - | - |
| 35 | 0x1347A8-0x135F78 | 13 | 1034 | - | PostStepLoadRun, SetVectorCylind, RadNormalize | 55 | - |
| 36 | 0x1532D8-0x154908 | 15 | 991 | - | memmove, MarkClockTickRealOnly, GLimitLm | 16 | - |
| 37 | 0x15CDA8-0x15E228 | 12 | 969 | - | sprintf, fmodf, strcpy | 131, 116 | %01d:%02d |
| 38 | 0x127E90-0x129050 | 11 | 951 | splice/eval | FUN_00194f38,  | - | - |
| 39 | 0x180100-0x181060 | 8 | 951 | - | RadNormalize, atan2f, GLimitAbs | 73, 74 | - |
| 40 | 0x1A3B80-0x1A4FB0 | 9 | 937 | - | memset, , GetNormalVectors | - | - |
