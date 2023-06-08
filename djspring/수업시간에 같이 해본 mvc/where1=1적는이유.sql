select book_id,title,category,price,insert_date from book 
where 1=1
and title like '%공부%' 
or category like '%공부%';

select book_id,title,category,price,insert_date from book 
where 1 = 1 
-- and title like '%공부%' 
or category like '%공부%';


select book_id,title,category,price,insert_date from book 
where 1 = 1 
 and title like '%공부%' ;
-- or category like '%공부%';


select book_id,title,category,price,insert_date from book 
where title like '%공부%' ;
-- or category like '%공부%';

select book_id,title,category,price,insert_date from book 
-- where title like '%공부%' ;
where category like '%공부%';