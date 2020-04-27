
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

#include "nadi-spi.h"

#define EOS '\0'

nd_req_t nd_get(nd_req_t req)
{
    char *secret = getpass(req->purpose);
    strncpy(req->value, secret, strlen(secret));
    req->value[strlen(secret)] = EOS;
    return req;
}

nd_req_t nd_put(nd_req_t req)
{
    return req;
}
