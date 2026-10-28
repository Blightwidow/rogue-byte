#include "sly2.h"
struct MOVIE { int a; char pad[0x34]; int b; char pad2[4]; char tail[0]; };
struct MOV { char b[0x40]; };
struct MPEG { unsigned count; MOV movies[4]; };
extern "C" void QueueMovie(MPEG *mpeg, MOV *movie)
{
    if (movie != 0) {
        if (((int *)movie)[1] != ((int *)movie)[0xF]) {
            unsigned count = mpeg->count;
            if (count < 4) {
                mpeg->movies[count] = *movie;
                mpeg->count = count + 1;
            }
        }
    }
}
