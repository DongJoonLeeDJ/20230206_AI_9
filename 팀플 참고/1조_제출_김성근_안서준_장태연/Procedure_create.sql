--create

create or replace procedure add_arrived (
code varchar2,
name varchar2)
is begin
insert into arrive_nation values(code, name);
end add_arrived;

/

create or replace procedure delete_ticket(
tnum in varchar2 )
is begin 
delete from ticket where ticket_num = tnum;
end delete_ticket;

/

create or replace procedure update_ticket_seat (
tnum in varchar2,
changeseat in varchar2)
is begin
update ticket set seat = changeseat
where ticket_num = tnum;
end update_ticket_seat;

/

CREATE OR REPLACE FUNCTION ticket_info (
ticketinfo in VARCHAR2 ) 
RETURN VARCHAR2
IS v_nm varchar2(20);
BEGIN 
    select passenger.name
    into v_nm
    from ticket
    join passenger on ticket.name = passenger.passport
    where ticketinfo=ticket.ticket_num;
return ticketinfo||'의 승객명은 '||v_nm||'입니다.';
end ticket_info;
    
/

select ticket_info('ticket-018') as 승객정보 from dual;