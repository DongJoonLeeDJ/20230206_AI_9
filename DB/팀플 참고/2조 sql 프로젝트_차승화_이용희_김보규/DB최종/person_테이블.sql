/*
���̺�4) ������̺�
�����з��ڵ�   001,002,003
�ǻ��ȣ      222(2022��)01(����)1(�ǻ�)0001
��ȣ���ȣ    222(2022��)01(����)2(��ȣ��)0001
ȯ�ڹ�ȣ      1,2,3....
�����з��ڵ�(�ǻ�,��ȣ��)   101,102,...,201,202...
�̸�
����
����
��ȭ��ȣ
����(�ǻ�,��ȣ��)
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