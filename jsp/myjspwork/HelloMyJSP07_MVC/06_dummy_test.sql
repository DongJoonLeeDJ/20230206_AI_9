call create_sequence('mvc_board');
select * from sequences;
insert into mvc_board(bId, bName, bTitle, bContent, bHit,
bGroup, bStep, bIndent) values 
(nextval('mvc_board'),'이름','제목','내용',0,currval('mvc_board'),
0,0);
select * from mvc_board;
