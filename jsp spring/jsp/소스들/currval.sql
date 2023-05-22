DELIMITER $$
    CREATE FUNCTION `currval` (the_name VARCHAR(32))
    RETURNS BIGINT UNSIGNED
    MODIFIES SQL DATA
    DETERMINISTIC
    BEGIN
        DECLARE ret BIGINT UNSIGNED;
        SELECT ifnull(max(currval),1) INTO ret FROM sequences WHERE name = the_name LIMIT 1;
        RETURN ret;
   END