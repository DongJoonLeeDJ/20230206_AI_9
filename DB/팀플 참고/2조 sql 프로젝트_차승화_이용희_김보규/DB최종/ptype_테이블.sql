/*
���̺�2) �����з� ���̺�
�з��ڵ�   001   /   002     / 003 
������     �ǻ�      ��ȣ��      ȯ��
*/

create table ptype
(
    pt_code    char(3)         primary key,
    name       varchar2(20)    not null
);

insert into ptype values('001','�ǻ�');
insert into ptype values('002','��ȣ��');
insert into ptype values('003','ȯ��');
select pt_code �����ڵ�, name ������ from ptype;