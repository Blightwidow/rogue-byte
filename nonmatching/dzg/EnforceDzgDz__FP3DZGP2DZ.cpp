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
    DZ_11A770 *outer;
    DZ_11A770 *inner;
    float *cursor;
    int index;
    if (pdz != 0) {
        RemoveDlEntry(&dzg->listFree, pdz);
        AppendDlEntry(&dzg->listActive, pdz);
        dzg->activeCount++;
    }
    iterations = 0;
    do {
        {
            float *out = dzg->matrix;
            for (outer = dzg->listActive.head; outer; outer = outer->next) {
                for (inner = dzg->listActive.head; inner; inner = inner->next) {
                    *out = outer->row[inner - dzg->dzs];
                    out++;
                }
            }
        }
        CroutDecomp__FiPfT1(dzg->activeCount, dzg->matrix, dzg->lu);
        {
            float *out = dzg->rhs;
            for (outer = dzg->listActive.head; outer; outer = outer->next) {
                *out = -outer->b;
                out++;
            }
        }
        CroutSolve__FiPfN21(dzg->activeCount, dzg->lu, dzg->rhs, dzg->solution);
        for (index = 0; index < dzg->count; index++) {
            float sum = 0.0f;
            float *w = dzg->solution;
            for (outer = dzg->listActive.head; outer; outer = outer->next) {
                sum += *w * outer->row[index];
                w++;
            }
            dzg->dzs[index].db = sum;
        }

        DZ_11A770 *hit = 0;
        float step = 1.0f;
        int code = 0;
        cursor = dzg->solution;
        for (outer = dzg->listActive.head; outer; outer = outer->next) {
            float delta = *cursor;
            cursor++;
            if (0.0001f < delta) {
                if (outer->hi != 3.4028235e38f) {
                    float candidate = (outer->hi - outer->value) / delta;
                    if (candidate < step) {
                        step = candidate;
                        hit = outer;
                        code = 4;
                    }
                }
            } else if (delta < -0.0001f) {
                if (outer->lo != -3.4028235e38f) {
                    float candidate = (outer->lo - outer->value) / delta;
                    if (candidate < step) {
                        step = candidate;
                        hit = outer;
                        code = 2;
                    }
                }
            }
        }
        for (DZ_11A770 *dz = dzg->listLower.head; dz; dz = dz->next) {
            float db = dz->db;
            if (-0.0001f < db) {
            } else {
                float candidate = -dz->b / db;
                if (candidate < step) {
                    step = candidate;
                    hit = dz;
                    code = 1;
                }
            }
        }
        for (DZ_11A770 *dz = dzg->listUpper.head; dz; dz = dz->next) {
            float db = dz->db;
            if (db < 0.0001f) {
            } else {
                float candidate = -dz->b / db;
                if (candidate < step) {
                    step = candidate;
                    hit = dz;
                    code = 3;
                }
            }
        }
        for (index = 0; index < dzg->count; index++) {
            DZ_11A770 *dz = dzg->dzs + index;
            dz->b += step * dz->db;
        }
        {
            cursor = dzg->solution;
            for (outer = dzg->listActive.head; outer; outer = outer->next) {
                outer->value += step * *cursor;
                cursor++;
            }
        }
        switch (code) {
        case 0:
            return;
        case 2:
            dzg->activeCount--;
            RemoveDlEntry(&dzg->listActive, hit);
            AppendDlEntry(&dzg->listLower, hit);
            if (hit == pdz) return;
            break;
        case 1:
            dzg->activeCount++;
            RemoveDlEntry(&dzg->listLower, hit);
            AppendDlEntry(&dzg->listActive, hit);
            break;
        case 4:
            dzg->activeCount--;
            RemoveDlEntry(&dzg->listActive, hit);
            AppendDlEntry(&dzg->listUpper, hit);
            if (hit == pdz) return;
            break;
        case 3:
            dzg->activeCount++;
            RemoveDlEntry(&dzg->listUpper, hit);
            AppendDlEntry(&dzg->listActive, hit);
            break;
        }
        iterations++;
    } while (iterations < 10);
}
}
