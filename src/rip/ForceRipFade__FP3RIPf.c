extern float g_2dded0;
void ForceRipFade__FP3RIPf(char *rip, float limit) {
    float duration = *(float *)(rip + 0x18);
    float remaining = duration - (g_2dded0 - *(float *)(rip + 0x14));
    if (limit < remaining) {
        float ratio = remaining / duration;
        float scaled = limit / ratio;
        *(float *)(rip + 0x18) = scaled;
        *(float *)(rip + 0x14) = g_2dded0 - ((1.0f - ratio) * scaled);
    }
}
