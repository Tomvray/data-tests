#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(chessgame_in);
PG_FUNCTION_INFO_V1(chessgame_out);

typedef struct
{
    text *data;
} chessgame;

Datum
chessgame_in(PG_FUNCTION_ARGS)
{
    char *input_str = PG_GETARG_CSTRING(0);

    chessgame *result = (chessgame *)palloc(sizeof(chessgame));
    result->data = cstring_to_text(input_str);

    PG_RETURN_POINTER(result);
}

Datum
chessgame_out(PG_FUNCTION_ARGS)
{
    chessgame *input = (chessgame *)PG_GETARG_POINTER(0);

    PG_RETURN_CSTRING(text_to_cstring(input->data));
}
