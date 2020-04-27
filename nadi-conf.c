
#include <stdlib.h>
#include <string.h>
#include <confuse.h>

#include "nadi-spi.h"

nd_req_t nd_get(nd_req_t req)
{
    cfg_opt_t opts[] = { CFG_STR(req->key, "", CFGF_NONE), CFG_END() };
    cfg_t *cfg = cfg_init(opts, CFGF_IGNORE_UNKNOWN);
    cfg_parse(cfg, "nadi-conf.properties");
    req->value = strdup(cfg_getstr(cfg, req->key));
    cfg_free(cfg);
    return req;
}

nd_req_t nd_put(nd_req_t req)
{
    return req;
}
