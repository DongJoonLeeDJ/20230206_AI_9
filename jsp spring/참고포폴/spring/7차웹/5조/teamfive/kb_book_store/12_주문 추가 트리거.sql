DELIMITER //
CREATE TRIGGER TR_ADD_ORDER
	AFTER INSERT 			-- 삭제 되면 작동
	ON orders		-- 어떤 테이블에?
    FOR EACH ROW			-- 각 row(행) 마다 적용

-- 테이블에 백업데이터 삽입
BEGIN
	INSERT INTO orderlog(orderid,custid,bookid,saleprice)
		VALUES (new.orderid,new.custid, new.bookid, new.saleprice );
END
// DELIMITER ;

