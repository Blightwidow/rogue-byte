struct PLO1CB410 { int kind; int *ids; int count; int start; };
struct OBJ1CB410 { char pad[0xE0]; PLO1CB410 *plo; };
extern "C" int PleaseFromIclone(OBJ1CB410 *, int, PLO1CB410 *, OBJ1CB410 *);
extern "C" int PleaseFromPlo(OBJ1CB410 *obj, int id)
{
    PLO1CB410 *plo = obj->plo;
    if (plo->kind != 1)
        return 0;
    int result = 0;
    int index = plo->start;
    while (index < plo->count) {
        if (id != plo->ids[index]) {
            index++;
            continue;
        }
        result = PleaseFromIclone(obj, index, plo, obj);
        break;
    }
    return result;
}
