exec add_ticket(('ticket-'||lpad(ticket_cnt.nextval,3, 0)),
    'KAL-005','aa001',38,'12D','2022-08-01 11:30','KR/ICN','DE/HHH');
   
    
exec add_arrived('KR/TAE','대한민국/대구');
exec delete_ticket('ticket-028');
exec update_ticket_seat('ticket-029', '28D');


select * from ticket where flight_num='KAL-005';
select * from ticket where flight_num='KAL-005';
select * from ticket where flight_num='KAL-005';

select * from ticket;
select * from arrive_nation;



