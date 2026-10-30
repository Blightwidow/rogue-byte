/* SPDX-License-Identifier: GPL-3.0-or-later */
struct LM_154DC8;
struct DIFFICULTY_154DC8 { char pad[0x14]; LM_154DC8 *plm; };
struct SUCKER_154DC8 { char pad[0xA8]; float *psuck; };
struct GAME_154DC8 { char pad[0x3B0C]; SUCKER_154DC8 *psucker; };
extern "C" float GLimitLm__FP2LMf(LM_154DC8 *, float);
extern GAME_154DC8 B_003DD490;
extern "C" void ChangeSuck__FfP10DIFFICULTY(float suck, DIFFICULTY_154DC8 *pdifficulty) {
    GAME_154DC8 *pgame = &B_003DD490;
    if (pgame->psucker != 0) {
        *pgame->psucker->psuck = GLimitLm__FP2LMf(pdifficulty->plm, suck);
    }
}
