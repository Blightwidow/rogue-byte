struct Pair { int first; int second; };
struct Holder { char pad[0x150]; int count; Pair *items; };
extern "C" void AddStgSwitchClass(Holder *self, int first, int second)
{
 int n = self->count; if (n < 8) { Pair *e = self->items + n; self->count = n + 1; e->first = first; e->second = second; }
}
