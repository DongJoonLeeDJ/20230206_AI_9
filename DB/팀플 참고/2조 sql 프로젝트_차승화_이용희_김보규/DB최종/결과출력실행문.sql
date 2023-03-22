-- 1. 테이블에서 정보 출력
select m_code 전공코드, name 전공명 from major;
select pt_code 직업코드, name 직업명 from ptype;
select po_code 직급코드, name 직급명 from position;
select person_num 등록번호, pt_code 직업코드, doc_id 의사번호, nur_id 간호사번호, 
       pat_id 환자번호, m_code 전공코드, name 이름, gen 성별, age 나이,
       phone 전화번호, po_code 직급코드
       from person;
       
-- 2. 생성된 뷰(view) 정보 출력
select * from v_doctors;
select * from v_nurse;
select * from v_patients;

-- 3. 생성된 프로시저(procedure) 실행확인
var o_cursor refcursor 
exec select_person('이동준', :o_cursor)
print o_cursor;

-- 4. person 테이블에서 성별이 'F'일때의 평균 나이 출력
select avg(age) from person where gen = 'F';
-- 5. person 테이블에서 성별이 'F'이면서 나이가 (성별이 'F'일때의 평균나이) 와 같거나 작은 
--    조건을 만족하는 데이터 정보 출력
select person_num 등록번호, pt_code 직업코드, doc_id 의사번호, nur_id 간호사번호, 
       pat_id 환자번호, m_code 전공코드, name 이름, gen 성별, age 나이,
       phone 전화번호, po_code 직급코드
       from person 
       where age <= (select avg(age) from person where gen = 'F') and gen = 'F';
             

-- 6. treatchart 테이블 데이터 입력(트리거에 의해 room 테이블에 데이터 입력,수정,삭제)
insert into treatchart values
(2209001,'22/09/01',2220110002,2220120001,1,
'두통, 어지러움','고혈압','규칙적인 운동, 금연권장, 아프로벨');
insert into treatchart values
(2209002,'22/09/01',2221310002,2221320001,2,
'고열, 이명, 두통, 귀의 통증','급성 중이염','항생제, 진통제');
insert into treatchart values
(2209003,'22/09/01',2220510001,2220520002,4,
'엉덩이 관절 움직이면 심한 통증, 다리길이 다름','대퇴 골절','입원');
insert into treatchart values
(2209004,'22/09/02',2224910001,2224920002,3,
'치아통증','매복 사랑니','발치');
insert into treatchart values
(2209005,'22/09/02',2221210001,2221220002,5,
'충혈, 눈곱, 눈 가려움','알레르기성 결막염','항히스타민, 항출혈 효과 안약');
insert into treatchart values
(2209006,'22/09/03',2220510001,2220520002,4,
'골절 부위가 서로 심하게 박혀 있는 감입 골절상태','대퇴 골절','나사 고정 수술');
insert into treatchart values
(2209007,'22/09/03',2220110002,2220120002,3,
'복부통증, 구토','급성 췌장염','입원');
insert into treatchart values
(2209008,'22/09/05',2220510001,2220520002,4,
'수술 후 완전회복','대퇴 골절','퇴원');

select id 차트번호, time 일자, v_doctors.이름 담당의사, v_nurse.이름 담당간호사, 
       v_patients.이름 환자, symptoms 증상, diagnosis 진단, prescription 처방
       from treatchart
       join v_doctors on treatchart.doc_id = v_doctors.의사번호
       join v_nurse on treatchart.nur_id = v_nurse.간호사번호
       join v_patients on treatchart.pat_id = v_patients.환자번호
       order by id;
       
select time 일자, v_doctors.이름 담당의사, v_nurse.이름 담당간호사,
       v_patients.이름 환자, diagnosis 병명 from room
       join v_doctors on room.doc_id = v_doctors.의사번호
       join v_nurse on room.nur_id = v_nurse.간호사번호
       join v_patients on room.pat_id = v_patients.환자번호;

-- 7. 함수 count_room() 실행문
select count_room() 현재입원한환자수 from dual;