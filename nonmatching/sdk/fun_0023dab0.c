typedef unsigned long u64;
typedef struct Unpacked {
    int cls;
    int sign;
    int exponent;
    int pad;
    u64 fraction;
} Unpacked;
extern Unpacked B_00450230;
void func_0023D468(u64 *source, Unpacked *out);
void func_0023D338(Unpacked *result, Unpacked *operand);

void func_0023DAB0(u64 a, u64 b) {
    Unpacked A, B;
    Unpacked *pResult;
    u64 fractionA, fractionB, bit, quotient, remainder;
    int less;
    func_0023D468(&a, &A);
    func_0023D468(&b, &B);
    pResult = &A;
    if (A.cls < 2) {
    } else if (B.cls < 2) {
        pResult = &B;
    } else {
        A.sign = A.sign ^ B.sign;
        if (A.cls == 4 || A.cls == 2) {
            if (A.cls == B.cls)
                pResult = &B_00450230;
        } else if (B.cls == 4) {
            A.fraction = 0;
            A.exponent = 0;
        } else if (B.cls == 2) {
            A.cls = 4;
        } else {
            fractionA = A.fraction;
            fractionB = B.fraction;
            A.exponent = A.exponent - B.exponent;
            if (fractionA < fractionB) {
                A.exponent--;
                fractionA <<= 1;
            }
            less = fractionA < fractionB;
            bit = 1UL << 60;
            quotient = 0;
            remainder = fractionA;
            for (;;) {
                if (!less) {
                    quotient |= bit;
                    remainder -= fractionB;
                }
                bit >>= 1;
                remainder <<= 1;
                if (bit == 0)
                    break;
                less = remainder < fractionB;
            }
            if ((quotient & 0xFF) == 0x80) {
                if (quotient & 0x100)
                    quotient += 0x80;
                else if (remainder != 0)
                    quotient += 0x80;
            }
            A.fraction = quotient;
        }
    }
    func_0023D338(pResult, &A);
}
