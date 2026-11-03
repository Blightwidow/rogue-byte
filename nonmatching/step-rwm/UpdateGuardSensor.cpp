#include "sly2.h"
struct Cand_206900 { float dist; int *group; char *other; int f0C; float f10; int pad14; };
struct Entry_206900 { char *object; int f4; float f8; int padC; };
struct Sensor_206900 { char pad[0xFC]; int count; Entry_206900 entries[1]; };
struct Guard_206900 {
    char pad0[0x2C0]; long grfsgs; char pad2C8[0x394 - 0x2C8];
    int cgroup; int agroup[3]; int csensed; char pad3A8[0x3CC - 0x3A8];
    char *ptarget; char pad3D0[0xF64 - 0x3D0];
    Sensor_206900 *psensor;
};
struct Frame_206900 { Cand_206900 acand[0x40]; char *aplo[0x100]; QW posTarget; QW posSelf; };
extern "C" {
int AddGuardSensedObject(Guard_206900 *, char *, int *);
int CploFindSwObjectsByClass(void *, int, int, void *, int, char **);
long GrfsgsFromSgs(int);
Entry_206900 *PentryFindSensorLo(Sensor_206900 *, char *);
QW PosLoWorld(void *);
int SetAlertState(char *, int);
void func_00153DE0(Sensor_206900 *);
void qsort(void *, int, int, int (*)(const void *, const void *));
int func_002068D8(const void *, const void *);
extern long B_003DD480;
extern int B_003DD488;
extern char B_003DD490;
extern float RO_002C3D04[3];
}
extern "C" void UpdateGuardSensor(Guard_206900 *guard)
{
    Frame_206900 frame;
    if (B_003DD488 == 0) {
        long a = GrfsgsFromSgs(5);
        long b = GrfsgsFromSgs(6);
        long c = GrfsgsFromSgs(0x17);
        long d = GrfsgsFromSgs(7);
        long e = GrfsgsFromSgs(0x10);
        long f = GrfsgsFromSgs(1);
        long g = GrfsgsFromSgs(0x16);
        long h = GrfsgsFromSgs(0x2A);
        B_003DD488 = 1;
        B_003DD480 = a | b | c | d | e | f | g | h;
    }
    if (guard->grfsgs & B_003DD480)
        return;
    if (guard->cgroup != 0) {
        int count = 0;
        for (int igroup = 0; igroup < guard->cgroup; igroup++) {
            int *group = &guard->agroup[igroup];
            int cplo = CploFindSwObjectsByClass(&B_003DD490, 0x505, *group, 0, 0x100, frame.aplo);
            for (int iplo = 0; iplo < cplo; iplo++) {
                char *other = frame.aplo[iplo];
                if (other == (char *)guard)
                    continue;
                int fenceA, fenceB;
                QW posSelf = PosLoWorld(guard);
                asm("qmtc2.ni %1, vf1" : "=r"(fenceA) : "r"(posSelf));
                asm("sqc2 vf1, %0" : "=m"(frame.posSelf) : "r"(fenceA));
                QW posOther = PosLoWorld(other);
                asm("qmtc2.ni %1, vf2" : "=r"(fenceA) : "r"(posOther));
                float distance;
                int bits;
                asm("lqc2 vf1, %2\n\tvsub.xyzw vf1, vf1, vf2\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %1, vf1\n\tmtc1 %1, %0\n\tnop" : "=f"(distance), "=r"(bits) : "m"(frame.posSelf), "r"(fenceA));
                if (distance < RO_002C3D04[0] && (unsigned)count < 0x40) {
                    Cand_206900 *cand = &frame.acand[count];
                    Sensor_206900 *sensor = guard->psensor;
                    cand->dist = distance;
                    cand->f0C = -1;
                    cand->group = group;
                    cand->other = other;
                    cand->f10 = -3.4028235e38f;
                    count++;
                    for (int ientry = sensor->count - guard->csensed; ientry < guard->psensor->count; ientry++) {
                        Entry_206900 *entry = &guard->psensor->entries[ientry];
                        if (entry->object == cand->other) {
                            cand->f0C = entry->f4;
                            cand->f10 = entry->f8;
                            break;
                        }
                    }
                }
            }
        }
        qsort(frame.acand, count, 0x18, func_002068D8);
        guard->psensor->count -= guard->csensed;
        guard->csensed = 0;
        if (count > 0) {
        Cand_206900 *cand = frame.acand;
        do {
            if (AddGuardSensedObject(guard, cand->other, cand->group) != 0) {
                int f0C = cand->f0C;
                guard->csensed++;
                if (f0C != -1) {
                    Entry_206900 *last = &guard->psensor->entries[guard->psensor->count - 1];
                    last->f4 = f0C;
                    last->f8 = cand->f10;
                }
            }
            count--;
            cand++;
        } while (count != 0);
        }
    }
    func_00153DE0(guard->psensor);
    if (guard->ptarget == 0)
        return;
    Entry_206900 *hit = PentryFindSensorLo(guard->psensor, *(char **)(guard->ptarget + 0xC));
    if (hit == 0)
        return;
    switch (hit->f4) {
    case 1:
        SetAlertState(guard->ptarget, 1);
        break;
    case 2: {
        frame.posTarget = PosLoWorld(*(char **)(guard->ptarget + 0xC));
        QW posSelf = PosLoWorld(guard);
        int near = 0;
        int fenceA, fenceB;
        asm("lqc2 vf1, %1" : "=r"(fenceA) : "m"(frame.posTarget));
        asm("qmtc2.ni %1, vf3\n\tvsub.xyzw vf2, vf1, vf3" : "=r"(fenceB) : "r"(posSelf), "r"(fenceA));
        asm("vmul.xy vf1, vf2, vf2\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r"(fenceA) : "r"(fenceB));
        float distance;
        int bits;
        asm("qmfc2.ni %1, vf1\n\tmtc1 %1, %0\n\tnop" : "=f"(distance), "=r"(bits) : "r"(fenceA));
        if (distance < RO_002C3D04[1]) {
            QW dpos;
            asm("qmfc2.ni %0, vf2" : "=r"(dpos) : "r"(fenceA));
            float zBits;
            asm("pextuw %0, $0, %1" : "=r"(zBits) : "r"(dpos));
            float dz;
            asm("mtc1 %1, %0\n\tnop" : "=f"(dz) : "r"(zBits));
            if (__builtin_fabsf(dz) < RO_002C3D04[2])
                near = 1;
        }
        if (near != 0)
            SetAlertState(guard->ptarget, 2);
        break;
    }
    }
}
