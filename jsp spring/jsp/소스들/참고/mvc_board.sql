ALTER TABLE mvc_board AUTO_INCREMENT = 0;

delete from mvc_board;


SELECT * FROM basicjsp.mvc_board;

insert into mvc_board (bId, bName, bTitle, bContent, bHit, bGroup, bStep, bIndent) values (null, 'ldj', '제목', '컨텐츠', 0, 0, 0, 0 );

select ifnull(max(bid), 0)+1 from mvc_board;

#출처: https://droptable.tistory.com/33 [DropTable]

# insert into mvc_board (bId, bName, bTitle, bContent, bHit, bGroup, bStep, bIndent) values (mvc_board_seq.nextval, ?, ?, ?, 0, mvc_board_seq.currval, 0, 0 )