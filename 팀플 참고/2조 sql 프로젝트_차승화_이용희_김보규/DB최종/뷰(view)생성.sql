-- 의사정보 뷰 쿼리
select ptype.name 직업, doc_id 의사번호, major.name 전공, person.name 이름, gen 성별, age 나이,
       phone 전화번호, position.name 직급 from person
       join ptype on person.pt_code = ptype.pt_code
       join major on person.m_code = major.m_code
       join position on person.po_code = position.po_code
       group by ptype.name,doc_id,major.name,person.name,gen,age,phone,position.name
       having ptype.name = '의사'
       order by major.name;

create view v_doctors as
       select ptype.name 직업, doc_id 의사번호, major.name 전공, person.name 이름, gen 성별, age 나이,
       phone 전화번호, position.name 직급 from person
       join ptype on person.pt_code = ptype.pt_code
       join major on person.m_code = major.m_code
       join position on person.po_code = position.po_code
       group by ptype.name,doc_id,major.name,person.name,gen,age,phone,position.name
       having ptype.name = '의사'
       order by ptype.name;


-- 간호사정보 뷰 쿼리
select ptype.name 직업, nur_id 간호사번호, major.name 전공, person.name 이름, gen 성별, age 나이,
       phone 전화번호, position.name 직급 from person
       join ptype on person.pt_code = ptype.pt_code
       join major on person.m_code = major.m_code
       join position on person.po_code = position.po_code
       group by ptype.name,nur_id,major.name,person.name,gen,age,phone,position.name
       having ptype.name = '간호사';
       
create view v_nurse as
       select ptype.name 직업, nur_id 간호사번호, major.name 전공, person.name 이름, gen 성별, age 나이,
       phone 전화번호, position.name 직급 from person
       join ptype on person.pt_code = ptype.pt_code
       join major on person.m_code = major.m_code
       join position on person.po_code = position.po_code
       group by ptype.name,nur_id,major.name,person.name,gen,age,phone,position.name
       having ptype.name = '간호사'
       order by ptype.name;


-- 환자정보 뷰 쿼리
select ptype.name 직업, pat_id 환자번호, person.name 이름, gen 성별, age 나이, phone 전화번호 from person
       join ptype on person.pt_code = ptype.pt_code
       group by ptype.name,pat_id,person.name,gen,age,phone
       having ptype.name = '환자'
       order by pat_id;

create view v_patients as
       select ptype.name 직업, pat_id 환자번호, person.name 이름, gen 성별, age 나이, phone 전화번호 from person
       join ptype on person.pt_code = ptype.pt_code
       group by ptype.name,pat_id,person.name,gen,age,phone
       having ptype.name = '환자'
       order by pat_id;   