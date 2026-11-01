struct SMP11D018 { float a; float b; float c; };
extern "C" int CSolveQuadratic(float, float, float, float *);
extern "C" {
float GSmooth__FfffP3SMPPf(float target, float start, float t, SMP11D018 *psmp, float *pvel)
{
    float roots[2];
    float pos;
    float vel;
    int flipped = 0;
    float dist;

    if (psmp->a == 0.0f) {
        if (pvel)
            *pvel = 0.0f;
        return target;
    }
    dist = target - start;
    if (dist < 0.0f) {
        dist = -dist;
        flipped = 1;
    }
    float ramp = (psmp->b + psmp->a) * psmp->c * 0.5f;
    if (ramp <= dist) {
        float cruise = (dist - ramp) / psmp->a;
        if (t <= cruise) {
            vel = -psmp->a;
            pos = dist - psmp->a * t;
        } else {
            t -= cruise;
            dist = ramp;
            goto quad;
        }
    } else {
    quad:
        int count = CSolveQuadratic((psmp->a - psmp->b) / (2.0f * psmp->c), psmp->b, -dist, roots);
        float rem = roots[count - 1] - t;
        pos = 0.0f;
        if (rem > 0.0f) {
            float v = (psmp->a - psmp->b) * rem;
            vel = -(psmp->b + v / psmp->c);
            pos = (v * rem) / (2.0f * psmp->c) + psmp->b * rem;
        } else {
            vel = -psmp->b;
        }
    }
done:
    if (flipped) {
        pos = start - pos;
        if (pvel)
            *pvel = -vel;
    } else {
        pos = pos + start;
        if (pvel)
            *pvel = vel;
    }
    return pos;
}
}
