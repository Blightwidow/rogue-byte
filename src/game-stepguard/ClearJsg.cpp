// 0x1DFFE0 FUN_001dffe0
extern "C" void StopJsg(void*);
extern "C" void AddJsgContext(void*, int);

void ClearJsg(void* pjsg)
{
    StopJsg(pjsg);
    *(int*)((unsigned char*)pjsg + 0x50) = 0;
    AddJsgContext(pjsg, -1);
    *(int*)((unsigned char*)pjsg + 0x7C) = 1;
}
