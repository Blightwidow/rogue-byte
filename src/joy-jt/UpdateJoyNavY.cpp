typedef int s32;
extern "C" {
s32 FJoyButtonPressed(char *, int);
struct CLOCK_G { char pad[0x3C]; float f3C; };
extern CLOCK_G g_2dded0;
extern float g_2ddf0c;
float fabsf(float);
#define F(t, o) (*(t *)(self + (o)))
s32 UpdateJoyNavY(char *self)
{
    float c;
    float base;
    if (F(s32, 0x1028) == 0) {
        s32 pressed = FJoyButtonPressed(self, 0x5000);
        if (pressed & 0x1000) {
            F(s32, 0x1028) = -1;
        } else if (pressed & 0x4000) {
            F(s32, 0x1028) = 1;
        } else if (0.8f <= F(float, 0x1044)) {
            float a = fabsf(F(float, 0x1040));
            float b = fabsf(F(float, 0x103C));
            if (b < a) {
                if (0.0f < F(float, 0x1040)) {
                    F(s32, 0x1028) = -1;
                } else {
                    F(s32, 0x1028) = 1;
                }
            }
        }
        if (F(s32, 0x1028) == 0)
            goto done;
        c = 0.3333f;
        F(float, 0x1038) = c;
        base = g_2ddf0c;
    } else {
        s32 v1 = 0;
        if (F(s32, 0x1028) < 0) {
            if (F(s32, 0x10B4) & 0x1000) {
                v1 = 1;
            } else if (0.25f <= F(float, 0x1044)) {
                float a = fabsf(F(float, 0x1040));
                float b = fabsf(F(float, 0x103C));
                if (b < a) {
                    if (0.0f < F(float, 0x1040)) v1 = 1;
                }
            }
        } else {
            if (F(s32, 0x10B4) & 0x4000) {
                v1 = 1;
            } else if (0.25f <= F(float, 0x1044)) {
                float a = fabsf(F(float, 0x1040));
                float b = fabsf(F(float, 0x103C));
                if (b < a) {
                    if (F(float, 0x1040) < 0.0f) v1 = 1;
                }
            }
        }
        if (v1 == 0) {
            F(s32, 0x1028) = 0;
            goto done;
        }
        if (F(float, 0x1034) <= g_2dded0.f3C) {
            float lo = 0.1f;
            float hi = 0.3333f;
            float t = (F(float, 0x1038) + F(float, 0x1038)) * 0.33333334f;
            if (t < lo) {
                c = lo;
            } else if (hi < t) {
                c = hi;
            } else {
                c = t;
            }
            F(float, 0x1038) = c;
            base = g_2dded0.f3C;
        } else {
            return 0;
        }
    }
    F(float, 0x1034) = base + c;
done:
    return F(s32, 0x1028);
}
}
