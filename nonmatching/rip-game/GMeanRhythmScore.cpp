extern "C" float GLimitLm__FP2LMf(void *, float);
struct Rhythm {
    char pad[0x234];
    char lm[8];
    int count;
    float scores[16];
    int window;
};
extern "C" float GMeanRhythmScore(Rhythm *rhythm)
{
    int window = rhythm->window;
    if (window < 1)
        return 0.0f;
    float sum = 0.0f;
    int index = rhythm->count;
    int first = index - window;
    if (first < 0)
        first = 0;
    index--;
    while (index >= first) {
        sum += rhythm->scores[index];
        index--;
    }
    return GLimitLm__FP2LMf(rhythm->lm, sum / (float)window);
}
