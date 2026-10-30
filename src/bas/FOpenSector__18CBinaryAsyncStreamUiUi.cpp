struct CBinaryAsyncStream {
    int m_state;      /* 0x00 */
    int pad04;
    unsigned int m_isector;  /* 0x08 */
    int pad0c[3];
    int m_x18;        /* 0x18 */
    int m_x1c;        /* 0x1C */
    int m_x20;        /* 0x20 */
    int m_x24;        /* 0x24 */
    unsigned int m_x28;  /* 0x28 */
    unsigned int m_x2c;  /* 0x2C */
};
extern "C" void StartSpooling__18CBinaryAsyncStream(CBinaryAsyncStream *);

extern "C" int FOpenSector__18CBinaryAsyncStreamUiUi(CBinaryAsyncStream *self, unsigned int isector, unsigned int csector) {
    self->m_isector = isector;
    self->m_x2c = csector;
    self->m_x28 = csector;
    self->m_state = 1;
    self->m_x20 = self->m_x18;
    self->m_x1c = 0;
    self->m_x24 = 0;
    StartSpooling__18CBinaryAsyncStream(self);
    return 1;
}
