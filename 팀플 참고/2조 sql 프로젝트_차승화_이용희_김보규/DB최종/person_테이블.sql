/*
테이블4) 사람테이블
직업분류코드   001,002,003
의사번호      222(2022년)01(전공)1(의사)0001
간호사번호    222(2022년)01(전공)2(간호사)0001
환자번호      1,2,3....
전공분류코드(의사,간호사)   101,102,...,201,202...
이름
성별
나이
전화번호
직급(의사,간호사)
*/

create table person
(
    person_num    number        primary key,
    pt_code       char(3)       not null,    
    doc_id        number(10)    unique,    
    nur_id        number(10)    unique,    
    pat_id        number        unique,       
    m_code        char(2)       null,     
    name          varchar2(30)  not null,     
    gen           char(1)       not null,
    age           number        not null,
    phone         varchar2(20)  unique,       
    po_code       char(3)       null
);

alter table person add constraint fk_1 foreign key(m_code) references major(m_code);

alter table person add constraint fk_2 foreign key(pt_code) references ptype(pt_code);

alter table person add constraint fk_3 foreign key(po_code) references position(po_code);