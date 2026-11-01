extern "C" {
void PostAshLoad(char *, int);
void PostBtnLoad(int *self) {
    char *item = (char *)(self + 1);
    for (unsigned index = 0; index < 2; index++) {
        PostAshLoad(item, *self);
        item += 0x44;
    }
}
}
