drop table orders;
drop table book;
drop table customer;
drop sequence myorder;


create table book
(
bookid int primary key,
bookname varchar2(40) not null,
publisher varchar2(40) not null,
price int
);
create table customer
(
custid int primary key,
name varchar2(40) not null,
address varchar2(50),
phone varchar2(20) unique
);

create sequence myorder;
create table orders(
orderid int default myorder.nextval primary key,
custid int references customer(custid),
bookid int references book(bookid),
saleprice int,
orderdate date default sysdate
);

insert into book values(1,'축구의 역사', '굿스포츠', 7000);
insert into book values(2,'축구아는 여자', '나무수', 13000);
insert into book values(3,'축구의 이해', '대한미디어', 22000);
insert into book (bookid,bookname,publisher,price)
values(4,'골프 바이블', '대한미디어', 35000);
insert into book values(5,'피겨 교본', '굿스포츠', 8000);
insert into book values(6,'역도 단계별기술', '굿스포츠', 6000);
insert into book values(7,'야구의 추억', '이상미디어', 20000);
insert into book values(8,'야구를 부탁해', '이상미디어', 13000);
insert into book values(9,'올림픽 이야기', '삼성당', 7500);
insert into book values(10,'Olympic Champions', 
'Pearson', 13000);



insert into customer values
(1,'박지성','영국 맨체스타','000-5000-0001');
insert into customer values
(2,'김연아','대한민국 서울','000-6000-0001');
insert into customer values
(3,'장미란','대한민국 강원도','000-7000-0001');
insert into customer values
(4,'추신수','미국 클리블랜드','000-8000-0001');
insert into customer values
(5,'박세리','대한민국 대전',NULL);

select * from customer;


-- myorder라는 시퀀스를 사용할 것
-- select문을 활용해서 bookid와 연계해서 saleprice를 집어넣기
insert into orders values 
(myorder.nextval, 1,1,7000,'2014-07-01');

--myorder를 생략(단, 이럴 경우 컬럼명 명시해서 insert하기)
insert into orders (custid,bookid,saleprice,orderdate) 
values (1,3,22000,'2014-07-03');

select * from orders;

-- 쿼리문 안에 또 다른 쿼리문을 삽입하는 것 = 중첩질의
-- 조회나 insert 등 여러 가지 방안에서 활용됨
-- 중첩 질의를 잘 짜면 내가 원하는 결과물을 볼 수 있으나
-- 너무 중첩 많이 되면 보기 어려우니 view를 적절히 섞어줘야 한다.
-- DBMS에서도 C처럼 함수를 만들 수 있다. 함수를 활용해서 적절히 써줄 수도 있다.
insert into orders(custid,bookid,saleprice,orderdate)
values (2,5,
(select price from book where bookid=5),'2014-07-03');

insert into orders(custid,bookid,saleprice,orderdate)
values(3,6,6000,'2014-07-04');

insert into orders(custid,bookid,saleprice,orderdate)
values(4,7,20000,'2014-07-05');


insert into orders(custid,bookid,saleprice,orderdate)
values(1,2,13000,'2014-07-07');

insert into orders(custid,bookid,saleprice,orderdate)
values(4,8,13000,'2014-07-07');

insert into orders(custid,bookid,saleprice,orderdate)
values(3,10,13000,'2014-07-08');

insert into orders(custid,bookid,saleprice,orderdate)
values(2,10,13000,'2014-07-09');

insert into orders(custid,bookid,saleprice,orderdate)
values(3,8,13000,'2014-07-10');

select * from orders;

--1. 5번 고객의 연락처를 추가하시오
update customer set phone='010-2940-1613' where custid=5;
select * from customer;

--2. 1번 고객의 address를 대한민국 서울로 변경하시오
update customer set address='대한민국 서울' where custid=1;

--3. 주문 내역에서 고객의 이름과 책 이름이 나오게 출력하시오.(join)
select orderid, customer.name, bookname, saleprice from 
orders join customer on orders.custid=customer.custid join 
book on orders.bookid=book.bookid;


--join된 결과물을 이용해서 view를 하나만 만들어 보자.
create view total_order_result as select orderid, customer.name, bookname, saleprice from 
orders join customer on orders.custid=customer.custid join 
book on orders.bookid=book.bookid;


select * from total_order_result;
--orderid를 기준으로 정렬하기
select * from total_order_result order by orderid;

--4. 출판사별 평균 가격을 출력하시오.
--~별로 분류하기 위해선 group by
select publisher, avg(price) from book group by publisher;

--5. 출판사별 최고 가격을 출력하시오.
select publisher, max(price) from book group by publisher;

--6.출판사별 평균 가격이 가장 비싼 출판사를 출력하시오.
-- 1. 출판사별 평균 가격 결과를 view로 만들어 준다.(4번 문제 답)
--ORA-00998: 이 식은 열의 별명과 함께 지정해야 합니다
-- avg(price)에 대해서 이름을 붙여줘야 함
create view avg_publisher_list as 
select publisher, avg(price) avg_price from book 
group by publisher;

select * from avg_publisher_list;

select publisher from avg_publisher_list where avg_price=
(select max(avg_price) from avg_publisher_list);


--7. 책 구매에 가장 돈을 적게 쓴 고객을 출력하시오.
select * from total_order_result;
-- 고객별 총 책 구매액 view
create view sum_price_customer_by as 
select name,sum(saleprice) sum_price from total_order_result 
group by name;
select * from sum_price_customer_by;
--7번 문제의 첫 번째 답
select name from sum_price_customer_by where sum_price=
(select min(sum_price) from sum_price_customer_by);
--책을 아예 구매하지 않은 박세리가 나오게 한 번 해보세요.


create view total_order_result_with_null as 
select orderid, customer.name, bookname, saleprice from 
orders right join customer on orders.custid=customer.custid 
left join book on orders.bookid=book.bookid;

select * from total_order_result_with_null;
--nvl : 해당 컬럼 값이 NULL이면 0으로 표시한다는 의미
create view orderlist as 
select orderid, name, bookname, nvl(saleprice, 0) spendmoney
from total_order_result_with_null;

select * from orderlist;

-- null 값은 is null 이렇게 체크함. 값=null 이렇게 체크하지 않음
-- null 체크 방법
select * from total_order_result_with_null where saleprice is null;
-- null 아닌 것만 띄우기
select * from total_order_result_with_null where saleprice is not null;

create view totalorderlist as 
select name, sum(spendmoney) totalmoney from orderlist 
group by name;

--7번 문제의 두 번째 답
select name from totalorderlist where totalmoney=
(select min(totalmoney) from totalorderlist);



--8. 평균 책 구매 가격이 비싼 고객을 출력하시오.
-- 고객들이 어떤 책 샀는지
select * from orderlist;
-- 각 고객별로 평균적으로 돈을 얼마 썼는 지
select name, 
round(avg(spendmoney),1) from orderlist 
group by name;

create view avg_orderlist as 
select name, 
round(avg(spendmoney),1) avgmoney 
from orderlist 
group by name;

select * from avg_orderlist;
select name from avg_orderlist where 
avgmoney = (select max(avgmoney) from avg_orderlist);

--9.책을 가장 많이 구매한 고객을 출력하시오.
--실제로 책을 구매한 고객만 나옴
select * from total_order_result;
select name, count(*) from total_order_result group by name;


--view 없이 한 것...
select name from 
(select name, count(*) tcount from total_order_result group by name) temp 
where tcount=(select max(tcount) from (select name, count(*) tcount 
from total_order_result group by name))

-- view를 사용
create view countlist as 
select name, count(*) countbook from total_order_result group by name;

select * from countlist;
-- 답
select name from countlist where countbook = (
select max(countbook) from countlist);

/*
10. 1번 고객이 10번 책을 추가 구매하려고 한다.
Insert든 updat든 saleprice는 반드시 book테이블 참조할 것
1번 고객의 saleprice를 90%로 변경하기 ex. 10,000->9,000
*/
insert into orders (custid,bookid,saleprice) values 
(1,10,(select price from book where bookid=10));

select * from orders;

-- 1번 고객의 saleprice를 90%로 변경
update orders set saleprice=saleprice*0.9 where custid=1;


-- 출판사를 관리하는 테이블을 따로 만든다.
-- 출판사코드(int), 출판사명(varchar)
-- book 테이블의 publisher 컬럼을 삭제하고, 출판사를 관리하는 테이블이랑 연결한다.
-- 주소를 관리하는 테이블을 따로 만든다.
--주소코드(int), 주소명(varchar)
-- customer 테이블의 address를 삭제하고 주소를 관리하는 테이블이랑 연결한다.
-- 책 5개, 고객 2명을 자유롭게 추가한다.
-- orders에 주문 10개를 자유롭게 추가한다.