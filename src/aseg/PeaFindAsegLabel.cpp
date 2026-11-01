struct ASEGL_12F938 { int pad0; int kind; int id; int pad3; };
struct ASEG_12F938 { char pad[0xA0]; int count; ASEGL_12F938 *labels; };
extern "C" ASEGL_12F938 *PeaFindAsegLabel(ASEG_12F938 *paseg, int id)
{
    for (int i = 0; i < paseg->count; i++) {
        ASEGL_12F938 *p = &paseg->labels[i];
        if ((p->kind == 11) & (p->id == id))
            return p;
    }
    return 0;
}