extern "C" {
void LeaveCritSect__FP8CRITSECT(void *);
extern int B_002F6390;
extern int B_002F63A0[];
extern int g_2f6388;
extern int g_2f639c;
void FreeStackImpl__Fv(void) {
g_2f6388 = B_002F63A0[g_2f639c--]; LeaveCritSect__FP8CRITSECT(&B_002F6390);
}
}
