extern "C" {
int CMovieText_ClineWrap(void *);
float CMovieText_DxMaxLine(void *);

void CMovieText_GetExtents(char *text, float *width, float *height) {
    int lines = CMovieText_ClineWrap(text);
    float maxWidth = CMovieText_DxMaxLine(text);
    float lineHeight = (float)lines * *(float *)(text + 0x84);
    if (width) *width = maxWidth;
    if (height) *height = lineHeight;
}
}
