
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "nadi-spi.h"

#define EOS '\0'

nd_req_t nd_get(nd_req_t req)
{
    fputs(req->purpose, stdout);
    fgets(req->value, req->vsize, stdin);
    req->value[strlen(req->value) - 1] = EOS;
    return req;
}

nd_req_t nd_put(nd_req_t req)
{
    return req;
}
