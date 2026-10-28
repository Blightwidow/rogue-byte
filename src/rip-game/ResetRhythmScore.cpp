// 0x153800 ResetRhythmScore
void ResetRhythmScore(void* prhythm)
{
    int* p = (int*)prhythm;
    p[0x23C / 4] = 0;
    p[0x284 / 4] = 0;
    p[0x288 / 4] = 0;
}
