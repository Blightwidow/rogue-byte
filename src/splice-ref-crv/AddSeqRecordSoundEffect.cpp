struct JSGE { char pad[0x10]; int n[4]; float g[3]; };
struct JSG;
extern "C" JSGE *PjsgeAllocJsg(JSG *, int, int);
extern "C" void AddSeqRecordSoundEffect(JSG *pjsg, int a, int b, int c, int d, float g0, float g1, float g2)
{
    JSGE *e = PjsgeAllocJsg(pjsg, 0x36, 1);
e->n[0] = a;
e->n[1] = b;
e->n[2] = c;
e->n[3] = d;
e->g[0] = g0;
e->g[1] = g1;
e->g[2] = g2;
}
