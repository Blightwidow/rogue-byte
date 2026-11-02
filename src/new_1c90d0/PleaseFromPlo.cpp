struct PLO1CB410 { int kind; int *ids; int count; int start; };
struct OBJ1CB410 { char pad[0xE0]; PLO1CB410 *plo; };
extern "C" int PleaseFromIclone(OBJ1CB410 *, int);
extern "C" int PleaseFromPlo(OBJ1CB410 *obj, int id)
{
 if (obj->plo->kind != 1) return 0; int result = 0; int i = obj->plo->start; for (; i < obj->plo->count; i++) { if (id == obj->plo->ids[i]) { result = PleaseFromIclone(obj, i); break; } } return result;
}
