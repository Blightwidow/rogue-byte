extern "C" {
int IdCurrentLevel();
int func_0013FAD0(int count, short *ids) {
    int id = IdCurrentLevel();
    if (id != -1) {
        int index = 0;
        while (index < count) {
            if (*ids++ == id) return 1;
            index++;
        }
        return 0;
    }
    return 1;
}
}
