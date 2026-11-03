#include "sly2.h"
struct Cand_172798 { QW pos; char pad[0x10 - 0x10]; };
struct Search_172798 {
    QW pos1;                    /* 0x0 */
    char pad10[0x10 - 0x10];
};
struct Entry_172798 { QW pos; float heading; char pad[0xC]; };
struct Owner_172798 {
    QW source;                  /* 0x0 */
    char pad0[0x10 - 0x10];
    float baseHeading;          /* 0x10 */
    unsigned count;             /* 0x14 */
    char pad1[0x20 - 0x18];
    Entry_172798 entries[0x40]; /* 0x20 */
    char pad2[0x820 - 0x20 - 0x40 * 0x20];
    QW target;                  /* 0x820 */
};
extern "C" {
void DecomposeSphere(QW, float *, float *, float *);
int FCheckLm__FP2LMf(const void *, float);
float RadNormalize__Ff(float);
extern const char RO_002A53C0[];
extern const char RO_002A53C8[];
int FAddSearchCand(Owner_172798 *self)
{
    float parts[3];
    int fenceDelta;
    asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyzw vf3, vf2, vf1" : "=r"(fenceDelta) : "m"(self->target), "m"(self->source));
    QW delta;
    asm("qmfc2.ni %0, vf3" : "=r"(delta) : "r"(fenceDelta));
    DecomposeSphere(delta, &parts[0], &parts[1], &parts[2]);
    if (FCheckLm__FP2LMf(RO_002A53C0, parts[2]) == 0)
        return 0;
    if (FCheckLm__FP2LMf(RO_002A53C8, parts[1]) == 0)
        return 0;
    unsigned index = self->count;
    if (index >= 0x40)
        return 0;
    Entry_172798 *entry = &self->entries[index];
    self->count = index + 1;
    entry->pos = self->target;
    float heading = RadNormalize__Ff(parts[0] - self->baseHeading);
    entry->heading = heading;
    if (heading < 0.0f)
        entry->heading = 6.2831855f - heading;
    return 1;
}
}
