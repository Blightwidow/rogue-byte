extern char B_002DEB30[];
struct Obj { char pad[0x124]; int a; int b; };
void func_00161F10(char *, int *, int, int *, int, int);
void Spawn_AddTask(Obj *self, int x, int y)
{
    func_00161F10(B_002DEB30, &self->b, 4, &self->a, x, y);
}
