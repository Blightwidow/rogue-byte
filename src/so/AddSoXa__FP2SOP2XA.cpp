struct XA { char pad[8]; XA *next; };
struct SO { char pad[0x138]; XA *xaList; };
extern "C" void func_001F5078(SO *);
void AddSoXa(SO *so, XA *xa)
{
    xa->next = so->xaList;
    so->xaList = xa;
    func_001F5078(so);
}
