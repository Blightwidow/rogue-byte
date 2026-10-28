struct Obj {
    int pad[3];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void Target(int, int, int);
};
void func_001A58D0(Obj *self, int passthrough, int value)
{
    self->Target(passthrough, 0, value);
}
