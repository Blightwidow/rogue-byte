#include "sly2.h"
struct OSTRM { int unk0; int unk4; int unk8; int fd; int unk10; int count; char data[1]; };
void CopyAb(void *, void *, unsigned int);
extern "C" void func_00236960(const char *, char *);
extern "C" void func_00238528(int, char *, int);
extern char RO_STR_002A8910[];
void Flush__5OSTRM(OSTRM *self)
{
    char buf[0x90];
    int done;
    char *src;
    int chunk;
    int remaining;

    if (self->count == 0)
        return;
    if (self->unk0 != 0)
        return;
    if (self->fd < 0) {
        src = self->data;
        for (done = 0; done < self->count; done += chunk) {
            remaining = self->count - done;
            chunk = 0x80;
            if (!(remaining > 0x7F))
                chunk = remaining;
            CopyAb(buf, src, chunk);
            src += chunk;
            buf[chunk] = 0;
            func_00236960(RO_STR_002A8910, buf);
        }
    } else {
        func_00238528(self->fd, self->data, self->count);
    }
    self->count = 0;
}
