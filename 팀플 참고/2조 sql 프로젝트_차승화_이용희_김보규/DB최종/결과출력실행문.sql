-- 1. ���̺��� ���� ���
select m_code �����ڵ�, name ������ from major;
select pt_code �����ڵ�, name ������ from ptype;
select po_code �����ڵ�, name ���޸� from position;
select person_num ��Ϲ�ȣ, pt_code �����ڵ�, doc_id �ǻ��ȣ, nur_id ��ȣ���ȣ, 
       pat_id ȯ�ڹ�ȣ, m_code �����ڵ�, name �̸�, gen ����, age ����,
       phone ��ȭ��ȣ, po_code �����ڵ�
       from person;
       
-- 2. ������ ��(view) ���� ���
select * from v_doctors;
select * from v_nurse;
select * from v_patients;

-- 3. ������ ���ν���(procedure) ����Ȯ��
var o_cursor refcursor 
exec select_person('�̵���', :o_cursor)
print o_cursor;

-- 4. person ���̺��� ������ 'F'�϶��� ��� ���� ���
select avg(age) from person where gen = 'F';
-- 5. person ���̺��� ������ 'F'�̸鼭 ���̰� (������ 'F'�϶��� ��ճ���) �� ���ų� ���� 
--    ������ �����ϴ� ������ ���� ���
select person_num ��Ϲ�ȣ, pt_code �����ڵ�, doc_id �ǻ��ȣ, nur_id ��ȣ���ȣ, 
       pat_id ȯ�ڹ�ȣ, m_code �����ڵ�, name �̸�, gen ����, age ����,
       phone ��ȭ��ȣ, po_code �����ڵ�
       from person 
       where age <= (select avg(age) from person where gen = 'F') and gen = 'F';
             

-- 6. treatchart ���̺� ������ �Է�(Ʈ���ſ� ���� room ���̺� ������ �Է�,����,����)
insert into treatchart values
(2209001,'22/09/01',2220110002,2220120001,1,
'����, ��������','������','��Ģ���� �, �ݿ�����, �����κ�');
insert into treatchart values
(2209002,'22/09/01',2221310002,2221320001,2,
'��, �̸�, ����, ���� ����','�޼� ���̿�','�׻���, ������');
insert into treatchart values
(2209003,'22/09/01',2220510001,2220520002,4,
'������ ���� �����̸� ���� ����, �ٸ����� �ٸ�','���� ����','�Կ�');
insert into treatchart values
(2209004,'22/09/02',2224910001,2224920002,3,
'ġ������','�ź� �����','��ġ');
insert into treatchart values
(2209005,'22/09/02',2221210001,2221220002,5,
'����, ����, �� ������','�˷����⼺ �ḷ��','������Ÿ��, ������ ȿ�� �Ⱦ�');
insert into treatchart values
(2209006,'22/09/03',2220510001,2220520002,4,
'���� ������ ���� ���ϰ� ���� �ִ� ���� ��������','���� ����','���� ���� ����');
insert into treatchart values
(2209007,'22/09/03',2220110002,2220120002,3,
'��������, ����','�޼� ���忰','�Կ�');
insert into treatchart values
(2209008,'22/09/05',2220510001,2220520002,4,
'���� �� ����ȸ��','���� ����','���');

select id ��Ʈ��ȣ, time ����, v_doctors.�̸� ����ǻ�, v_nurse.�̸� ��簣ȣ��, 
       v_patients.�̸� ȯ��, symptoms ����, diagnosis ����, prescription ó��
       from treatchart
       join v_doctors on treatchart.doc_id = v_doctors.�ǻ��ȣ
       join v_nurse on treatchart.nur_id = v_nurse.��ȣ���ȣ
       join v_patients on treatchart.pat_id = v_patients.ȯ�ڹ�ȣ
       order by id;
       
select time ����, v_doctors.�̸� ����ǻ�, v_nurse.�̸� ��簣ȣ��,
       v_patients.�̸� ȯ��, diagnosis ���� from room
       join v_doctors on room.doc_id = v_doctors.�ǻ��ȣ
       join v_nurse on room.nur_id = v_nurse.��ȣ���ȣ
       join v_patients on room.pat_id = v_patients.ȯ�ڹ�ȣ;

-- 7. �Լ� count_room() ���๮
select count_room() �����Կ���ȯ�ڼ� from dual;