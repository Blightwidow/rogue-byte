// SPDX-License-Identifier: GPL-3.0-or-later
int func_0023F640(int* node) {
    int offset = node[0];
    int count = 0;
    if (offset != 0) {
        for (;;) {
            int nextOffset;
            if (node[1] != 0) {
                if (node[2] != 0) {
                    count++;
                }
            }
            node = (int*)((char*)node + offset + 4);
            nextOffset = node[0];
            if (nextOffset == 0) {
                break;
            }
            offset = nextOffset;
        }
    }
    return count;
}
