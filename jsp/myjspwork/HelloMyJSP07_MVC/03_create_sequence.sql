DELIMITER $$ 
create procedure `create_sequence` (IN the_name text) 
modifies sql data 
deterministic 
begin 
delete from sequences where name = the_name;
insert into sequences values(the_name,0);
end
