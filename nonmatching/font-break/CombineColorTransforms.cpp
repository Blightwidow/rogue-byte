static inline float Min(float a, float b) { return b < a ? b : a; }
static inline float Max(float a, float b) { return b > a ? b : a; }

extern "C" void CombineColorTransforms(unsigned char *parentMul, unsigned char *parentAdd, unsigned char *slotMul,
                                       unsigned char *slotAdd, unsigned char *outMul, unsigned char *outAdd)
{
    for (int i = 0; i < 4; i++) {
        float sm = (float)((int)slotMul[i] - 0x7F) * 0.007874016f;
        float pm = (float)((int)parentMul[i] - 0x7F) * 0.007874016f;
        pm = Max(Min(pm, 1.0f), -1.0f);
        sm = Max(Min(sm, 1.0f), -1.0f);
        float mul = Min(pm * sm, 1.0f);
        float add = pm * ((float)slotAdd[i] - 127.0f) + ((float)parentAdd[i] - 127.0f);
        add = Min(add, 128.0f);
        outMul[i] = (unsigned char)(int)(Max(mul, -1.0f) * 127.0f + 128.0f);
        outAdd[i] = (unsigned char)(int)(Max(add, -127.0f) + 127.0f);
    }
}
