extern "C" {
extern char D_002BD4E0;
extern char D_002BD518;
extern char D_002BD550;
extern char D_002BD588;
extern char D_002BD5C0;
extern char D_002BD5F8;
extern char D_002BD630;
extern char D_002BD668;
extern char D_002BD6A0;
extern char D_002BD6D8;
extern char D_002BD710;
extern char D_002BD748;
extern char D_002BD780;
extern char D_002BD7B8;
extern char D_002BD7F0;
void InitSl(void *, int);
void AddCode(void *, void *);
}

void InitCodes(void *list)
{
    InitSl(list, 0x18);
    AddCode(list, &D_002BD4E0);
    AddCode(list, &D_002BD518);
    AddCode(list, &D_002BD550);
    AddCode(list, &D_002BD588);
    AddCode(list, &D_002BD5C0);
    AddCode(list, &D_002BD5F8);
    AddCode(list, &D_002BD630);
    AddCode(list, &D_002BD668);
    AddCode(list, &D_002BD6A0);
    AddCode(list, &D_002BD6D8);
    AddCode(list, &D_002BD710);
    AddCode(list, &D_002BD748);
    AddCode(list, &D_002BD780);
    AddCode(list, &D_002BD7B8);
    AddCode(list, &D_002BD7F0);
}
