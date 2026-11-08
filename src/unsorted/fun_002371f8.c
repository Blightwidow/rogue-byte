struct Source {
    int word0;
    int word4;
    int word8;
    int wordC;
    int word10;
    int word14;
    int word18;
    int word1C;
    int word20;
    int word24;
    int word28;
    int word2C;
    int word30;
    struct Destination *destination;
};
struct Queue {
    int handle;
    int busy;
    int word8;
    int head;
    int tail;
};
struct Destination {
    int word0;
    int word4;
    int word8;
    int wordC;
    int word10;
    int word14;
    int word18;
    int word1C;
    int word20;
    int word24;
    int word28;
    int word2C;
    int word30;
    int word34;
    int word38;
    int next;
    struct Queue *queue;
};
extern void func_00235478(int handle, struct Destination *destination, struct Queue *queue);
void func_002371F8(struct Source *source)
{
    struct Destination *destination = source->destination;
    struct Queue *queue = destination->queue;
    int first;
    int second;
    if (queue->head == 0) {
        queue->head = (int)destination;
    } else {
        ((struct Destination *)queue->tail)->next = (int)destination;
    }
    queue->tail = (int)destination;
    /* Choice: source->word14 and word1C are read into locals before the stores to destination, as retail loads them first (a load does not move
       above an earlier store that may alias it). The locals hold real values read from the source and stored; see exceptions.md, "typed local". */
    first = source->word14;
    second = source->word1C;
    destination->word20 = first;
    destination->word1C = second;
    destination->word24 = source->word20;
    destination->wordC = source->word24;
    destination->word28 = source->word28;
    destination->word2C = source->word2C;
    destination->word30 = source->word30;
    destination->word34 = source->word10;
    if (queue->handle >= 0 && queue->busy == 0) {
        func_00235478(queue->handle, destination, queue);
    }
}
