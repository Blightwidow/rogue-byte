typedef struct RegTable {
    int base;
    int field04[5];
    long entry[80];
    int field298;
    char kind[1];
} RegTable;
extern int func_00240328(void);
int get_reg_addr(int first, RegTable *table) {
    int index = first;
    if (table->kind[index] == 2) {
        do {
            index = (int)table->entry[index];
        } while (table->kind[index] == 2);
    }
    if (table->kind[index] == 1) {
        return table->base + (int)table->entry[index];
    }
    return func_00240328();
}
