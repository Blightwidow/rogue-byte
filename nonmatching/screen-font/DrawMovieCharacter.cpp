extern "C" {
void DrawMovieBitmapCharacter(void *);
void DrawMovieShapeCharacter(void *);
void DrawMovieTextCharacter(void *);

void DrawMovieCharacter(char *character) {
    switch (*(int *)(character + 4)) {
    case 3:
        DrawMovieTextCharacter(character);
        break;
    case 1:
        DrawMovieShapeCharacter(character);
        break;
    case 6:
    case 7:
        DrawMovieBitmapCharacter(character);
        break;
    case 8:
        break;
    }
}
}
