DELIMITER //
CREATE TRIGGER TR_ADD_CUSTOMER
	AFTER INSERT 			-- 삭제 되면 작동
	ON customer		-- 어떤 테이블에?
    FOR EACH ROW			-- 각 row(행) 마다 적용

-- 테이블에 백업데이터 삽입
BEGIN
	INSERT INTO customerlog(custid,custname,custaddress,custphone)
		VALUES (new.custid,new.name, new.address, new.phone );
END
// DELIMITER ;

