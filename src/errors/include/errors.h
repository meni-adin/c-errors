
#ifndef ERRORS_H
#define ERRORS_H

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

#include "c_errors_config.h"

typedef enum status_t_ {
    SUCCESS = 0,  // Must be first and equal 0
    ERR_MEM_ALLOC,
    ERR_BAD_ARGUMENT,
    ERR_COUNT,
} status_t;

void errors_assert(status_t status);

const char *errors_getStr(status_t status);

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // ERRORS_H
