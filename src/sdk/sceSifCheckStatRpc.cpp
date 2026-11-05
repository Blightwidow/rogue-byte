struct RpcServer { int pad0[4]; unsigned flags; int pad14; int id; };
struct RpcClient { RpcServer *server; int id; };
extern "C" int sceSifCheckStatRpc(RpcClient *client) {
    RpcServer *server = client->server;
    if (server == 0 || client->id != server->id || (server->flags & 1) == 0) {
        return 0;
    }
    return 1;
}
