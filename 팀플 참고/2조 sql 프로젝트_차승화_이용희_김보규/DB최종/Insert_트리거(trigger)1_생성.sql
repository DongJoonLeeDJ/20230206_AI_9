create or replace trigger trig_room_add 
after insert on treatchart
for each row 
when (new.prescription like '%ют©Ь%') 
begin 
    insert into room values(trig_room_num.nextval,:new.time, :new.doc_id, :new.nur_id, :new.pat_id, :new.diagnosis);
 end trig_room;

