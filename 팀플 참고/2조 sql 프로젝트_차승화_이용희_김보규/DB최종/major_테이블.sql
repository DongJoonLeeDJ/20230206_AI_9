/*
���̺�1) �������̺�
�����ڵ� : 2�ڸ��ڵ�
������
01 ����
05 �����ܰ�
12 �Ȱ�
13 �̺����İ�
49 ġ��
*/

create table major
(
    m_code     char(2)       primary key,
    name       varchar2(20)  unique
);

insert into major values('01','����');
insert into major values('05','�����ܰ�');
insert into major values('12','�Ȱ�');
insert into major values('13','�̺����İ�');
insert into major values('49','ġ��');
select m_code �����ڵ�, name ������ from major;