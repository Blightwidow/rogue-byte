typedef int QW __attribute__((mode(TI)));
struct M3 { QW row[3]; };
struct CAM { char pad0[0x14]; void *ptarget; char pad18[0xA4 - 0x18]; float pan; float tilt; };
union Lanes { QW whole; float lane[4]; };
struct L { Lanes dir; QW junk; M3 mat; QW offset; QW spill; };
extern "C" {
QW PosLoWorld(void *);
QW bevy_classes_k30_cam_150780(CAM *);
float atan2f(float, float);
M3 *LoadRotateMatrixPanTilt(M3 *, float, float);
extern QW RO_002A5000;
// float to lane 0 of a QW, and back
static inline float LaneZero(QW q) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(q)); return f; }
static inline QW WordOf(float f) { QW q; asm("mfc1 %0, %1" : "=r"(q) : "f"(f)); return q; }
QW bevy_classes_k30_cam_1507f8(CAM *pcam)
{
    L l;
    void *ptarget = pcam->ptarget;
    if (ptarget != 0) {
        QW posTarget = PosLoWorld(ptarget);
        asm volatile("qmtc2.ni %1, vf1\n\tsqc2 vf1, %0" : "=m"(l.spill) : "r"(posTarget));
        QW posCam = bevy_classes_k30_cam_150780(pcam);
        asm volatile("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2\n\tvsub.xyzw vf1, vf1, vf2\n\tvmul.xyz vf2, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tvsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf2, vf1, Q\n\tsqc2 vf2, %0" : "=m"(l.dir) : "r"(posCam), "m"(l.spill));
        pcam->pan = atan2f(l.dir.lane[1], l.dir.lane[0]);
        QW posCam2 = bevy_classes_k30_cam_150780(pcam);
        QW lengthBits;
        asm volatile("lqc2 vf2, %1\n\tlqc2 vf1, 0(%2)\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmtc2.ni %3, vf3\n\tqmfc2.ni %0, vf1" : "=r"(lengthBits) : "m"(l.dir), "r"(&RO_002A5000), "r"(posCam2));
        QW negatedBits = WordOf(-LaneZero(lengthBits));
        asm volatile("qmtc2.ni %1, vf1\n\tvmulx.xyzw vf2, vf2, vf1x\n\tsqc2 vf1, %0\n\tvadd.xyzw vf1, vf3, vf2" : "=m"(l.junk) : "r"(negatedBits));
    } else {
        l.offset = RO_002A5000;
        LoadRotateMatrixPanTilt(&l.mat, pcam->pan, pcam->tilt);
        QW posCam = bevy_classes_k30_cam_150780(pcam);
        asm volatile("lqc2 vf2, %1\n\tlqc2 vf3, %2\n\tlqc2 vf1, %3\n\tlqc2 vf4, %4\n\tvmulax.xyz ACC, vf3, vf4x\n\tvmadday.xyz ACC, vf2, vf4y\n\tvmaddz.xyz vf1, vf1, vf4z\n\tqmtc2.ni %0, vf2\n\tvadd.xyzw vf1, vf2, vf1" : : "r"(posCam), "m"(l.mat.row[1]), "m"(l.mat.row[0]), "m"(l.mat.row[2]), "m"(l.offset));
    }
    QW result;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(result));
    return result;
}
}
