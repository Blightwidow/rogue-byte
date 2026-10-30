struct DZ_11A770 {
    int pad0;
    float lo;
    float hi;
    float value;
    float b;
    float db;
    float *row;
    int pad1c;
    DZ_11A770 *next;
    DZ_11A770 *prev;
};
struct DL_11A770 {
    DZ_11A770 *head;
    int pad4;
    int pad8;
};
struct DZG_11A770 {
    int pad0;
    int count;
    DZ_11A770 *dzs;
    DL_11A770 listActive;
    DL_11A770 listLower;
    DL_11A770 listUpper;
    DL_11A770 listFree;
    int activeCount;
    float *matrix;
    float *lu;
    float *rhs;
    float *solution;
};
extern "C" {
extern const float RO_002A4120;
extern const float RO_002A4124;
void AppendDlEntry(DL_11A770 *, DZ_11A770 *);
void RemoveDlEntry(DL_11A770 *, DZ_11A770 *);
void CroutDecomp__FiPfT1(int, float *, float *);
void CroutSolve__FiPfN21(int, float *, float *, float *);
void EnforceDzgDz__FP3DZGP2DZ(DZG_11A770 *dzg, DZ_11A770 *pdz) {
    int iterations;
    int index;
    unsigned code;
    float step;
    float candidate;
    float delta;
    float sum;
    float *cursor;
    DZ_11A770 *outer;
    DZ_11A770 *inner;
    DZ_11A770 *hit;
    if (pdz != 0) {
        RemoveDlEntry(&dzg->listFree, pdz);
        AppendDlEntry(&dzg->listActive, pdz);
        dzg->activeCount++;
    }
    iterations = 0;
    for (;;) {
        cursor = dzg->matrix;
        for (outer = dzg->listActive.head; outer != 0; outer = outer->next) {
            for (inner = dzg->listActive.head; inner != 0; inner = inner->next) {
                *cursor++ = outer->row[inner - dzg->dzs];
            }
        }
        CroutDecomp__FiPfT1(dzg->activeCount, dzg->matrix, dzg->lu);
        cursor = dzg->rhs;
        for (outer = dzg->listActive.head; outer != 0; outer = outer->next) {
            *cursor++ = -outer->b;
        }
        CroutSolve__FiPfN21(dzg->activeCount, dzg->lu, dzg->rhs, dzg->solution);
        for (index = 0; index < dzg->count; index++) {
            sum = 0.0f;
            cursor = dzg->solution;
            for (outer = dzg->listActive.head; outer != 0; outer = outer->next) {
                sum += *cursor++ * outer->row[index];
            }
            dzg->dzs[index].db = sum;
        }
        hit = 0;
        step = 1.0f;
        code = 0;
        cursor = dzg->solution;
        for (outer = dzg->listActive.head; outer != 0; outer = outer->next) {
            delta = *cursor++;
            if (delta > 0.0001f) {
                if (outer->hi != RO_002A4120) {
                    candidate = (outer->hi - outer->value) / delta;
                    if (candidate < step) {
                        step = candidate;
                        hit = outer;
                        code = 4;
                    }
                }
            } else if (delta < -0.0001f) {
                if (outer->lo != RO_002A4124) {
                    candidate = (outer->lo - outer->value) / delta;
                    if (candidate < step) {
                        step = candidate;
                        hit = outer;
                        code = 2;
                    }
                }
            }
        }
        for (outer = dzg->listLower.head; outer != 0; outer = outer->next) {
            if (outer->db > -0.0001f) {
            } else {
                candidate = -outer->b / outer->db;
                if (candidate < step) {
                    step = candidate;
                    hit = outer;
                    code = 1;
                }
            }
        }
        for (outer = dzg->listUpper.head; outer != 0; outer = outer->next) {
            if (outer->db < 0.0001f) {
            } else {
                candidate = -outer->b / outer->db;
                if (candidate < step) {
                    step = candidate;
                    hit = outer;
                    code = 3;
                }
            }
        }
        for (index = 0; index < dzg->count; index++) {
            dzg->dzs[index].b += step * dzg->dzs[index].db;
        }
        cursor = dzg->solution;
        for (outer = dzg->listActive.head; outer != 0; outer = outer->next) {
            outer->value += step * *cursor++;
        }
        switch (code) {
        case 0:
            return;
        case 2:
            dzg->activeCount--;
            RemoveDlEntry(&dzg->listActive, hit);
            AppendDlEntry(&dzg->listLower, hit);
            iterations++;
            if (hit == pdz) {
                return;
            }
            break;
        case 4:
            dzg->activeCount--;
            RemoveDlEntry(&dzg->listActive, hit);
            AppendDlEntry(&dzg->listUpper, hit);
            iterations++;
            if (hit == pdz) {
                return;
            }
            break;
        case 1:
            dzg->activeCount++;
            RemoveDlEntry(&dzg->listLower, hit);
            AppendDlEntry(&dzg->listActive, hit);
            iterations++;
            break;
        case 3:
            dzg->activeCount++;
            RemoveDlEntry(&dzg->listUpper, hit);
            AppendDlEntry(&dzg->listActive, hit);
            iterations++;
            break;
        default:
            iterations++;
            break;
        }
        if (iterations >= 10) {
            return;
        }
    }
}
}
