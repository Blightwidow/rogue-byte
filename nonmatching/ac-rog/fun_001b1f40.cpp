struct LO { char pad[0x18]; int oid; };
struct TRIG { char pad[0x238]; int coid; int aoid[4]; int ccid; int acid[4]; };
extern "C" int FIgnoreBombIntersection();
extern "C" int FIsBasicDerivedFrom(LO *, int);
extern "C" int IMax(int, int);
 int func_001B1F40(TRIG *self, LO *plo) { int answer = FIgnoreBombIntersection(); for (int i = 0; i < self->coid; i++) { if (self->aoid[i] == plo->oid) answer = IMax(answer, 1); } for (int j = 0; j < self->ccid; j++) { if (FIsBasicDerivedFrom(plo, self->acid[j])) answer = IMax(answer, 1); } return answer; }
