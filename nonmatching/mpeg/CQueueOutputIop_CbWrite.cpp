typedef signed char s8; typedef int s32;
struct COut {
    s32 f0; s32 mode; s32 f8; s32 channels; s32 f10; s32 f14; s32 size; s32 pos;
    s32 f20; s32 avail; s32 total; s32 played;
};
extern "C" {
int CQueueOutputIop_Deinterleave(COut *, int, char *);
int CQueueOutputIop_SendToIop(COut *, int, char *, int);
int CQueueOutputIop_CbWrite(COut *self, int limit, char *data) {
    int done = 0;
    int want = limit;
    if (want <= 0 || self->avail < want) want = self->avail;
    if (self->mode == 0x10) {
        want &= -(self->channels << 10);
        CQueueOutputIop_Deinterleave(self, want, data);
    } else {
        want &= ~0x3FF;
    }
    while (want != 0) {
        int room = self->size - self->pos;
        int chunk = want;
        if (want >= room) chunk = room;
        char *dest = data + done;
        if (self->mode == 0x10) {
            chunk = 0x400;
            int phase = (self->played / 1024 / self->channels) % 4;
            if (phase == 0) {
                dest[1] = 6;
                dest[0x11] = 2;
            } else if (phase == 3) {
                dest[0x3F1] = phase;
            }
        }
        int sent = CQueueOutputIop_SendToIop(self, chunk, dest, chunk);
        want -= sent;
        if (sent == 0) break;
        done += sent;
        int next = self->pos + sent;
        self->pos = next;
        self->pos = next % self->size;
        self->total += sent;
        self->avail -= sent;
        self->played += sent;
        if (limit <= 0) break;
    }
    return done;
}
}
