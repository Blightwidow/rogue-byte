extern "C" float g_2dded0;
extern "C" const float D_002C3D40;
extern "C" const float D_002C3D44;
extern "C" const float D_002C3D48;
struct Guard {
    char pad[0xFBC];
    int mode;
    float time;
};
void SetGuardMode(Guard *, int);

void UpdateGuardModeTimeout(Guard *g)
{
    switch (g->mode) {
    case 8:
    case 13:
        if (D_002C3D40 < g_2dded0 - g->time) {
            SetGuardMode(g, -1);
        }
        break;
    case 34:
    case 37:
        if (D_002C3D44 < g_2dded0 - g->time) {
            SetGuardMode(g, -1);
        }
        break;
    case 21:
        if (D_002C3D48 < g_2dded0 - g->time) {
            SetGuardMode(g, -1);
        }
        break;
    }
}
