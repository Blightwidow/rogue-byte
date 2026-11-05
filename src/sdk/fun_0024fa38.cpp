struct Request { int zero; int value; };
struct Owner { char pad0[0xC]; int ready; char pad10[0x858]; void *target; };
extern "C" {
void func_0024B670(void *, Request *);
void func_0024F8C0(int);
void func_0024FA38(Owner *owner, int value) {
    void *target = owner->target;
    if (target != 0 && owner != 0 && owner->ready != 0) {
        Request request;
        request.zero = 0;
        request.value = value;
        func_0024B670(target, &request);
        return;
    }
    func_0024F8C0(value);
}
}
