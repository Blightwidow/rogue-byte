struct ColorU8 { unsigned char red; unsigned char green; unsigned char blue; };
struct ColorFloat { float red; float green; float blue; };
void UnpackColorU8ToVec_11dcd8(struct ColorU8 *source, struct ColorFloat *target) {
    target->red = (float)source->red * 0.003921569f;
    target->green = (float)source->green * 0.003921569f;
    target->blue = (float)source->blue * 0.003921569f;
}
