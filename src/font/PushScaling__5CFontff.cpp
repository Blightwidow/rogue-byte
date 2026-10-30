struct SC { float x, y; };
struct CFont {
    char pad[0x10];
    float m_sx;
    float m_sy;
    int m_csc;
    SC m_asc[8];
    void PushScaling(float rx, float ry);
};
void CFont::PushScaling(float rx, float ry)
{
    SC *psc = &m_asc[m_csc++];
    psc->x = m_sx;
    psc->y = m_sx;
    m_sx = m_asc[0].x * rx;
    m_sy = m_asc[0].y * ry;
}
