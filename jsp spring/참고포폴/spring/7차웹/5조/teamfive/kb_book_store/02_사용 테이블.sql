drop table book;
drop table customer;
drop table orders;

create table book
(
bookid int primary key auto_increment, /* 서점 내부적으로 관리할 고유 코드*/
bookisbn varchar(13) unique not null, /*책 구분을 위한 고유 코드*/
bookname varchar(5000), /*책 이름*/
publisher varchar(5000), /*출판사*/
price int, /*책 가격*/
bookImg varchar(5000) /*책 이미지*/
);

create table customer
(custid varchar(50) primary key, /*회원 ID*/
name varchar(40), /* 회원명 */
address varchar(50), /* 회원 주소*/
phone varchar(20) unique); /* 회원 연락처 */

/* 고객 추가 시점. log테이블에도 기록하지만 정렬을 위하여 추가 */
ALTER TABLE `kb_book_store`.`customer` 
ADD COLUMN `insert_date` DATETIME NULL DEFAULT now() AFTER `phone`;


-- fk가 2개, book, customer에서 가져옴
create table orders 
(
   orderid int auto_increment primary key,
   custid varchar(50),
   bookid int,
   saleprice int,
   orderdate datetime default now(),
   foreign key (custid) references customer(custid),   
   foreign key (bookid) references book(bookid)
);