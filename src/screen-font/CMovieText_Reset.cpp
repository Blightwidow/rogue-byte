extern "C" {
struct RGBA4_215CA8 { char c[4]; };
struct MovieText215CA8 {
    int value0, value4, value8, valueC;
    char pad10[4];
    RGBA4_215CA8 color14, color18;
    unsigned int flags1C;
};
void CMovieText_UpdateFont(MovieText215CA8 *);

void CMovieText_Reset(MovieText215CA8 *text, int value)
{
    if (value) text->value0 = value;
    text->value4 = text->value0;
    text->value8 = text->valueC;
    text->color14 = text->color18;
    text->flags1C = 0x80000000;
    ((char *)text)[0x1F] = ((char *)text)[0x17];
    CMovieText_UpdateFont(text);
}
}
