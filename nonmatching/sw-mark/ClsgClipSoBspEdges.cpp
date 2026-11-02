typedef int s128 __attribute__((mode(TI)));
struct Edge { unsigned short v0, v1, pad4, face; Edge *next; };
struct Node { char pad[0x10]; Edge *edges; char pad14[4]; int flags; };
struct Entry { int a, b; Node *node; };
struct Face { char pad[0x18]; int flags; char pad1c[4]; };
struct OutEdge { char pad[0x54]; Edge *edge; char pad58[0x8]; };
struct Bsp { char pad[0x94]; s128 *verts; char pad98[4]; Face *faces; };
struct Ctx { char pad[0x74]; int tree; };
extern "C" {
int ClsgClipEdgeToBsp(int, int, s128, s128, int, OutEdge *);
int ClsgClipSoBspEdges(int unused, Ctx *ctx, Bsp *bsp, int count, Entry *entries, int limit, OutEdge *out) {
    int marked = 0;
    int total = 0;
    s128 *verts = bsp->verts;
    Face *faces = bsp->faces;
    int index;
    for (index = count; --index >= 0; )
        entries[index].node->flags |= 1;
    for (index = count; --index >= 0; ) {
        Node *node = entries[index].node;
        int flags = node->flags;
        if ((flags & 1) != 0) if ((flags & 2) == 0) {
            Edge *edge = node->edges;
            node->flags = flags | 2;
            if (edge != 0) {
                do {
                    if (!((faces[edge->face].flags ^ 1) & 1)) {
                        total += ClsgClipEdgeToBsp(ctx->tree, 0x7FFFFFFF, verts[edge->v0], verts[edge->v1], limit - total, out + total);
                        for (; marked < total; marked++)
                            out[marked].edge = edge;
                    }
                    edge = edge->next;
                } while (edge != 0);
            }
        }
    }
    for (index = count; --index >= 0; )
        entries[index].node->flags &= ~3;
    return total;
}
}
