DELIMITER //
CREATE TRIGGER TR_ADD_BOOK
	AFTER INSERT 			-- 삭제 되면 작동
	ON book		-- 어떤 테이블에?
    FOR EACH ROW			-- 각 row(행) 마다 적용

-- 테이블에 백업데이터 삽입
BEGIN
	INSERT INTO booklog(bookName,bookIsbn)
		VALUES (new.bookname,new.bookisbn );
END
// DELIMITER ;

