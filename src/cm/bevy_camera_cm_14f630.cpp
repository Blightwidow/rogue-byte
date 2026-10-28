// 0x14F630 SetCmNearClipActivePolicy
extern "C" void SetCmNearClip(void* pcm, float sNearClip);

void bevy_camera_cm_14f630(void* arg0, float fparg0)
{
    SetCmNearClip(arg0, fparg0);
    void* temp_v0 = *(void**)((char*)arg0 + 0x314);
    if (temp_v0 != 0) {
        *(float*)((char*)temp_v0 + 8) = fparg0;
    }
}