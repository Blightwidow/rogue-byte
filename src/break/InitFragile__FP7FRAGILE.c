struct Tail { float scale; int first; int second; };
struct Fragile { char pad0[0x170]; struct Tail tail; char pad17C[8]; float field184; };
void InitSo();
void InitFragile__FP7FRAGILE(struct Fragile *fragile) {
    struct Tail *tail;
    InitSo();
    tail = &fragile->tail;
    fragile->tail.scale = 1.0f;
    tail->first = 0;
    tail->second = 0;
    fragile->field184 = 100.0f;
}
