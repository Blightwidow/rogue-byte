struct World { char pad[0x1024]; int f1024; };
struct JT { World *world; char pad[0x28]; int hfdk; float timer; int mode; char pad2[0x18]; int f50; char pad3[0x14]; int f68; };
enum HFDK { HFDK_NONE = 0 };
extern float g_2dded0;
void SetJtHfdk(JT *jt, HFDK hfdk)
{
    if (hfdk == jt->hfdk) return;
    jt->hfdk = hfdk; jt->f50 = 0; jt->timer = g_2dded0;
    if (hfdk > 0) { if (hfdk >= 3) { if (hfdk == 3) jt->mode = 1; } else { if (jt->world->f1024 == jt->f68) jt->mode = 2; else jt->mode = 0; } }
}
