struct Key_12B6D8 { char pad0[0xC]; float time; char pad10[0x20]; };
struct Acrb_12B6D8 { int pad0; int count; Key_12B6D8 *keys; };
extern "C" int IkeyFindAcrb(Acrb_12B6D8 *pacrb, float time) {
    int last = pacrb->count - 1;
    int index;
    for (index = 1; index < last; index++) {
        if (time < pacrb->keys[index].time)
            break;
    }
    return index;
}
