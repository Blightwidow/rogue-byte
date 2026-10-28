struct Inner { char pad[8]; short a; char pad2[6]; int c; };
struct Outer { char pad[8]; Inner *inner; };
int func_00218710(Outer *outer)
{
    Inner *inner = outer->inner;
    if (inner->a != 0) {
        if (inner->c == 0) return 1;
    }
    return 0;
}
