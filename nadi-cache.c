
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#include "nadi-spi.h"

#define MAXLEN 80
#define EOS '\0'
#define CACHEDURATION 30

char *getname(nd_req_t req)
{
    char *fname = malloc(strlen(req->key) + 20);
    sprintf(fname, "nadi-cache-%s.txt", req->key);
    return fname;
}

nd_req_t nd_get(nd_req_t req)
{
    char fline[MAXLEN];
    struct stat fstats;
    FILE *fp;
    fline[0] = EOS;
    char *fname = getname(req);
    if (access(fname, F_OK) != -1 ) { // file exists
        stat(fname, &fstats);
        if ((time(0) - fstats.st_mtime) < CACHEDURATION) { // file is less than 1 minute old
            fp = fopen(fname, "r");
            fgets(fline, MAXLEN, fp);
            fclose(fp);
            strncpy(req->value, fline, strlen(fline));
            req->value[strlen(fline) - 1] = EOS;
            free(fname);
            return req;
        }
    }
    fputs(req->purpose, stdout);
    fgets(req->value, req->vsize, stdin);
    req->value[strlen(req->value) - 1] = EOS;
    return nd_put(req);
}

nd_req_t nd_put(nd_req_t req)
{
    char *fname = getname(req);
    FILE *fp = fopen(fname, "w");
    fprintf(fp, "%s\n", req->value);
    fclose(fp);
    free(fname);
    return req;
}
