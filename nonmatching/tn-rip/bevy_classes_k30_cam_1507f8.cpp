typedef int QW __attribute__((mode(TI)));
struct M3 { QW row[3]; };
struct CAM { char pad0[0x14]; void *ptarget; char pad18[0xA4 - 0x18]; float pan; float tilt; };
union Lanes { QW whole; float lane[4]; };
extern "C" {
QW PosLoWorld(void *);
QW bevy_classes_k30_cam_150780(CAM *);
float atan2f(float, float);
M3 *LoadRotateMatrixPanTilt(M3 *, float, float);
extern QW RO_002A5000;
// float to lane 0 of a QW, and back
static inline float LaneZero(QW q) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(q)); return f; }
static inline QW WordOf(float f) { QW q; asm("mfc1 %0, %1" : "=r"(q) : "f"(f)); return q; }
static inline QW Length_1507F8(QW v)
{
    QW sq, one;
    asm("vmul.xyz %0, %2, %2\n\tvaddw.x %1, vf0, vf0w\n\tvadday.x ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z" : "=j"(sq), "=j"(one) : "j"(v));
    QW len;
    asm("vsqrt Q, %1x\n\tvwaitq\n\tvaddq.x %0, vf0, Q" : "=j"(len) : "j"(sq));
    return len;
}
static inline QW Normalize_1507F8(QW v)
{
    QW len = Length_1507F8(v);
    QW r;
    asm("vdiv Q, vf0w, %2x\n\tvwaitq\n\tvmulq.xyzw %0, %1, Q" : "=j"(r) : "j"(v), "j"(len));
    return r;
}
QW bevy_classes_k30_cam_1507f8(CAM *pcam)
{
    QW result;
    void *ptarget = pcam->ptarget;
    if (ptarget != 0) {
        Lanes dir;
        QW junk[1]; // stack area retail stores the negated length into, never read
        QW posTarget = PosLoWorld(ptarget);
        QW posCam = bevy_classes_k30_cam_150780(pcam);
        QW delta;
        asm("vsub.xyzw %0, %1, %2" : "=j"(delta) : "j"(posTarget), "j"(posCam));
        QW vdir = Normalize_1507F8(delta);
        dir.whole = vdir;
        pcam->pan = atan2f(dir.lane[1], dir.lane[0]);
        QW posCam2 = bevy_classes_k30_cam_150780(pcam);
        QW offset = RO_002A5000;
        QW dist = Length_1507F8(offset);
        QW neg = WordOf(-LaneZero(dist));
        QW scaled;
        asm("vmulx.xyzw %0, %2, %3x\n\tsqc2 %3, %1" : "=j"(scaled), "=m"(junk[0]) : "j"(dir.whole), "j"(neg));
        asm("vadd.xyzw %0, %1, %2" : "=j"(result) : "j"(posCam2), "j"(scaled));
    } else {
        M3 mat;
        QW offset = RO_002A5000;
        LoadRotateMatrixPanTilt(&mat, pcam->pan, pcam->tilt);
        QW posCam = bevy_classes_k30_cam_150780(pcam);
        QW rotated;
        asm("vmulax.xyz ACC, %1, %4x\n\tvmadday.xyz ACC, %2, %4y\n\tvmaddz.xyz %0, %3, %4z" : "=j"(rotated) : "j"(mat.row[0]), "j"(mat.row[1]), "0"(mat.row[2]), "j"(offset));
        asm("vadd.xyzw %0, %1, %2" : "=j"(result) : "j"(posCam), "j"(rotated));
    }
    return result;
}
}
