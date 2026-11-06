struct Metrics { char pad0[0xC]; int lineUnits; char pad10[4]; float scale; };
struct RichText { char pad0[0xC]; struct Metrics *metrics; };
int ClineWrap__9CRichTextf();
float CRichText_DyWrap(struct RichText *text) {
    struct Metrics *metrics = text->metrics;
    float lineHeight = (float)metrics->lineUnits * metrics->scale;
    return lineHeight * (float)ClineWrap__9CRichTextf();
}
