#include "sly2.h"
struct CQueueOutputIop {
    int pad0;
    int wfmt;
    int rate;
    int channels;
    int run;
    int iop;
    int ring;
    void Reset();
};
struct HDR { char pad[8]; int wfmt; int rate; int channels; int run; };
extern "C" int snd_PlaySoundVolPanPMPB(int, int, int, int, int, int);

int CQueueOutputIop_FInit(CQueueOutputIop *queue, HDR *hdr)
{
    int wfmt = hdr->wfmt;
    queue->wfmt = wfmt;
    queue->rate = hdr->rate;
    int channels = hdr->channels;
    queue->channels = channels;
    queue->run = hdr->run;
    if (wfmt == 0x10) {
        queue->ring = channels << 12;
        queue->iop = snd_PlaySoundVolPanPMPB(0x400, 0x1000, 0x400, 0, 2, 3);
    } else {
        queue->ring = 0x6000;
        queue->iop = snd_PlaySoundVolPanPMPB(0x6000, 0, 0x400, 0, 2, 2);
    }
    if (queue->iop < 0)
        return 0;
    queue->Reset();
    return 1;
}
