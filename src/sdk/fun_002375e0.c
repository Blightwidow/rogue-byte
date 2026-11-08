/* SPDX-License-Identifier: GPL-3.0-or-later */
/* SIF RPC call with retry: on failure, delay with exponential backoff (up to 100 retries). */

int sceSifCallRpc(int client, int rpcNumber, int mode, int sendBuffer, int sendSize, int receiveBuffer,
                  int receiveSize, int endFunction, int endParameter);
int func_00235518(int microseconds);

unsigned int func_002375E0(int client, int rpcNumber, int mode, int sendBuffer, int sendSize, int receiveBuffer,
                           int receiveSize, int endFunction, int endParameter, int noRetry)
{
    unsigned int failed;
    int backoff;
    int attempts;

    attempts = 0;
    backoff = 1;
    do {
        failed = (unsigned int)sceSifCallRpc(client, rpcNumber, mode, sendBuffer, sendSize, receiveBuffer,
                                             receiveSize, endFunction, endParameter) >> 31;
        if (failed == 0 || noRetry != 0) {
            break;
        }
        func_00235518(backoff * 1000);
        if (backoff < 0x7F) {
            backoff *= 2;
        }
        attempts++;
    } while (attempts < 0x65);
    return failed;
}
