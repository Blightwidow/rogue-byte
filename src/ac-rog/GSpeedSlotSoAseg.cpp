struct VT {
    char pad[0x18];
    short delta;
    short index;
    void (*fn)(void *, float, float, float *, int);
};
struct CHN {
    int unk0;
    void **panim;
};
struct ASEG {
    char pad[0x74];
    float duration;
    float rate;
};

extern "C" {
CHN *PchnFindAseg(ASEG *, void *, int, int);
void GSpeedSlotSoAseg(void *pso, ASEG *paseg, float *pgSpeed);
}

void GSpeedSlotSoAseg(void *pso, ASEG *paseg, float *pgSpeed)
{
    float agStart[4];
    float agEnd[4];
    if (paseg != 0) {
        CHN *pchn = PchnFindAseg(paseg, pso, 1, 1);
        if (pchn != 0) {
            register void *panim asm("$7") = pchn->panim;
            VT *vt = *(VT **)panim;
            vt->fn((char *)panim + vt->delta, 0.0f, 1.0f, agStart, 0);
            register void *panim2 asm("$7") = pchn->panim;
            VT *vt2 = *(VT **)panim2;
            vt2->fn((char *)panim2 + vt2->delta, paseg->duration, 1.0f, agEnd, 0);
            float d = agEnd[0] - agStart[0];
            *pgSpeed = __builtin_fabsf(d) / paseg->duration * paseg->rate;
        }
    }
}
