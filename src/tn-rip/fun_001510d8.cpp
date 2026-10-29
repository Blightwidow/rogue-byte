extern "C" int FFloatsNear__Ffff(float, float, float);

int func_001510D8(char *arg0) {
    float value = *(float *)(arg0 + 0x18);
    int result = 0;
    if (value < 0.0f || FFloatsNear__Ffff(*(float *)(arg0 + 0xAC), value, 0.01f)) {
        result = 1;
    }
    return result;
}
