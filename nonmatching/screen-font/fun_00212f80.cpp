extern "C" void func_00218038(void *);
extern "C" void SeekSpriteInstanceTime(void *, float, int, int);

struct Inst { char pad[8]; short state; char pad2[14]; };
struct Label { char pad[0x14]; int id; };
struct Sprite { unsigned short labelCount; unsigned short instCount; Label *labels; Inst *insts; char pad[0x24]; };
struct Blot { char pad[0x80]; unsigned short spriteCount; unsigned short pad82; Sprite *sprites; };

static inline Sprite *SpriteAt(Blot *blot, int i) { return &blot->sprites[i]; }
static inline int LabelIdAt(Sprite *sprite, int j) { return sprite->labels[j].id; }

extern "C" void func_00212F80(float u, Blot *blot, int label)
{
    if (label == 0x314) {
        func_00218038(blot->sprites);
        return;
    }
    for (int i = 0; i < blot->spriteCount; i++) {
        Sprite *sprite = SpriteAt(blot, i);
        for (int j = 0; j < sprite->labelCount; j++) {
            if (label == LabelIdAt(sprite, j)) {
                int last = -1;
                for (int k = 0; k < sprite->instCount; k++) {
                    if (sprite->insts[k].state != -1) last = k;
                }
                if (last >= 0) SeekSpriteInstanceTime(sprite, u, last, 0);
            }
        }
    }
}
