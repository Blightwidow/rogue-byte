extern "C" void func_00183F50();
struct GLOBALS { char pad[0x463C]; unsigned int oidNext; };
extern "C" GLOBALS B_003DD490;
void PostCrfodbLoad__FP6CRFODB(void* pguard)
{
    func_00183F50();
    *(unsigned int*)((char*)pguard + 0x180) = B_003DD490.oidNext++;
}
