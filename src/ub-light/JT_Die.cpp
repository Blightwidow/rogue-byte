extern "C" void SetAloEyesClosed(float);
extern "C" void func_00140EB0(int);
void JT_Die(int self)
{
    SetAloEyesClosed(1.0f);
    func_00140EB0(self);
}
