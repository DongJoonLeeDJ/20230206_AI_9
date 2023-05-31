USE `kb_book_store`;
DROP function IF EXISTS `find_price`;

DELIMITER $$
USE `kb_book_store`$$
CREATE FUNCTION `find_price` (p_bookid int)
RETURNS INTEGER
BEGIN
declare saleprice integer;
select price into saleprice from book where bookid=p_bookid;
RETURN saleprice;
END$$

DELIMITER ;

