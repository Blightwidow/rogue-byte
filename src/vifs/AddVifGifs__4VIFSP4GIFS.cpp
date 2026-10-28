struct QW;
class GIFS { public: char pad[4]; unsigned base; char pad2[4]; unsigned cursor; };
class VIFS {
public:
    void AddVifGifs(GIFS *gifs);
    void AddVifDirect(int, QW *, int);
};
void VIFS::AddVifGifs(GIFS *gifs)
{
    AddVifDirect((gifs->cursor - gifs->base) >> 4, (QW *)gifs->base, 0);
}
