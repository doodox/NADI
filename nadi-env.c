
#include <stdlib.h>

#include "nadi-spi.h"

nd_req_t nd_get(nd_req_t req)
{
    req->value = getenv(req->key);
    return req;
}

nd_req_t nd_put(nd_req_t req)
{
    return req;
}
