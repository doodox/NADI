#pragma once
#include <stddef.h>

struct nd_req_s {
    size_t vsize;
    char *value;
    char *purpose;
    char *store;
    char *key;
};

#define ND_REQ_SIZE sizeof(struct nd_req_s)

typedef struct nd_req_s *nd_req_t;

nd_req_t nd_alloc(size_t vsize);
void nd_free(nd_req_t self);
nd_req_t nd_set(nd_req_t req, char *purpose, char *store, char *key, char *value);
nd_req_t nd_set_pk(nd_req_t req, char *purpose, char *key);
