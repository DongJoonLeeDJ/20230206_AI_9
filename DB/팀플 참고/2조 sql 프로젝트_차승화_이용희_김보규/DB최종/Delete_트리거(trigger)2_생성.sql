create or replace trigger trig_room_del
after insert on treatchart
for each row 
when (new.prescription like '%ΕπΏψ%') 
begin 
    delete from room where pat_id = :new.pat_id;
 end trig_room;
