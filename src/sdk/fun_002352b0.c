/* SPDX-License-Identifier: GPL-3.0-or-later */

/* One queued thread request: what to do and the thread id it applies to. */
struct ThreadRequest {
    unsigned char command;
    unsigned char threadId;
};

/* Ring of thread requests filled by interrupt handlers and drained by a kernel helper thread. */
struct ThreadRequestQueue {
    unsigned int head;
    int field4;
    struct ThreadRequest requests[512];
};

extern int B_00448940; /* semaphore signalled once per queued request */

int WaitSema(int semaphoreId);
int WakeupThread(int threadId);
int RotateThreadReadyQueue(int priority);
int SuspendThread(int threadId);
int func_002369E0(const char *format, ...); /* kernel printf: varargs, saves $a1-$a7 */

/*
 * Retail (libkernl, SDK range) saves eight registers with `sd` in 16-byte slots (Sony ee-gcc 2.9),
 * waits on the semaphore at 0x448940, takes the next request (head & 0x1FF, head = index + 1) and
 * dispatches on its command byte; an unknown command prints the library's internal-error string.
 */
void func_002352B0(struct ThreadRequestQueue *queue)
{
    for (;;) {
        unsigned int index;

        WaitSema(B_00448940);
        index = queue->head & 0x1FF;
        queue->head = index + 1;
        switch (queue->requests[index].command) {
        case 0:
            WakeupThread(queue->requests[index].threadId);
            break;
        case 1:
            RotateThreadReadyQueue(queue->requests[index].threadId);
            break;
        case 2:
            SuspendThread(queue->requests[index].threadId);
            break;
        default:
            func_002369E0("## internel error in libkernl.a!\n");
            break;
        }
    }
}
