extern "C" float g_2ddf0c;
extern "C" float *g_2dd314;
extern "C" int B_003D3A3C;
extern "C" int SignalSema(int, float *);
extern "C" void StartLoadingLogo(float *logo)
{
 int s = B_003D3A3C; *logo = g_2ddf0c; g_2dd314 = logo; SignalSema(s, logo);
}
