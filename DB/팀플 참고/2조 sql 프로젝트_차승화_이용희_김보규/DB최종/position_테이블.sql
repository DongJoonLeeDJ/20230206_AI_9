/*
���̺�3) ���� ���̺�
�����ڵ�    101(�ǻ�), 102, ..... ,201(��ȣ��) , 202 ,....
���޸�
*/

create table position
(
    po_code   char(3)       primary key,
    name      varchar2(30)  not null
);

insert into position values('101','������Ʈ');
insert into position values('102','ġ��');
insert into position values('103','��ο�');
insert into position values('104','����');
insert into position values('105','�ο���');
insert into position values('106','����');
insert into position values('201','��ȣ��');
insert into position values('202','����ȣ��');
insert into position values('203','��ȣ����');
insert into position values('204','��ȣ����');
select po_code �����ڵ�, name ���޸� from position;

