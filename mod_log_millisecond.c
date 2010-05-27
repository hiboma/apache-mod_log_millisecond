/* 
**  mod_log_millisecond.c -- Apache sample log_millisecond module
**  [Autogenerated via ``apxs -n log_millisecond -g'']
**
**  To play with this sample module first compile it into a
**  DSO file and install it into Apache's modules directory 
**  by running:
**
**    $ apxs -c -i mod_log_millisecond.c
**
**    #   httpd.conf
**    LoadModule log_millisecond_module modules/mod_log_millisecond.so
*/ 

#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"

#include "mod_log_config.h"

static const char *log_request_duration_milliseconds(request_rec *r, char *a)
{
    apr_time_t duration = apr_time_now() - r->request_time;
    return apr_psprintf(r->pool, "%" APR_TIME_T_FMT ".%" APR_TIME_T_FMT, apr_time_sec(duration), apr_time_msec(duration));
}

static int log_millisecond_pre_config(apr_pool_t *p, apr_pool_t *plog, apr_pool_t *ptemp)
{
    static APR_OPTIONAL_FN_TYPE(ap_register_log_handler) *log_register;

    log_register = APR_RETRIEVE_OPTIONAL_FN(ap_register_log_handler);
    if (!log_register)
        return DECLINED;

    log_register(p, "M", log_request_duration_milliseconds, 1);
    return OK;
}
static void log_millisecond_register_hooks(apr_pool_t *p)
{
    ap_hook_pre_config(log_millisecond_pre_config, NULL, NULL, APR_HOOK_LAST);
}

/* Dispatch list for API hooks */
module AP_MODULE_DECLARE_DATA log_millisecond_module = {
    STANDARD20_MODULE_STUFF, 
    NULL,                  /* create per-dir    config structures */
    NULL,                  /* merge  per-dir    config structures */
    NULL,                  /* create per-server config structures */
    NULL,                  /* merge  per-server config structures */
    NULL,                  /* table of config file commands       */
    log_millisecond_register_hooks  /* register hooks                      */
};

