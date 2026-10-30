#include "sly2.h"
extern "C" {
struct Cand_206900 { float dist; int *source; char *other; int f0C; float f10; int pad14; };
struct Entry_206900 { char *object; int f4; float f8; int padC; };
struct Sensor_206900 { char pad[0xFC]; int count; Entry_206900 entries[1]; };
int AddGuardSensedObject(char *, char *, int *);
int CploFindSwObjectsByClass(void *, int, int, int);
long GrfsgsFromSgs(int);
Entry_206900 *PentryFindSensorLo(Sensor_206900 *, char *);
QW PosLoWorld(char *);
int SetAlertState(char *, int);
void func_00153DE0(Sensor_206900 *);
void qsort(void *, int, int, void *);
extern long B_003DD480;
extern int B_003DD488;
extern char B_003DD490;
extern float D_FLT_002C3D04;
extern float D_FLT_002C3D08;
extern float D_FLT_002C3D0C;
extern char func_002068D8;
void UpdateGuardSensor(char *arg0) {
    char sp[0xA20] __attribute__((aligned(16)));
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
    if (!(*(long *)(arg0 + 0x2C0) & B_003DD480)) {
        if (*(int *)(arg0 + 0x394) != 0) {
            int groupIndex = 0;
            unsigned int count = 0;
            if (*(int *)(arg0 + 0x394) > 0) {
                char **found = (char **)(sp + 0x600);
                do {
                    int *group = (int *)(arg0 + groupIndex * 4 + 0x398);
                    int total = CploFindSwObjectsByClass(&B_003DD490, 0x505, *group, 0);
                    int index = 0;
                    if (total > 0) {
                        do {
                            char *other = found[index];
                            if (other != arg0) {
                                asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(arg0)));
                                asm volatile("sqc2 vf1, 0xa10(%0)" : : "r"(sp));
                                asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(other)));
                                asm volatile("lqc2 vf1, 0xa10(%0)" : : "r"(sp));
                                asm volatile("vsub.xyzw vf1, vf1, vf2");
                                asm volatile("vmul.xy vf1, vf1, vf1");
                                asm volatile("vaddy.x vf1, vf1, vf1y");
                                asm volatile("vsqrt Q, vf1x");
                                asm volatile("vwaitq");
                                asm volatile("vaddq.x vf1, vf0, Q");
                                int distanceBits;
                                asm volatile("qmfc2.ni %0, vf1" : "=r"(distanceBits));
                                float distance = *(float *)&distanceBits;
                                if ((distance < D_FLT_002C3D04) && (count < 0x40U)) {
                                    Sensor_206900 *sensor = *(Sensor_206900 **)(arg0 + 0xF64);
                                    Cand_206900 *candidate = &((Cand_206900 *)sp)[count];
                                    candidate->dist = distance;
                                    candidate->f0C = -1;
                                    candidate->source = group;
                                    candidate->other = other;
                                    candidate->f10 = -3.4028235e38f;
                                    int sensorCount = sensor->count;
                                    int scan = sensorCount - *(int *)(arg0 + 0x3A4);
                                    count += 1;
                                    for (; scan < sensorCount; scan++) {
                                        Entry_206900 *entry = &(*(Sensor_206900 **)(arg0 + 0xF64))->entries[scan];
                                        if (entry->object == candidate->other) {
                                            candidate->f0C = entry->f4;
                                            candidate->f10 = entry->f8;
                                            break;
                                        }
                                        sensorCount = (*(Sensor_206900 **)(arg0 + 0xF64))->count;
                                    }
                                }
                            }
                            index += 1;
                        } while (index < total);
                    }
                    groupIndex += 1;
                } while (groupIndex < *(int *)(arg0 + 0x394));
            }
            qsort(sp, (int)count, 0x18, &func_002068D8);
            Sensor_206900 *sensorAfter = *(Sensor_206900 **)(arg0 + 0xF64);
            sensorAfter->count = sensorAfter->count - *(int *)(arg0 + 0x3A4);
            *(int *)(arg0 + 0x3A4) = 0;
            if ((int)count > 0) {
                Cand_206900 *cursor = (Cand_206900 *)sp;
                do {
                    if (AddGuardSensedObject(arg0, cursor->other, cursor->source) != 0) {
                        int f0C = cursor->f0C;
                        *(int *)(arg0 + 0x3A4) = *(int *)(arg0 + 0x3A4) + 1;
                        if (f0C != -1) {
                            Sensor_206900 *sensor = *(Sensor_206900 **)(arg0 + 0xF64);
                            Entry_206900 *last = &sensor->entries[sensor->count - 1];
                            last->f4 = f0C;
                            last->f8 = cursor->f10;
                        }
                    }
                    count -= 1;
                    cursor += 1;
                } while (count != 0);
            }
        }
        func_00153DE0(*(Sensor_206900 **)(arg0 + 0xF64));
        char *target = *(char **)(arg0 + 0x3CC);
        Entry_206900 *hit;
        if ((target != 0) && (hit = PentryFindSensorLo(*(Sensor_206900 **)(arg0 + 0xF64), *(char **)(target + 0xC)), (hit != 0))) {
            switch (hit->f4) {
            case 1:
                SetAlertState(*(char **)(arg0 + 0x3CC), 1);
                break;
            case 2: {
                *(QW *)(sp + 0xA00) = PosLoWorld(*(char **)(*(char **)(arg0 + 0x3CC) + 0xC));
                asm volatile("lqc2 vf1, 0xa00(%0)" : : "r"(sp));
                int near = 0;
                asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(arg0)));
                asm volatile("vsub.xyzw vf2, vf1, vf3");
                asm volatile("vmul.xy vf1, vf2, vf2");
                asm volatile("vaddy.x vf1, vf1, vf1y");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                float dz;
                asm volatile("qmfc2.ni $2, vf2\n\tpextuw $2, $0, $2\n\tmtc1 $2, %0" : "=f"(dz) : : "$2");
                int distanceBits;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(distanceBits));
                if ((*(float *)&distanceBits < D_FLT_002C3D08) && (__builtin_fabsf(dz) < D_FLT_002C3D0C)) {
                    near = 1;
                }
                if (near != 0) {
                    SetAlertState(*(char **)(arg0 + 0x3CC), 2);
                }
                break;
            }
            }
        }
    }
}
}
