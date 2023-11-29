-- File: chessgame--1.0.sql

CREATE TYPE chessgame;

-- Optional: Define any additional functions or operations related to your chessgame type.
-- For example, a function that operates on chessgame:

CREATE OR REPLACE FUNCTION chessgame_length(input chessgame)
RETURNS INT
AS $$
  SELECT LENGTH(input);
$$ LANGUAGE SQL;
