struct GUARD { char pad[0xF80]; int mode; int target; };
extern "C" void func_00204F78(void *, int, int);
void ClearGuardPathMode(GUARD *pguard)
{
 switch (pguard->mode) { case 0: func_00204F78(pguard, pguard->target, 0); break; case 1: func_00204F78(pguard, pguard->target, 0); break; case 2: func_00204F78(pguard, pguard->target, 0); break; case 3: func_00204F78(pguard, pguard->target, 0); break; }
 pguard->target = 0; pguard->mode = -1; }
