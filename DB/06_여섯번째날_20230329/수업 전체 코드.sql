CREATE OR REPLACE FUNCTION MYTEST_FUNC RETURN VARCHAR IS 
V_TEST VARCHAR2(100);
BEGIN 
    V_TEST :='이동준';
    RETURN V_TEST;
END;
/
-- DUAL : 임시테이블. 실제 존재하는 건 아니고 간단한 함수를 테스트할때 쓰는 구문
--무조건 이동준이라는 문자열만 리턴을 한다.
SELECT MYTEST_FUNC() FROM DUAL;
insert into simple_test_table values(5,MYTEST_FUNC(),NULL);
select * from simple_test_table;


-- 매개변수랑 리턴이 있는 함수
--함수를 만들기 전에 미리 해야할 수도 있는 작업 이 있다.
set serveroutput on; -- 안 해도 되는 자리도 있으나 이 걸 해야 원활하게 돌아갈 수 있다.

/
create or replace function func_getperson(v_num int)
return varchar is v_name varchar2(100);
begin 
    select name into v_name from simple_test_table where num=v_num;
    return v_name;
exception when others then 
    DBMS_OUTPUT.PUT_LINE('except! ' || sqlcode || '):'||sqlerrm);
    return ''; --쌍따옴표 아니고 따옴표 2개임
end;
/


select func_getperson(3) from dual;
insert into simple_test_table values 
(10, func_getperson(2), '123');


select * from simple_test_table;


commit;