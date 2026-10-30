struct VT_138BA0 {
    char pad0[0x10];
    short delta;
    short unused;
    void (*fn)(void *, float *, float *, void *, float, float);
};
struct OBJ_138BA0 { VT_138BA0 *vt; };
struct CHANNEL_138BA0 { float weight; struct HOST_138BA0 *host; };
struct HOST_138BA0 { char pad0[0x74]; float duration; char pad78[0xC0 - 0x78]; int stride; int count; char *base; };
struct MRSG_138BA0 { int offset; int keyA; int keyB; };
struct ACSB_138BA0 { int pad0; HOST_138BA0 *host; MRSG_138BA0 *mrsg; OBJ_138BA0 **objects; float rest; };
extern "C" {
int ImrsgLookUp__FffiP4MRSGPf(float, float, int, int, float *);
void func_00138BA0(ACSB_138BA0 *self, float *outA, float *outB, int unused, float time, float scale) {
    float values[3];
    float base;
    float sumA;
    float sumB;
    int index;
    int found = unused;
    char *entryBase = 0;
    char *entryRow = 0;
    HOST_138BA0 *host;
    if (self->mrsg == 0) {
        base = time / self->host->duration;
    } else {
        found = ImrsgLookUp__FffiP4MRSGPf(time, self->host->duration, self->mrsg->keyA, self->mrsg->keyB, &values[0]);
        entryRow = *(char **)((char *)self->mrsg + 8) + found * 8;
        base = values[0] / *(float *)(entryRow + 4);
    }
    host = self->host;
    index = 0;
    sumA = 0.0f;
    sumB = 0.0f;
    if (host->count > 0) {
        do {
            CHANNEL_138BA0 *channel = (CHANNEL_138BA0 *)(host->base + index * host->stride);
            if (channel->weight != 0.0f) {
                OBJ_138BA0 *object = self->objects[index];
                if (object != 0) {
                    float arg1Value;
                    float arg2Value;
                    if (self->mrsg != 0) {
                        char *record = (char *)channel + *(int *)self->mrsg + found * 8;
                        float channelDuration = channel->host->duration;
                        float second = *(float *)(record + 4);
                        arg1Value = *(float *)record + base * second;
                        arg2Value = (scale * second) / *(float *)(entryRow + 4);
                        if (channelDuration < arg1Value) {
                            arg1Value -= channelDuration;
                        }
                    } else {
                        float channelDuration = channel->host->duration;
                        arg2Value = (scale * channelDuration) / host->duration;
                        arg1Value = base * channelDuration;
                    }
                    VT_138BA0 *vt = object->vt;
                    vt->fn((char *)object + vt->delta, &values[1], &values[2], object, arg1Value, arg2Value);
                } else {
                    values[2] = 0.0f;
                    values[1] = self->rest;
                }
                sumA += channel->weight * values[1];
                sumB += channel->weight * values[2];
            }
            host = self->host;
            index++;
        } while (index < host->count);
    }
    if (outA != 0) {
        *outA = sumA;
    }
    if (outB != 0) {
        *outB = sumB;
    }
}
}
