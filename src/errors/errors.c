
#include "errors.h"

#include <stdio.h>
#include <stdlib.h>

static const char *gErrorsDatabase[] = {[SUCCESS]          = "Operation succeeded",
                                        [ERR_MEM_ALLOC]    = "Memory allocation failed",
                                        [ERR_BAD_ARGUMENT] = "Function called with a bad argument"};

#define ARRAY_LEN(array) (sizeof(array) / sizeof(*array))

#define IS_KNOWN_STATUS(status) ((SUCCESS <= status) && (status < ERR_COUNT))

_Static_assert(ARRAY_LEN(gErrorsDatabase) == ERR_COUNT,
               "Error: seems like a description string for an error is missing");

void errors_assert(status_t status) {
    const char *errStr;
    if (status == SUCCESS) {
        return;
    }
    errStr = IS_KNOWN_STATUS(status) ? gErrorsDatabase[status] : "unknown error";
    fprintf(stderr, "%s\n", errStr);
    exit(status);
}

const char *errors_getStr(status_t status) {
#ifdef C_ERRORS_SAFE_MODE
    if (!IS_KNOWN_STATUS(status)) {
        return NULL;
    }
#endif  // C_DATABASES_SAFE_MODE
    return gErrorsDatabase[status];
}
