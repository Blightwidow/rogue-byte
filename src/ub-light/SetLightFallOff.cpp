struct Eight { char b[8]; };
extern "C" void RebuildLight(char *);
void SetLightFallOff(char *self, Eight *value)
{
    *(Eight *)(self + 0x164) = *value;
    RebuildLight(self);
}
