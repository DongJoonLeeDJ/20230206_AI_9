create or replace function count_room
return int
is 
    c_room int;
begin 
    select count(*) into c_room from room;
    return c_room;
end count_room;

