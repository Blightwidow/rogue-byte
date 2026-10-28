extern char B_003DD490[];
void SetGadgetAcquired(int, int);
void func_0019F0A8(void *);
void OnCodeGrantGadget(int gadget)
{
    SetGadgetAcquired(gadget, 1);
    func_0019F0A8(B_003DD490);
}
