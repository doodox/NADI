
#include <stddef.h>
#include <stdio.h>

#include "nadi-spi.h"

int main(int argc, char *argv[])
{
    char *key = argv[1];
    char purpose[40];
    sprintf(purpose, "Enter %s: ", key);
    nd_req_t req = nd_alloc(128);
    nd_get(nd_set_pk(req, purpose, key));
    printf("%s='%s'\n", key, req->value);
    nd_free(req);
}
