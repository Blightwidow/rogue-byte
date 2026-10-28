struct AMB { char pad[0x40]; int hvoice; };
extern "C" void func_00233088(int, int, int, int, int, int, int);
extern "C" void ContinueStreamAmb(AMB *pamb)
{
    func_00233088(0x524B5553, 4, pamb->hvoice, 0, 0, 0, 0);
}
