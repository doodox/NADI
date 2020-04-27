
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "nadi-spi.h"

#define MAXLEN 80
#define EOS '\0'

nd_req_t nd_get(nd_req_t req)
{
    char fline[MAXLEN];
    char *fname = malloc(strlen(req->key) + 14);
    sprintf(fname, "nadi-txt-%s.txt", req->key);
    FILE *fp = fopen(fname, "r");
    fgets(fline, MAXLEN, fp);
    fclose(fp);
    strncpy(req->value, fline, strlen(fline));
    req->value[strlen(fline) - 1] = EOS;
    return req;
}

nd_req_t nd_put(nd_req_t req)
{
    return req;
}
