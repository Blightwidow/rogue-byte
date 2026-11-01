// SPDX-License-Identifier: GPL-3.0-or-later
struct JT { char pad[0x18]; };
extern "C" void SetJtState(JT *, int, int);
void SetJtStateFromKind(JT *pjt, unsigned int nKind)
{
    switch (nKind) {
    case 0: SetJtState(pjt, 0, -1); break;
    case 1: SetJtState(pjt, 2, -1); break;
    case 2: SetJtState(pjt, 7, -1); break;
    case 3: SetJtState(pjt, 4, -1); break;
    case 4: SetJtState(pjt, 0x12, -1); break;
    case 5: SetJtState(pjt, 0x13, -1); break;
    case 6: SetJtState(pjt, 0x14, -1); break;
    case 7: SetJtState(pjt, 0x17, -1); break;
    case 8: SetJtState(pjt, 8, -1); break;
    }
}
