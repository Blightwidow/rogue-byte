// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
struct ParseState {
    char *cursor;
    int field4;
    char pad8[8];
    unsigned short field10;
    char pad12[0xE];
};
struct ParseResult {
    char pad0[4];
    int field4;
    char pad8[0x292];
    unsigned short field29A;
    char pad29C[0x54];
} __attribute__((aligned(8)));
struct ParseWorkspace {
    ParseResult head;
    long long trailer;
};
char *func_0023F850(void);
unsigned func_0023F938(char *, ParseState *);
unsigned func_0023FA40(unsigned, ParseResult *, ParseState *, unsigned *);
int func_0023F240(unsigned, int *);
void *memset(void *, int, unsigned);

ParseResult *func_0023FE78(unsigned limit, ParseResult *output)
{
    unsigned deadline;
    int skipped;
    ParseState state;
    ParseWorkspace workspace;
    char *chunk = func_0023F850();
    if (chunk == 0)
        return 0;
    unsigned cursor = func_0023F938(chunk, &state);
    if (cursor == 0)
        return 0;
    memset(&workspace, 0, sizeof(ParseWorkspace));
    workspace.head.field29A = state.field10;
    char *header = chunk - (*(int *)(chunk + 4) - 4);
    unsigned end = (unsigned)(header + *(int *)header + 4);
    workspace.head.field4 = state.field4;
    if (cursor < end) {
        do {
            cursor = func_0023FA40(cursor, &workspace.head, &state, 0);
        } while (cursor < end);
    }
    char *body = chunk + 0x10;
    cursor = (unsigned)body;
    if (*state.cursor == 0x7A)
        cursor = func_0023F240(cursor, &skipped) + skipped;
    end = (unsigned)(chunk + *(int *)chunk + 4);
    deadline = *(unsigned *)(chunk + 8);
    if (cursor < end) {
        if (limit >= deadline) {
            do {
                cursor = func_0023FA40(cursor, &workspace.head, &state, &deadline);
            } while (cursor < end && limit >= deadline);
        }
    }
    *output = workspace.head;
    return output;
}
}
