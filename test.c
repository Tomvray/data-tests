#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(test_in);
PG_FUNCTION_INFO_V1(test_out);

typedef struct
{
    text *data;
} test;

Datum
test_in(PG_FUNCTION_ARGS)
{
    char *input_str = PG_GETARG_CSTRING(0);
    /* if (input_str == NULL)
    {
        ereport(ERROR, errcode(ERRCODE_NULL_VALUE_NOT_ALLOWED), errmsg("null input not allowed!!!!!"));
    } */
    test *result = (test *)palloc(sizeof(test));
    result->data = cstring_to_text(input_str);

    PG_RETURN_POINTER(result);
}

Datum
test_out(PG_FUNCTION_ARGS)
{
    test *input = (test *)PG_GETARG_POINTER(0);

    PG_RETURN_CSTRING(text_to_cstring(input->data));
}
