struct Bytes24 { char bytes[24]; };
struct BmpHeader { Bytes24 head; unsigned paragraphs; };
extern "C" {
BmpHeader *CopyBmpHeader(BmpHeader *destination, BmpHeader *source) {
    destination->head = source->head;
    *(unsigned *)((char *)destination + 0x18) = (*(unsigned *)((char *)destination + 0x10) + 0xF) >> 4;
    return destination;
}
}
