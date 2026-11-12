#include "ps2inline.h"
typedef struct {
    u64 pmode;
    u64 smode2;
    u64 dispfb;
    u64 display;
    u64 bgcolor;
} DispEnv;
typedef struct {
    u64 NLOOP : 15;
    u64 EOP : 1;
    u64 pad16 : 44;
    u64 NREG : 4;
    u64 REGS0 : 4;
    u64 REGSrest : 60;
} GifTag;
typedef struct {
    u64 frame1;
    u64 pad[15];
} DrawEnv;
typedef struct {
    u64 pad[12];
} ClearEnv;
typedef struct {
    DispEnv disp[2];
    GifTag giftag0;
    DrawEnv draw0;
    ClearEnv clear0;
    GifTag giftag1;
    DrawEnv draw1;
    ClearEnv clear1;
} DBuff;

extern u64 *func_002405F0(void);
extern int sceGsSetDefDispEnv(DispEnv *env, short psm, short width, short height, short dx, short dy);
extern int sceGsSetDefDrawEnv(DrawEnv *env, short psm, short width, short height, short ztest, short zpsm);
extern int sceGsSetDefClear(ClearEnv *env, short ztest, short x, short y, short width, short height, int red, int green, int blue, int alpha, int depth);
extern short sceGszbufaddr(short psm, short width, short height);

void sceGsSetDefDBuff(DBuff *db, short psm, short width, short height, short ztest, short zpsm, short clear)
{
    u64 *revision = func_002405F0();
    int zaddr;
    sceGsSetDefDispEnv(&db->disp[0], psm, width, height, 0, 0);
    sceGsSetDefDispEnv(&db->disp[1], psm, width, height, 0, 0);
    sceGsSetDefDrawEnv(&db->draw0, psm, width, height, ztest, zpsm);
    sceGsSetDefDrawEnv(&db->draw1, psm, width, height, ztest, zpsm);
    if (clear != 0) {
        short x = 0x800 - (width >> 1);
        short y = 0x800 - (height >> 1);
        sceGsSetDefClear(&db->clear0, ztest, x, y, width, height, 0, 0, 0, 0, 0);
        sceGsSetDefClear(&db->clear1, ztest, x, y, width, height, 0, 0, 0, 0, 0);
    }
    *(QW *)&db->giftag0 = 0;
    *(QW *)&db->giftag1 = 0;
    db->giftag0.NLOOP = clear ? 0xE : 8;
    db->giftag0.EOP = 1;
    db->giftag0.NREG = 1;
    db->giftag0.REGS0 = 0xE;
    db->giftag1.NLOOP = clear ? 0xE : 8;
    db->giftag1.EOP = 1;
    db->giftag1.NREG = 1;
    db->giftag1.REGS0 = 0xE;
    zaddr = sceGszbufaddr(psm, width, height);
    if (0x100000001UL == (*revision & 0xFFFF0000FFFFUL) || (short)*revision == 0) {
        short zbuf;
        zaddr >>= 1;
        zbuf = zaddr;
        db->disp[1].dispfb = (db->disp[1].dispfb & ~0x1FFUL) | (zbuf & 0x1FF);
        db->draw0.frame1 = (db->draw0.frame1 & ~0x1FFUL) | (zaddr & 0x1FF);
    }
}
