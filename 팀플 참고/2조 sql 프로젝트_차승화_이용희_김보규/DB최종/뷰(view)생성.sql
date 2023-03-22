-- �ǻ����� �� ����
select ptype.name ����, doc_id �ǻ��ȣ, major.name ����, person.name �̸�, gen ����, age ����,
       phone ��ȭ��ȣ, position.name ���� from person
       join ptype on person.pt_code = ptype.pt_code
       join major on person.m_code = major.m_code
       join position on person.po_code = position.po_code
       group by ptype.name,doc_id,major.name,person.name,gen,age,phone,position.name
       having ptype.name = '�ǻ�'
       order by major.name;

create view v_doctors as
       select ptype.name ����, doc_id �ǻ��ȣ, major.name ����, person.name �̸�, gen ����, age ����,
       phone ��ȭ��ȣ, position.name ���� from person
       join ptype on person.pt_code = ptype.pt_code
       join major on person.m_code = major.m_code
       join position on person.po_code = position.po_code
       group by ptype.name,doc_id,major.name,person.name,gen,age,phone,position.name
       having ptype.name = '�ǻ�'
       order by ptype.name;


-- ��ȣ������ �� ����
select ptype.name ����, nur_id ��ȣ���ȣ, major.name ����, person.name �̸�, gen ����, age ����,
       phone ��ȭ��ȣ, position.name ���� from person
       join ptype on person.pt_code = ptype.pt_code
       join major on person.m_code = major.m_code
       join position on person.po_code = position.po_code
       group by ptype.name,nur_id,major.name,person.name,gen,age,phone,position.name
       having ptype.name = '��ȣ��';
       
create view v_nurse as
       select ptype.name ����, nur_id ��ȣ���ȣ, major.name ����, person.name �̸�, gen ����, age ����,
       phone ��ȭ��ȣ, position.name ���� from person
       join ptype on person.pt_code = ptype.pt_code
       join major on person.m_code = major.m_code
       join position on person.po_code = position.po_code
       group by ptype.name,nur_id,major.name,person.name,gen,age,phone,position.name
       having ptype.name = '��ȣ��'
       order by ptype.name;


-- ȯ������ �� ����
select ptype.name ����, pat_id ȯ�ڹ�ȣ, person.name �̸�, gen ����, age ����, phone ��ȭ��ȣ from person
       join ptype on person.pt_code = ptype.pt_code
       group by ptype.name,pat_id,person.name,gen,age,phone
       having ptype.name = 'ȯ��'
       order by pat_id;

create view v_patients as
       select ptype.name ����, pat_id ȯ�ڹ�ȣ, person.name �̸�, gen ����, age ����, phone ��ȭ��ȣ from person
       join ptype on person.pt_code = ptype.pt_code
       group by ptype.name,pat_id,person.name,gen,age,phone
       having ptype.name = 'ȯ��'
       order by pat_id;   