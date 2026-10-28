#include "sly2.h"
struct Obj { char pad[0x134]; int a; int b; };
extern char B_002DEB30[];
void func_00161F10(char *, int *, int, int *, int, int);
void func_00148B78(Obj *self, int x, int y)
{
    func_00161F10(B_002DEB30, &self->b, 4, &self->a, x, y);
}
