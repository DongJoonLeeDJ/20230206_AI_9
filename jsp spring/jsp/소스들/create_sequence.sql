
DELIMITER $$
    CREATE PROCEDURE `create_sequence` (IN the_name text)
    MODIFIES SQL DATA
    DETERMINISTIC
    BEGIN
        DELETE FROM sequences WHERE name = the_name;
        INSERT INTO sequences VALUES(the_name, 0);
   END