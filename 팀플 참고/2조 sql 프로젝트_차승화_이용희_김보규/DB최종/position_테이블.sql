/*
테이블3) 직급 테이블
직급코드    101(의사), 102, ..... ,201(간호사) , 202 ,....
직급명
*/

create table position
(
    po_code   char(3)       primary key,
    name      varchar2(30)  not null
);

insert into position values('101','레지던트');
insert into position values('102','치프');
insert into position values('103','펠로우');
insert into position values('104','과장');
insert into position values('105','부원장');
insert into position values('106','원장');
insert into position values('201','간호사');
insert into position values('202','수간호사');
insert into position values('203','간호과장');
insert into position values('204','간호부장');
select po_code 직급코드, name 직급명 from position;

