struct B4 { char b[4]; };
struct SpriteBase { char pad[0x84]; };
struct Blot { char pad[0x84]; char *sprites; };
struct Char { int pad0; int type; Blot *blot; int padC; int id; int handle; };
struct Slot { char pad[0x30]; Char *chr; char pad34[0x24]; int iinst; };

extern "C" int IinstFindFreeSprite(void *);
extern "C" void PlaceSpriteInstance(void *, int, int, void *, B4 *, B4 *);
extern "C" void *func_001BEED8(int);
extern "C" int func_001BEB28(void *);

extern "C" void func_00215730(Char *chr, Slot *slot, void *xf, B4 *add, B4 *mul)
{
    slot->chr = chr;
    switch (chr->type) {
    case 4: {
        int iinst = IinstFindFreeSprite(chr->blot->sprites + chr->id * 0x30);
        slot->iinst = iinst;
        B4 localAdd = *add;
        B4 localMul = *mul;
        PlaceSpriteInstance(chr->blot->sprites + chr->id * 0x30, 0x314, iinst, xf, &localAdd, &localMul);
        break;
    }
    case 6:
        if (chr->id != -1) {
            void *object = func_001BEED8(chr->id);
            if (object) chr->handle = func_001BEB28(object);
        }
        break;
    }
}
