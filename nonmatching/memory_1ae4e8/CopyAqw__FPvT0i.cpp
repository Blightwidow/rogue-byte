typedef int s32; typedef int s128 __attribute__((mode(TI)));
extern "C" {
void CopyAqw__FPvT0i(s128 *dest, s128 *src, s32 count) {
    s32 remainder = count & 3;
    s32 counter;
    s32 bulk = count - remainder;
    if (remainder != 0) {
        counter = remainder;
        do {
            s128 element = *src++;
            counter--;
            *dest++ = element;
        } while (counter != 0);
    }
    for (counter = 0; counter < bulk; counter += 4) {
        s128 first = src[0];
        s128 second = src[1];
        s128 third = src[2];
        s128 fourth = src[3];
        src += 4;
        dest[0] = first;
        dest[1] = second;
        dest[2] = third;
        dest[3] = fourth;
        dest += 4;
    }
}
}
