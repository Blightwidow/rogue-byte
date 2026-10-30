typedef int QW __attribute__((mode(TI)));
struct B4 { char b[4]; };

struct Char { int pad0; int type; int pad8; int padC; int sprite; };
struct Slot { B4 add; B4 mul; char pad[8]; QW mat0; QW mat1; Char *chr; char pad34[0x24]; int instIndex; char pad5c[0x14]; };
struct Inst { int count; Slot *slots; int pad[4]; };
struct Sprite { int pad0; int pad4; Inst *insts; char pad[0x24]; };
struct Root { char pad[0x84]; Sprite *sprites; };

extern "C" int FGetSpriteSlotTransform(Root *blot, int isprite, QW *mat, B4 *add, B4 *mul, int count, Slot *slots)
{
    if (slots == 0) {
        Inst *root = blot->sprites->insts;
        count = root->count;
        slots = root->slots;
    }
    Slot *cur = slots;
    for (int i = 0; i < count; i++, cur++) {
        Char *chr = cur->chr;
        if (chr == 0 || chr->type != 4) continue;
        if (isprite == chr->sprite) {
            mat[0] = cur->mat0;
            mat[1] = cur->mat1;
            *add = cur->add;
            *mul = cur->mul;
            return 1;
        }
        Sprite * sp;
        sp = (__typeof__(&(blot->sprites)[0]))((chr->sprite) * sizeof((blot->sprites)[0]) + (unsigned)(blot->sprites));
        Inst *inst = (__typeof__(&(sp->insts)[0]))((cur->instIndex) * sizeof((sp->insts)[0]) + (unsigned)(sp->insts));
        if (FGetSpriteSlotTransform(blot, isprite, mat, add, mul, inst->count, inst->slots)) return 1;
    }
    return 0;
}
