call insert_book_price('시작0 ~ 5,000',  get_book_count_price(0,5000));
call insert_book_price('5,000 ~ 10,000',  get_book_count_price(5000,10000));
call insert_book_price('10,000 ~ 15,000',  get_book_count_price(10000,15000));
call insert_book_price('15,000 ~ 20,000',  get_book_count_price(15000,20000));
call insert_book_price('20,000 ~ 25,000',  get_book_count_price(20000,25000));
call insert_book_price('25,000 ~ 30,000',  get_book_count_price(25000,30000));
call insert_book_price('30,000 ~ ',  get_book_count_price(-1,30000));

select * from bookprice;
