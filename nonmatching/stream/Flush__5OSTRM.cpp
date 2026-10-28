#include "sly2.h"
struct OSTRM { int unk0; int unk4; int unk8; int fd; int unk10; int count; char data[1]; };
void CopyAb(void *, void *, unsigned int);
extern "C" void func_00236960(const char *, char *);
extern "C" void func_00238528(int, char *, int);
extern char RO_STR_002A8910[];
void Flush__5OSTRM(OSTRM *self)
{
    int count = self->count;
    int total = count;
    if (count == 0 || self->unk0 != 0)
        return;
    if (self->fd < 0) {
        char *src = self->data;
        char line[0x90];
        int done = 0;
        int limit = 0x7f;
        asm("" : "+r"(limit));
        while (done < total) {
            int remaining = total - done;
            int chunk = (remaining > limit) ? 0x80 : remaining;
            done += chunk;
            CopyAb(line, src, chunk);
            src += chunk;
            line[chunk] = 0;
            func_00236960(RO_STR_002A8910, line);
            total = self->count;
        }
    } else {
        func_00238528(self->fd, self->data, count);
    }
    self->count = 0;
}
