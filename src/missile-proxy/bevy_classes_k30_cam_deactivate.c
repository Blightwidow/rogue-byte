#include "types.h"

struct CMLIKE {
    char pad[0x120];
    s32 fReset;
};

struct K30CAM {
    char pad[0x10];
    struct CMLIKE *pcm;
};

s32 DeactivateCplcy(void *, s32, void *);       /* extern */
s32 SetResetFlag__FP2CM(s32 *);             /* extern */
extern s32 B_002DDF40;

void bevy_classes_k30_cam_deactivate(struct K30CAM *pk30cam, s32 arg1, struct CMLIKE *pcm) {
    if (pk30cam->pcm == pcm) {
        if (pcm->fReset != 0) {
            SetResetFlag__FP2CM(&B_002DDF40);
        }
        pk30cam->pcm = 0;
    }
    DeactivateCplcy(pk30cam, arg1, pcm);
}
