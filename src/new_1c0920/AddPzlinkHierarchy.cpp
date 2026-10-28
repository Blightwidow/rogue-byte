struct World { char pad[0x3D74]; int counter; char pad2[0x45CC - 0x3D78]; char *current; };
extern "C" World B_003DD490;
extern "C" void AddLoHierarchy(void);
extern "C" void AddPzlinkHierarchy(void)
{
    AddLoHierarchy();
    int next = B_003DD490.counter + 1;
    B_003DD490.counter = next;
    *(int *)(B_003DD490.current + 0x28) = next;
}
