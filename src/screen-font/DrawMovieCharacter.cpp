extern "C" {
void DrawMovieBitmapCharacter(void *, void *, void *, void *);
void DrawMovieShapeCharacter(void *, void *, void *, void *);
void DrawMovieTextCharacter(void *, void *, void *, void *);

void DrawMovieCharacter(char *character, void *matrix, void *cxform, void *context) {
    switch (*(int *)(character + 4)) {
    case 3:
        DrawMovieTextCharacter(character, matrix, cxform, context);
        break;
    case 1:
        DrawMovieShapeCharacter(character, matrix, cxform, context);
        break;
    case 6:
    case 7:
        DrawMovieBitmapCharacter(character, matrix, cxform, context);
        break;
    case 8:
        break;
    }
}
}
