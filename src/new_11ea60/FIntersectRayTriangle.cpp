#include "sly2.h"
extern "C" int FIntersectRayTriangle(QW vecDir, QW posOrigin, QW posA, QW posB, QW posC, float *ps, float *pauv)
{
    QW frame[5];
    register int result asm("$2");
    register QW v6 asm("vf6");
    register QW v1 asm("vf1");
    register float f0 asm("$f0");
    asm("qmtc2.ni %3, vf6\n\tlui $1, 0xB586\n\tori $1, $1, 0x37BD\n\tmtc1 $1, $f0\n\tqmtc2.ni %4, vf1" : "=j" (v6), "=j" (v1), "=f" (f0) : "r" (posA), "r" (posC) : "$1");
    asm volatile("" : "=m" (frame[0]), "=m" (frame[1]), "=m" (frame[2]), "=m" (frame[3]), "=m" (frame[4]));
    asm volatile(".set noreorder\n\t.set noat\n\tvsub.xyzw vf4, vf1, vf6\n\tqmtc2.ni %1, vf7\n\tqmtc2.ni %3, vf1\n\tvopmula.xyz ACC, vf7, vf4\n\tvopmsub.xyz vf3, vf4, vf7\n\tvsub.xyzw vf2, vf1, vf6\n\tsqc2 vf4, 0x10($sp)\n\tvmul.xyz vf1, vf2, vf3\n\tvaddw.x vf5, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf5, vf1z\n\tsqc2 vf2, 0x0($sp)\n\tqmfc2.ni $2, vf1\n\tmtc1 $2, $f1\n\tqmtc2.ni %2, vf5\n\tc.lt.s $f0, $f1\n\tnop\n\tbc1f 1f\n\tsqc2 vf3, 0x20($sp)\n\tlui $1, 0x3586\n\tori $1, $1, 0x37BD\n\tmtc1 $1, $f0\n\tnop\n\tc.lt.s $f1, $f0\n\tnop\n\tbc1t 4f\n\tdaddu $2, $0, $0\n\t1:\n\tlui $1, 0x3F80\n\tmtc1 $1, $f4\n\tvsub.xyzw vf3, vf5, vf6\n\tlqc2 vf1, 0x20($sp)\n\tdiv.s $f3, $f4, $f1\n\tvmul.xyz vf1, vf3, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni $2, vf1\n\tmtc1 $0, $f5\n\tmtc1 $2, $f0\n\tnop\n\tmul.s $f2, $f0, $f3\n\tc.lt.s $f2, $f5\n\tnop\n\tbc1t 2f\n\tsqc2 vf3, 0x30($sp)\n\tc.lt.s $f4, $f2\n\tnop\n\tbc1t 4f\n\tdaddu $2, $0, $0\n\tlqc2 vf1, 0x0($sp)\n\tvopmula.xyz ACC, vf3, vf1\n\tvopmsub.xyz vf4, vf1, vf3\n\tvmul.xyz vf2, vf7, vf4\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tsqc2 vf4, 0x40($sp)\n\tqmfc2.ni $2, vf2\n\tmtc1 $2, $f0\n\tnop\n\tmul.s $f1, $f0, $f3\n\tc.lt.s $f1, $f5\n\tnop\n\tbc1t 4f\n\tdaddu $2, $0, $0\n\tadd.s $f0, $f2, $f1\n\tc.lt.s $f4, $f0\n\tnop\n\tbc1t 4f\n\tlqc2 vf1, 0x10($sp)\n\tvmul.xyz vf1, vf1, vf4\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni $2, vf1\n\tmtc1 $2, $f0\n\tnop\n\tmul.s $f0, $f0, $f3\n\tc.lt.s $f0, $f5\n\tnop\n\tbc1f 3f\n\tnop\n\t2:\n\tb 4f\n\tdaddu $2, $0, $0\n\t3:\n\tbnel %4, $0, 5f\n\tswc1 $f0, 0x0(%4)\n\t5:\n\tbeqz %5, 4f\n\taddiu $2, $0, 0x1\n\tswc1 $f1, 0x4(%5)\n\tswc1 $f2, 0x0(%5)\n\t4:\n\t.set at\n\t.set reorder"
        : "=r" (result) : "r" (vecDir), "r" (posOrigin), "r" (posB), "r" (ps), "r" (pauv), "j" (v6), "j" (v1), "f" (f0) : "$1", "$f0", "$f1", "$f2", "$f3", "$f4", "$f5", "memory");
    return result;
}
