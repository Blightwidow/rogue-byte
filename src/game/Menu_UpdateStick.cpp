extern "C" float atan2f(float, float);
struct JOY { char pad[0x103C]; float x; float y; float mag; };
struct VT { char pad[0x70]; short delta; short index; void (*fn)(void *, int); };
struct MENU { char pad0[0xC]; VT *vt; JOY *pjoy; char pad1[0x14]; int dir; };
void Menu_UpdateStick(MENU *pmenu)
{
    JOY *pjoy = pmenu->pjoy;
    if (pjoy == 0)
        return;
    if (pmenu->dir == -1) {
        float high = 0.8f; float mag = pjoy->mag; asm volatile("nop" : "+f" (high));
        if (high < mag) {
            float rad = atan2f(pjoy->y, pjoy->x);
            int octant = (int)(rad * 1.2732395f + 8.5f);
            VT *vt = pmenu->vt;
            vt->fn((char *)pmenu + vt->delta, octant % 8);
        }
    } else {
        float low = 0.5f; float mag = pjoy->mag; asm volatile("nop" : "+f" (low));
        if (mag < low) {
            VT *vt = pmenu->vt;
            vt->fn((char *)pmenu + vt->delta, -1);
        }
    }
}
