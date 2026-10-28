#include "sly2.h"
struct Obj { char pad[0x74]; int pruned; };
extern "C" void ClsgClipEdgeToObjectPruned(Obj *, int, QW, QW, int, int);
void ClsgClipEdgeToObject(Obj *self, QW a, QW b, int c, int d)
{
    ClsgClipEdgeToObjectPruned(self, self->pruned, a, b, c, d);
}
