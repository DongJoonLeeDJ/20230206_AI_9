DELIMITER $$
CREATE DEFINER=`kb_bookstore_admin`@`%` PROCEDURE `clear_book_data`()
BEGIN
	delete from book where bookisbn='' 
    or bookname='' or isnull(bookImg) or publisher ='' or isnull(price);
END$$
DELIMITER ;
