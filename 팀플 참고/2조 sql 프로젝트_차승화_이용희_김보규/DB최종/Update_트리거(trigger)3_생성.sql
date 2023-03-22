create or replace trigger trig_room_upd 
after insert or update on treatchart
for each row 
when (new.prescription like '%����%') 
begin
    update room set time = :new.time where pat_id = :new.pat_id;
    update room set diagnosis = :new.diagnosis||' - ������' 
           where pat_id = :new.pat_id;
 end trig_room_upd; 
