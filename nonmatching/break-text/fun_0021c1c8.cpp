#include "sly2.h"
extern "C" {
struct Trail21C1C8;
struct VT21C1C8 { char padF8[0xF8]; short deltaF8; short padFA; MATRIX4 *(*fnFC)(char *, int); };
struct Entry21C1C8 { float time; float scale; float distance; char pad0C[4]; MATRIX4 matrix; };
struct Trail21C1C8 {
    char pad0[0xC]; VT21C1C8 *vt;
    char pad10[0x12C - 0x10]; float speed;
    char pad130[0x154 - 0x130]; int fPaused; int count; Entry21C1C8 *entries; int head; int stillFrames;
    char pad168[0x180 - 0x168]; char *target; float length; float travelled; char pad18C[4]; QW lastPos;
};
extern float g_2dded0[];
void ProjectSoTransform();
QW PosLoWorld(char *);
void func_0021C5F8(Trail21C1C8 *, QW);
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
void func_0021C1C8(Trail21C1C8 *trail)
{
    ProjectSoTransform();
    if (trail->fPaused != 0) return;
    int slot = trail->head;
    int next = slot + 1;
    trail->head = next % trail->count;
    Entry21C1C8 *entry = (Entry21C1C8 *)((char *)trail->entries + slot * 0x50);
    entry->time = g_2dded0[0];
    entry->scale = trail->speed;
    MATRIX4 *source = trail->vt->fnFC((char *)trail + trail->vt->deltaF8, 0x50);
    entry->matrix = *source;
    if (trail->speed <= 0.0f) trail->stillFrames = trail->stillFrames + 1;
    else trail->stillFrames = 0;
    if (trail->target != 0) {
        if (trail->speed == 0.0f) trail->travelled = -4.0f;
        QW pos = PosLoWorld(trail->target);
        asm volatile("qmtc2.ni %0, vf2" : : "r"(pos));
        asm volatile("lqc2 vf1, 0x190(%0)" : : "r"(trail));
        asm volatile("vsub.xyzw vf1, vf1, vf2");
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf3, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf3, vf1z");
        asm volatile("sqc2 vf2, 0x190(%0)" : : "r"(trail));
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        QW lane;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(lane));
        float total = trail->travelled + Lane(lane) / trail->length;
        trail->travelled = total;
        entry->distance = total;
    }
    func_0021C5F8(trail, PosLoWorld((char *)trail));
}
}
