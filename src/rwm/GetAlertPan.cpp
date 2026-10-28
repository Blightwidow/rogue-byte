struct VT { char pad[0xF8]; short delta; short idx; float *(*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct ALERT { char pad[0xC]; OBJ *palo; int mode; };
struct CM { char pad[0x60]; float x; float y; };
extern CM B_002DDF40;
extern "C" float atan2f(float, float);
float GetAlertPan(ALERT *palert)
{
    float rad = 0.0f;
    int mode = palert->mode;
    switch (mode) {
 case 0: rad = atan2f(B_002DDF40.y, B_002DDF40.x); break;
 case 1: {
        OBJ *o = palert->palo;
        float *first = o->vt->fn((char *)o + o->vt->delta);
        o = palert->palo;
        float *second = o->vt->fn((char *)o + o->vt->delta);
        rad = atan2f(first[1], second[0]);
} break; case -1: break; default: break; }
    return rad;
}
