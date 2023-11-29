-- File: test--1.0.sql


CREATE OR REPLACE FUNCTION test_in(cstring)
RETURNS test
AS 'MODULE_PATHNAME'
LANGUAGE C IMMUTABLE STRICT PARALLEL SAFE;

CREATE OR REPLACE FUNCTION test_out(test)
RETURNS cstring
AS 'MODULE_PATHNAME'
LANGUAGE C IMMUTABLE STRICT PARALLEL SAFE;

CREATE TYPE test(
  INPUT   = test_in,
  OUTPUT  = test_out,
  INTERNALLENGTH = VARIABLE
)


-- Optional: Define any additional functions or operations related to your chessgame type.
-- For example, a function that operates on chessgame:


