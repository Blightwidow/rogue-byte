extern "C" int sprintf(char *, const char *, ...);
extern float g_2dded0;
extern float B_003E1BFC;
static inline float Clamp(float value, float low) { return value < low ? low : value; }
extern "C" void func_00210F80(char *text)
{
    float start = g_2dded0;
    float elapsed = B_003E1BFC - start;
    int total = (int)Clamp(elapsed, 0.0f);
    int minutes = total / 60;
    sprintf(text, "%d:%02d", minutes, total - minutes * 60);
}
