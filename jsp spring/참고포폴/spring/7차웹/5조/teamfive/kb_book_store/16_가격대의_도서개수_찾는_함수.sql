DELIMITER $$
CREATE DEFINER=`kb_bookstore_admin`@`%` FUNCTION `get_book_count_price`(p_min int, p_max int) RETURNS int
begin 
declare countBook integer;
if p_min < 0 then 
select count(*) into countBook from book where price>=p_max;
else 
select count(*) into countBook from book where price>=p_min and price<p_max;
end if;
RETURN saleprice;
END$$
DELIMITER ;
