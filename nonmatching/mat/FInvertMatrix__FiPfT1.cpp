struct ALLOCREQ_11C500 { int size; int align; };
extern "C" {
int CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void CopyAb__FPvT0Ui(void *, void *, unsigned);
void *PvAllocStackImpl__Fi(ALLOCREQ_11C500 *);
int FInvertMatrix__FiPfT1(int stride, int count, float *source, float *inverse) {
    char frame[16];
    ALLOCREQ_11C500 request;
    float *work;
    float *cell;
    int result = 0;
    int row;
    int column;
    int pivot;
    int step;
    float largest;
    float candidate;
    float factor;
    float held;
    CStackFrame_Construct(frame);
    ALLOCREQ_11C500 *pointer = &request;
    request.size = count * stride * 4;
    pointer->align = 0x10;
    work = (float *)PvAllocStackImpl__Fi(pointer);
    CopyAb__FPvT0Ui(work, source, count * stride * 4);
    for (row = 0; row < count; row++) {
        cell = &inverse[row * stride];
        for (column = 0; column < count; column++) {
            if (row == column) {
                *cell = 1.0f;
            } else {
                *cell = 0;
            }
            cell++;
        }
    }
    for (step = 0; step < count; step++) {
        pivot = step;
        largest = __builtin_fabsf(work[step * stride + step]);
        for (column = step + 1; column < count; column++) {
            candidate = __builtin_fabsf(work[step * stride + column]);
            if (largest < candidate) {
                largest = candidate;
                pivot = column;
            }
        }
        if (largest < 0.0001f) {
            goto done;
        }
        if (pivot != step) {
            for (row = 0; row < count; row++) {
                held = work[row * stride + step];
                work[row * stride + pivot] = held;
                work[row * stride + step] = work[row * stride + pivot];
                held = inverse[row * stride + step];
                inverse[row * stride + step] = inverse[row * stride + pivot];
                inverse[row * stride + pivot] = held;
            }
        }
        for (column = step + 1; column < count; column++) {
            factor = work[step * stride + column] / work[step * stride + step];
            for (row = 0; row < count; row++) {
                work[row * stride + column] -= factor * work[row * stride + step];
                inverse[row * stride + column] -= factor * inverse[row * stride + step];
            }
        }
    }
    for (step = count - 1; step >= 0; step--) {
        for (column = 0; column < step; column++) {
            factor = work[step * stride + column] / work[step * stride + step];
            for (row = 0; row < count; row++) {
                work[row * stride + column] -= factor * work[row * stride + step];
                inverse[row * stride + column] -= factor * inverse[row * stride + step];
            }
        }
    }
    for (step = 0; step < count; step++) {
        for (row = 0; row < count; row++) {
            inverse[row * stride + step] /= work[step * stride + step];
        }
    }
    result = 1;
done:
    CStackFrame_Destructor(frame, 2);
    return result;
}
}
