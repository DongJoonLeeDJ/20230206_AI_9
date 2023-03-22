/*
테이블5) 진료차트 테이블
진료차트 번호  :7자리 22(년도)09(월)001
진료날짜
담당의사번호
담당간호사번호
환자번호
증상
진단
처방
*/

create table treatchart
(
    id            number(7)      primary key,     
    time          date           default sysdate,
    doc_id        number(10)     not null,     
    nur_id        number(10)     not null,
    pat_id        number         not null,     
    symptoms      varchar2(1000) not null,
    diagnosis     varchar2(1000) not null,
    prescription  varchar2(1000) not null   
);

alter table treatchart add constraint fk_4 foreign key(doc_id) references person(doc_id);

alter table treatchart add constraint fk_5 foreign key(nur_id) references person(nur_id);

alter table treatchart add constraint fk_6 foreign key(pat_id) references person(pat_id);

