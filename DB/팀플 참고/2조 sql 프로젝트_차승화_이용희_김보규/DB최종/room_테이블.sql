/*
테이블6) 입원환자 테이블
입원기록번호
입원날짜
담당의사번호
담당 간호사번호
환자 번호
병명
*/

create table room
(
    room_num    number         primary key,
    time        date           not null,
    doc_id      number(10)     not null,
    nur_id      number(10)     not null,
    pat_id      number         not null,
    diagnosis   varchar2(1000) not null
);


alter table room add constraint fk_7 foreign key(doc_id) references person(doc_id);

alter table room add constraint fk_8 foreign key(nur_id) references person(nur_id);

alter table room add constraint fk_9 foreign key(pat_id) references person(pat_id);