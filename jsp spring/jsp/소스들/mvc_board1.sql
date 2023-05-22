SELECT * FROM basicjsp.mvc_board;
alter table mvc_board auto_increment = 1;
delete from mvc_board;

CREATE TABLE SEQUENCES
(
    NAME VARCHAR(32)
  , CURRVAL BIGINT UNSIGNED
);

call create_sequence('mvc_board');
insert into mvc_board (bId, bName, bTitle, bContent, bHit, bGroup, bStep, bIndent) values (nextval(mvc_board), 'a', 'b', 'c', 0, currval(mvc_board), 0, 0 )

