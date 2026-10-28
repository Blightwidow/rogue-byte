struct ALO;
struct LIGHT {
    float v0;
    float v4;
    float v8;
    float vC;
};
extern "C" LIGHT *func_001F8300(ALO *);
extern "C" void func_001F8470(ALO *alo, float value)
{
    LIGHT *light = func_001F8300(alo);
    if (light)
        light->v4 = value;
}
