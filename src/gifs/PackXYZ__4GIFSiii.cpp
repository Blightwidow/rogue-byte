/* SPDX-License-Identifier: GPL-3.0-or-later */
struct GIFS { char pad[0xC]; char *cur; };
extern "C" void CheckReg__4GIFSii(GIFS *, int, int);
extern "C" void PackXYZ__4GIFSiii(GIFS *self, int x, int y, long z) {
    CheckReg__4GIFSii(self, 1, 5);
    char *p = self->cur;
    self->cur = p + 0x10;
    *(int *)(p + 0) = x;
    *(int *)(p + 4) = y;
    *(long *)(p + 8) = z;
}
