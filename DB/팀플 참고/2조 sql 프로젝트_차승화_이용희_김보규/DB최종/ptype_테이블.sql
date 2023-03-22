/*
테이블2) 직업분류 테이블
분류코드   001   /   002     / 003 
직업명     의사      간호사      환자
*/

create table ptype
(
    pt_code    char(3)         primary key,
    name       varchar2(20)    not null
);

insert into ptype values('001','의사');
insert into ptype values('002','간호사');
insert into ptype values('003','환자');
select pt_code 직업코드, name 직업명 from ptype;