// SPDX-License-Identifier: GPL-3.0-or-later
struct SIFDMA { void *src; char *dst; int size; int attr; };
struct IOPMODULE { int size; char *data; int argumentLength; int arguments; int pad; };
extern "C" {
void CdPath__FPcT0i(char *, char *, int);
int FCdCompleted__Fi(int);
int FValidCdMmode__Fv(void);
void FlushCache(int);
void SetCdMmode__Fv(void);
int func_00238BD0(void);
char *func_00238C58(int);
void func_00238D40(char *);
void func_002425F0(int);
void sceCdInit(int);
void sceFsReset(void);
void sceSifInitRpc(int);
void sceSifLoadFileReset(void);
int sceSifLoadModule(char *, int, int);
int sceSifRebootIop(const char *);
unsigned int sceSifSetDma(SIFDMA *, int);
int sceSifSyncIop(void);
extern int B_002E2058;
extern IOPMODULE *D_004E5D80;
extern IOPMODULE *D_004E5E38;
extern char RO_STR_002A6A48[];
void func_001A7630(void) {
    union {
        char path[0x100];
        SIFDMA dma;
    } frame;
    sceSifInitRpc(0);
    sceSifLoadFileReset();
    sceCdInit(0);
    if (FValidCdMmode__Fv() == 0) {
        for (;;) {
        }
    }
    SetCdMmode__Fv();
    sceFsReset();
    if (B_002E2058 == 0) {
        CdPath__FPcT0i(frame.path, RO_STR_002A6A48, 1);
        do {
        } while (sceSifRebootIop(frame.path) == 0);
        do {
        } while (sceSifSyncIop() == 0);
        sceSifInitRpc(0);
        sceSifLoadFileReset();
        sceCdInit(0);
        if (FValidCdMmode__Fv() == 0) {
            for (;;) {
            }
        }
        SetCdMmode__Fv();
        sceFsReset();
    }
    func_002425F0(0);
    FCdCompleted__Fi(1);
    func_00238BD0();
    int largest = 0;
    for (IOPMODULE *module = D_004E5D80; module < D_004E5E38; module++) {
        largest = module->size >= largest ? module->size : largest;
    }
    char *staging = func_00238C58(largest);
    IOPMODULE *module = D_004E5D80;
    while (module < D_004E5E38) {
        IOPMODULE *next = module + 1;
        int remaining = module->size;
        int offset = 0;
        if (remaining != 0) {
            do {
                int chunk = 0xFFFC0;
                if (remaining < chunk) chunk = remaining;
                frame.dma.src = module->data + offset;
                frame.dma.dst = staging + offset;
                frame.dma.size = chunk;
                frame.dma.attr = 0;
                FlushCache(0);
                while (sceSifSetDma(&frame.dma, 1) == 0) {
                }
                remaining -= chunk;
                offset += chunk;
            } while (remaining != 0);
        }
        while (sceSifLoadModule(staging, module->argumentLength, module->arguments) < 0) {
        }
        module = next;
    }
    func_00238D40(staging);
}
}
