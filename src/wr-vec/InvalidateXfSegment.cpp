struct OBJ_22C840;
struct VT_22C840 { char pad[0x178]; short delta; short pad2; void (*fn)(void *, int); };
struct OBJ_22C840 { char pad[0xC]; VT_22C840 *vt; };
struct XFSEG_22C840 { char pad[0x80]; float lo0; float lo1; int *p0; int *p1; char padx[8]; short kind; short flag; };
extern int D_002C44E0[];
extern "C" void InvalidateXfSegment(OBJ_22C840 *obj, XFSEG_22C840 *seg);
extern "C" void InvalidateXfSegment(OBJ_22C840 *obj, XFSEG_22C840 *seg)
{
    switch (seg->kind) {
    case 0: case 1: case 2: case 3:
    case 13: case 14: case 15: case 16:
    case 20: case 21:
        break;
    default:
        seg->lo1 = -3.4028235e38f;
        seg->p1 = D_002C44E0;
        seg->lo0 = -3.4028235e38f;
        seg->p0 = D_002C44E0;
        break;
    }
    seg->flag = 0;
    VT_22C840 *vt = obj->vt;
    vt->fn((char *)obj + vt->delta, 4);
}
