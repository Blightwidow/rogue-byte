#include "sly2.h"
struct CPLCY {
    int unk0; int unk4; int unk8;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void Reset();
};
struct CPR { CPLCY *pcplcy; int pad[3]; };
struct CM { char pad[0x30C]; int ccpr; int unk310; CPR acpr[1]; };
struct CM2 : CM { };

void bevy_camera_cm_14d650(CM *pcm)
{
    for (int icpr = 0; icpr < pcm->ccpr; icpr++)
        pcm->acpr[icpr].pcplcy->Reset();
    *(int *)((char *)pcm + 0x620) = 0;
    *(float *)((char *)pcm + 0x624) = 10.0f;
}
