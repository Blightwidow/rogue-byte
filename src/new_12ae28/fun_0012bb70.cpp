struct Key_12BB70 { char pad0[0xC]; float time; char pad10[0x10]; };
struct Acrb_12BB70 { int pad0; int count; Key_12BB70 *keys; };
extern "C" int func_0012BB70(Acrb_12BB70 *pacrb, float time) {
    int last = pacrb->count - 1;
    int index;
    for (index = 1; index < last; index++) {
        if (time < pacrb->keys[index].time)
            break;
    }
    return index;
}
