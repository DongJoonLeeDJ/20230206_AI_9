DELIMITER $$
    CREATE FUNCTION `nextval` (the_name VARCHAR(32))
    RETURNS BIGINT UNSIGNED
    MODIFIES SQL DATA
    DETERMINISTIC
    BEGIN
        DECLARE ret BIGINT UNSIGNED;
        UPDATE sequences SET currval = currval +1 WHERE name = the_name;
        SELECT currval INTO ret FROM sequences WHERE name = the_name LIMIT 1;
        RETURN ret;
   END