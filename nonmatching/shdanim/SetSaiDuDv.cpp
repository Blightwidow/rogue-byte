#include "sly2.h"
struct SAA { char pad[0x24]; short du; short dv; int unk; int dirty; char pad2[4]; char sl[1]; };
extern "C" int FIsSlEmpty(void *);
void SetSaiDuDv(SAA *s, float du, float dv)
{
    if (FIsSlEmpty(s->sl)) return;
    int duFixed = (int)(du * 4096.0f + 0.5f) & 0xFFF;
    int dvFixed = (int)(dv * 4096.0f + 0.5f) & 0xFFF;
    if (s->du != duFixed || s->dv != dvFixed) {
        s->dirty = 1;
        s->dv = dvFixed;
        s->du = duFixed;
    }
}
