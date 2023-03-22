create or replace procedure select_person
(   
    myname in varchar2, 
    o_cursor in out sys_refcursor
)
    is begin open o_cursor for 
    select * from person where name = myname; 
    EXCEPTION when others then 
    dbms_output.put_line('error'); 
    end select_person;