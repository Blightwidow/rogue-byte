extern "C" {
struct Segment_23F710 {
    int low;
    int high;
    int single;
    int **list;
    int count;
};
struct Builder_23F710 {
    void *first;
    int firstCount;
    void *second;
    int secondCount;
    unsigned int low;
    int high;
};
int func_0023F640(int);
void func_0023F688(int, Builder_23F710 *, unsigned int *, int *);
int *func_0023F3D8(Builder_23F710 *, int);
void *malloc(int);
void func_0023F710(Segment_23F710 *segment) {
    Builder_23F710 builder;
    int **cursor;
    int **list;
    int **list2;
    int total;
    list = segment->list;
    if (list != 0) {
        cursor = list;
        total = 0;
        while (*cursor != 0) {
            total += func_0023F640((int)*cursor);
            cursor++;
        }
    } else {
        total = func_0023F640(segment->single);
    }
    segment->count = total;
    builder.first = malloc(total * 4);
    builder.second = malloc(total * 4);
    builder.firstCount = 0;
    builder.secondCount = 0;
    builder.low = 0xFFFFFFFF;
    builder.high = 0;
    list2 = segment->list;
    if (list2 != 0) {
        cursor = list2;
        while (*cursor != 0) {
            func_0023F688((int)*cursor, &builder, &builder.low, &builder.high);
            cursor++;
        }
    } else {
        func_0023F688(segment->single, &builder, &builder.low, &builder.high);
    }
    segment->list = (int **)func_0023F3D8(&builder, total);
    segment->low = builder.low;
    segment->high = builder.high;
}
}
