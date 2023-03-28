select * from book;
select * from book where bookisbn='9788944983450';

select * from book where bookname='장흥';
select * from orders;
select find_price(2);
select count(*) from book;#1612
select count(*) from book where price >= 0 and price <5000;#1
select count(*) from book where  price >= 5000 and price  <10000;#185
select count(*) from book where  price >= 10000 and price  <15000;#417
select count(*) from book where  price >=  15000 and price  <20000;#415
select count(*) from book where price>=20000 and price <25000;#175
select count(*) from book where price>=25000 and price <30000;#148
select count(*) from book where price>=30000;#271


select get_book_count_price(0,5000);
select get_book_count_price(5000,10000);
select get_book_count_price(10000,15000);
select get_book_count_price(15000,20000);
select get_book_count_price(20000,25000);
select get_book_count_price(25000,30000);
select get_book_count_price(-1,30000);





