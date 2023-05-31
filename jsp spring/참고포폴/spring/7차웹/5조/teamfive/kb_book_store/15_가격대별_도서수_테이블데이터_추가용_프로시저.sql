USE `kb_book_store`;
DROP procedure IF EXISTS `insert_book_price`;

DELIMITER $$
USE `kb_book_store`$$
CREATE PROCEDURE `insert_book_price` (in p_range varchar(100), in p_count int)
BEGIN
	insert into bookprice(priceRange, countPrice) values(p_range, p_count);
END$$

DELIMITER ;

