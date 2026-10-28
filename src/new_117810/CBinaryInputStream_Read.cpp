#include "sly2.h"
struct CBinaryInputStream { int pad0; char *cursor; int available; };
extern "C" void CBinaryInputStream_Pump(CBinaryInputStream *);
extern "C" void CopyAb__FPvT0Ui(void *, void *, unsigned int);

int CBinaryInputStream_Read(CBinaryInputStream *stream, int count, void *dest)
{
    int left = count;
    if (stream->available < 0) {
        return 0;
    }
    while (left > 0) {
        CBinaryInputStream_Pump(stream);
        int available = stream->available;
        if (available == 0) {
            stream->available = -1;
            break;
        }
        int chunk = available;
        if (left < available) chunk = left;
        if (dest) {
            CopyAb__FPvT0Ui(dest, stream->cursor, chunk);
            dest = (char *)dest + chunk;
        }
        stream->cursor += chunk;
        stream->available -= chunk;
        left -= chunk;
    }
    return count - left;
}
