/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SAVE;
struct ALLOCREQ { int cb; int cbAlign; };
struct CFileLocation { unsigned a; unsigned b; unsigned c; unsigned d; char pad[0x100]; void Clear(); };
struct STREAM { char pad[0x70]; };
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
int sprintf(char *, const char *, ...);
int McOpenFile(SAVE *, const char *, int, int *);
int McWrite(SAVE *, int, void *, int, int *);
int McClose(SAVE *, int);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
void CBinaryInputStream_ConstructFromBuffer(STREAM *, int, void *, int);
int CBinaryFileStream_FOpenLocation(STREAM *, CFileLocation *);
int CBinaryInputStream_Read(STREAM *, int, void *);
void CBinaryFileStream_Close(STREAM *);
void CBinaryFileStream_Destructor(STREAM *, int);
extern const char RO_002A6CB8[];
}
extern "C" int load_file_from_disc(SAVE *psave, const char *dir, const unsigned *record, const char *file)
{
    char frame[0x10];
    char path[0x50];
    CStackFrame_Construct(frame);
    sprintf(path, RO_002A6CB8, dir, file);
    int fd = -1;
    int error = McOpenFile(psave, path, 0x202, &fd);
    if (error == 0) {
        CFileLocation location;
        CFileLocation *loc = &location;
        loc->c = 2;
        loc->Clear();
        ALLOCREQ request;
        ALLOCREQ *req = &request;
        req->cb = 0x403F;
        req->cbAlign = 0x10;
        void *buffer = PvAllocStackImpl__Fi(req);
        STREAM stream;
        CBinaryInputStream_ConstructFromBuffer(&stream, 0x403F, buffer, 0);
        int hasLocation = record != 0 ? (location.a = (record[0] ^ record[0xD]) + 0xCA0, loc->c = 2, location.b = record[1] ^ record[0xF], location.b != 0) : 0;
        if (hasLocation && CBinaryFileStream_FOpenLocation(&stream, loc) != 0) {
            char data[0x1000];
            int written;
            int count;
            goto read;
        body:
            error = McWrite(psave, fd, data, count, &written);
            if (error != 0)
                goto done;
            if (written != count) {
                error = 7;
                goto done;
            }
        read:
            count = CBinaryInputStream_Read(&stream, 0x1000, data);
            if (count != 0)
                goto body;
            error = 0;
        } else {
            error = 0x27;
        }
    done:
        CBinaryFileStream_Close(&stream);
        int closeError = McClose(psave, fd);
        if (error == 0)
            error = closeError;
        CBinaryFileStream_Destructor(&stream, 2);
    }
    CStackFrame_Destructor(frame, 2);
    return error;
}
