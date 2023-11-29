#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"
#include <stdio.h>

PG_MODULE_MAGIC;

typedef struct {
    int32 length;
    char data[FLEXIBLE_ARRAY_MEMBER];
} text;

PG_FUNCTION_INFO_V1(test_in);
PG_FUNCTION_INFO_V1(test_out);

Datum
test_in(PG_FUNCTION_ARGS)
{
    char *input_str = PG_GETARG_CSTRING(0);
    /* if (input_str == NULL)
    {
        ereport(ERROR, errcode(ERRCODE_NULL_VALUE_NOT_ALLOWED), errmsg("null input not allowed!!!!!"));
    } */
    text *destination = (text *) palloc(VARHDRSZ + strlen(input_str));
	SET_VARSIZE(destination, VARHDRSZ + strlen(input_str));
	memcpy(destination->data, input_str, strlen(input_str));

    PG_RETURN_POINTER(result);
}

Datum
test_out(PG_FUNCTION_ARGS)
{
    test *input = (test *)PG_GETARG_POINTER(0);

    PG_RETURN_CSTRING(text_to_cstring(input->data));
}
