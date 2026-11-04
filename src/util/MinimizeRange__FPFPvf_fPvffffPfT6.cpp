static inline float fmax2(float a, float b) { return b > a ? b : a; }
static inline float fmin2(float a, float b) { return b < a ? b : a; }
static inline float Clamp(float value, float low, float high) {
    if (value < low) return low;
    if (high < value) return high;
    return value;
}
struct Point { float x, y; };
struct Bracket { Point a, mid1, b, mid2, c; };
typedef float (*Objective)(void *, float);
extern "C" float MinimizeRange__FPFPvf_fPvffffPfT6(Objective function, void *context, float start, float step,
                                                   float low, float high, float *outX, float *outY) {
    Bracket br;
    start = Clamp(start, low, high);
    br.a.x = fmax2(low, start - step);
    br.a.y = function(context, br.a.x);
    br.b.x = start;
    br.b.y = function(context, start);
    br.c.x = fmin2(high, start + step);
    br.c.y = function(context, br.c.x);
    int iteration;
    while (1) {
        if (br.a.y < br.b.y) {
            br.c = br.b;
            br.b = br.a;
            br.a.x = fmax2(low, br.b.x + br.b.x - br.c.x);
            br.a.y = function(context, br.a.x);
            continue;
        }
        if (br.c.y < br.b.y) {
            br.a = br.b;
            br.b = br.c;
            br.c.x = fmin2(high, br.b.x + br.b.x - br.a.x);
            br.c.y = function(context, br.c.x);
            continue;
        }
        break;
    }
    for (iteration = 9; iteration >= 0; iteration--) {
        br.mid1.x = (br.a.x + br.b.x) * 0.5f;
        br.mid1.y = function(context, br.mid1.x);
        br.mid2.x = (br.b.x + br.c.x) * 0.5f;
        br.mid2.y = function(context, br.mid2.x);
        if (br.mid1.y < br.b.y) {
            if (br.mid1.y < br.mid2.y) {
                br.c = br.b;
                br.b = br.mid1;
            } else {
                br.a = br.b;
                br.b = br.mid2;
            }
        } else {
            if (br.b.y <= br.mid2.y) {
                br.a = br.mid1;
                br.c = br.mid2;
            } else {
                br.a = br.b;
                br.b = br.mid2;
            }
        }
    }
    if (outX) *outX = br.b.x;
    float resultY = br.b.y;
    if (outY) *outY = resultY;
    return resultY;
}
