
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "nadi-base.h"

nd_req_t nd_alloc(size_t vsize)
{
    size_t size = ND_REQ_SIZE + vsize;
    nd_req_t req = (nd_req_t)malloc(size);
    memset(req, 0, size);

    req->vsize = vsize;
    req->value = (char *)(req + ND_REQ_SIZE);
    return req;
}

void nd_free(nd_req_t req)
{
    free(req);
}

nd_req_t nd_set(nd_req_t req, char *purpose, char *store, char *key, char *value)
{
    req->purpose = purpose;
    req->store = store;
    req->key = key;
    req->value = value;
    return req;
}

nd_req_t nd_set_pk(nd_req_t req, char *purpose, char *key)
{
    req->purpose = purpose;
    req->key = key;
    return req;
}
