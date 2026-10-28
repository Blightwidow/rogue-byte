// 0x1813F0 Chaser_SetSpeedGain
extern "C" const float D_FLT_002BE87C;

void func_001813F0(void* arg0, float fparg0)
{
    float f0 = fparg0 * D_FLT_002BE87C;
    *(float*)((char*)arg0 + 0x384) = f0;
}
