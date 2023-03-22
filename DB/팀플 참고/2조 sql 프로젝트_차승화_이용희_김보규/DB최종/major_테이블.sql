/*
테이블1) 전공테이블
전공코드 : 2자리코드
전공명
01 내과
05 정형외과
12 안과
13 이비인후과
49 치과
*/

create table major
(
    m_code     char(2)       primary key,
    name       varchar2(20)  unique
);

insert into major values('01','내과');
insert into major values('05','정형외과');
insert into major values('12','안과');
insert into major values('13','이비인후과');
insert into major values('49','치과');
select m_code 전공코드, name 전공명 from major;