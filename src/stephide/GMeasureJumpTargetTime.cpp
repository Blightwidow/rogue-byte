typedef int QW __attribute__((mode(TI)));
extern "C" void MeasureJtJumpToTargetAtTime(int, int, QW, float *, int, int);
struct Mjt { int pjmp; int palo; int pad[2]; QW pos; };
float GMeasureJumpTargetTime(Mjt *mjt)
{
    float measure;
    MeasureJtJumpToTargetAtTime(mjt->pjmp, mjt->palo, mjt->pos, &measure, 0, 0);
    return measure;
}
