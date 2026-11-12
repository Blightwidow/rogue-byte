#include "sly2.h"
#include "vu0inline.h"
struct V3_1BE6F0 { char xy[8]; int z; };
struct V4_1BE6F0 { V3_1BE6F0 v; float w; };
struct Camobj { char pad[0x118]; Camobj *parent; float fov; float nearPlane; float farPlane; };
struct Window { int width; int height; char pad[8]; int originX; int originY; char pad1[8]; Camobj *camobj; };
struct M4 { QW row[4]; };
struct Locals1BE6F0 { QW copy[3]; QW negZ; QW negX; QW rowY; M4 mat; QW negone; };
extern "C" {
QW PosLoWorld(void *);
QW *PmatLoWorld(void *);
void __as__6VECTORG9VU_VECTOR(void *, QW);
float tanf(float);
void BuildSimpleProjectionMatrix__FffffffP7MATRIX4(M4 *, float, float, float, float, float, float);
void CombineEyeLookAtProj(M4 *, M4 *, M4 *);
int AddDmaCnt__4DMAS(void *);
int AddVifFlush__4VIFS(void *);
void AddVifDirect__4VIFSiP2QWi(void *, int, int, void *);
int AddVifFlusha__4VIFS(void *);
void AddVifBaseOffset__4VIFSii(void *, int, int);
void AddVifUnpack__4VIFS3UPKiPvi(void *, int, int, void *, int);
void EndDmaCnt__4DMAS(void *);
extern char D_002C1F00[];
extern char D_002C1F10[];
void func_001BE6F0(Window *window, void *vifs)
{
    if (window->camobj) {
        Camobj *parent = window->camobj->parent;
        Camobj *camobj = parent ? parent : window->camobj;
        QW *m = PmatLoWorld(camobj);
        Locals1BE6F0 l;
        M4 *mat = &l.mat;
        QW row0 = m[0];
        QW negone = VectorFromFloat(-1.0f);
        l.copy[0] = row0;
        QW row1 = m[1];
        l.copy[1] = row1;
        QW negX = VectorScaleX(row0, negone);
        QW row2 = m[2];
        QW negZ = VectorScaleX(row2, negone);
        l.rowY = row1;
        l.negone = negone;
        l.negZ = negZ;
        l.negX = negX;
        l.copy[2] = row2;
        QW pos = PosLoWorld(camobj);
        __as__6VECTORG9VU_VECTOR(&mat->row[3], pos);
        mat->row[0] = l.negZ;
        float aspect = (float)window->width / (float)window->height;
        mat->row[1] = l.negX;
        mat->row[2] = l.rowY;
        ((int *)&l.mat.row[2])[3] = 0;
        ((int *)&l.mat.row[1])[3] = 0;
        ((int *)&l.mat.row[0])[3] = 0;
        ((float *)&mat->row[3])[3] = 1.0f;
        float tangent = tanf(window->camobj->fov * 0.5f);
        M4 projection;
        M4 combined;
        V4_1BE6F0 params[2];
        BuildSimpleProjectionMatrix__FffffffP7MATRIX4(&projection, (float)window->width / (tangent * aspect * 4096.0f), (float)window->height / (tangent * 4096.0f), 0.0f, 0.0f, window->camobj->nearPlane, window->camobj->farPlane);
        CombineEyeLookAtProj(mat, &projection, &combined);
        Camobj *pc = window->camobj;
        float nearValue = pc->nearPlane;
        float farValue = pc->farPlane;
        params[0].v = *(V3_1BE6F0 *)D_002C1F00;
        float ratio = (nearValue + farValue) / (nearValue - farValue);
        float scale = pc->nearPlane * (1.0f - ratio);
        params[0].w = 1.0f / scale;
        params[1].v = *(V3_1BE6F0 *)D_002C1F10;
        params[1].w = -ratio / (pc->nearPlane * (1.0f - ratio));
        AddDmaCnt__4DMAS(vifs);
        AddVifFlush__4VIFS(vifs);
        AddVifDirect__4VIFSiP2QWi(vifs, window->originX, window->originY, 0);
        AddVifFlusha__4VIFS(vifs);
        AddVifBaseOffset__4VIFSii(vifs, 0, 0);
        AddVifUnpack__4VIFS3UPKiPvi(vifs, 0xC, 4, &combined, 2);
        AddVifUnpack__4VIFS3UPKiPvi(vifs, 0xC, 4, mat, 6);
        AddVifUnpack__4VIFS3UPKiPvi(vifs, 0xC, 2, params, 0);
        AddVifBaseOffset__4VIFSii(vifs, 0x32, 0x1E7);
        EndDmaCnt__4DMAS(vifs);
    }
}
}
