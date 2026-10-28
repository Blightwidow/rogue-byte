struct LIGHT {
    float v0;
    float v4;
    float v8;
    float vC;
};
struct OWNER {
    char pad[0xDC];
    LIGHT *light;
};
struct ALO {
    char pad[0xE8];
    OWNER *owner;
};
extern "C" float func_001F8440(ALO *alo)
{
    OWNER *owner = alo->owner;
    LIGHT *light = 0;
    if (owner)
        light = owner->light;
    if (light)
        return light->vC;
    return 0.0f;
}
