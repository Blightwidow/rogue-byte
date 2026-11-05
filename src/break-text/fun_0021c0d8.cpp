struct VT { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct SO { char pad0[0xC]; VT *vptr; char pad10[0x11C]; float u; float du; char pad134[0x24]; int cIdle; char pad15c[8]; int cRec; };
extern "C" void UpdateLo(SO *);
extern float g_2dded4;

void func_0021C0D8(SO *s)
{
    UpdateLo(s);
    float du = s->du;
    if (du != 0.0f) {
        float u = s->u + g_2dded4 * du;
        s->u = u;
        if (u <= 0.0f) {
            s->u = 0.0f;
            s->du = 0.0f;
        } else {
            if (u >= 1.0f) {
                s->u = 1.0f;
                s->du = 0.0f;
            }
        }
    }
    if (s->u <= 0.0f && s->du <= 0.0f && s->cRec >= s->cIdle) {
        VT *v = s->vptr;
        v->fn((char *)s + v->delta);
    }
}
