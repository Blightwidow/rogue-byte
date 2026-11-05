struct Label217BA0 { char pad[0x14]; int id; };
struct Sprite217BA0 { unsigned short labelCount; unsigned short pad2; Label217BA0 *labels; char pad8[0x20]; int active; };
extern "C" {
void PlayRootSpriteLabelIndex(Sprite217BA0 *, int, int);

void PlayRootSpriteLabel(Sprite217BA0 *sprite, int label) {
    if (sprite->active) {
        int index = 0;
        if (label != 0x314) {
                        for (index = 0; index < sprite->labelCount; index++) {
                if (label == sprite->labels[index].id) break;
            }
            if (index >= sprite->labelCount) index = 0;
        }
        PlayRootSpriteLabelIndex(sprite, index, label);
    }
}
}
