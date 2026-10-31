extern "C" {
int FFilterHitTestDefault(int, void *);
int FIsBasicDerivedFrom(void *, int);
struct Hit_20CFC0 { char pad[4]; void *obj; char pad2[8]; long grf; };
int func_0020CFC0(int arg0, Hit_20CFC0 *arg1) {
    if ((arg1->grf & (0x8000L << 0x21)) != 0 && FIsBasicDerivedFrom(arg1->obj, 0x59) != 0)
        return 1;
    return FFilterHitTestDefault(arg0, arg1);
}
}
