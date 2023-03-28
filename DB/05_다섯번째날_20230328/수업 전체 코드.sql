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

alter table book drop column publisher;
alter table customer drop column address;
select* from book;
select*from customer;


--출판사 관리 테이블
create table publisherlist 
( code int primary key,
name varchar2(100) not null);

--주소 관리 테이블
create table addresslist
(code int primary key,
name varchar2(100) not null);

--컬럼 추가
alter table book add publishercode int;
alter table customer add addresscode int;
--외래키 추가
alter table book add constraint fk_pub 
foreign key(publishercode) references publisherlist(code);

alter table customer add constraint fk_address 
foreign key(addresscode) references addresslist(code);



insert into publisherlist values(1,'굿스포츠');
insert into publisherlist values(2,'나무수');
insert into publisherlist values(3,'대한미디어');
insert into publisherlist values(4,'이상미디어');
insert into publisherlist values(5,'삼성당');
insert into publisherlist values(6,'Pearson');
insert into publisherlist values(7,'문학동네');

insert into addresslist values(1,'영국 맨체스타');
insert into addresslist values(2,'대한민국 서울');
insert into addresslist values(3,'대한민국 강원도');
insert into addresslist values(4,'미국 클리블랜드');
insert into addresslist values(5,'대한민국 대전');

select * from book;

update book set publishercode = 1 where bookid in(1,5,6);
update book set publishercode = 2 where bookid in(2);
update book set publishercode = 3 where bookid in(3,4);
update book set publishercode = 4 where bookid in(7,8);
update book set publishercode = 5 where bookid in(9);
update book set publishercode = 6 where bookid in(10);

select * from book;

--이젠 두 개의 테이블을 join해야 우리가 원래 알던 book 테이블 형태를 볼 수 있다.(출판사 이름)
select bookid, bookname, price, publisherlist.name publisher from 
book join publisherlist on book.publishercode=publisherlist.code;


update customer set addresscode=1 where custid=1;
update customer set addresscode=2 where custid=2;
update customer set addresscode=3 where custid=3;
update customer set addresscode=4 where custid=4;
update customer set addresscode=5 where custid=5;

select custid, customer.name, addresslist.name address, phone from 
customer join addresslist on customer.addresscode=addresslist.code;



-- 트랜잭션 : 하나의 행위를 세는 단위
-- 한 번의 트랜 잭션이 insert나 update나 delete 한 번일 수도 있고
-- 한 번의 트랜 잭션이 insert 100번, update 50번, delete 10번을 묶어서 하나의 트랜잭션으로 보기도 한다.
insert into customer (custid,name) values (6, '손흥민');
insert into addresslist values (6,'영국 토트넘');
update customer set addresscode=6 where custid=6;
insert into customer values(7,'홍진호','22',2);
select * from customer;

insert into book values(11, '말씀중에 죄송합니다.', 10000,1);
insert into book values(12, '연금술사', 8500,7);
insert into book values(13, 'Computer Science', 20000,6);
insert into book values(14, '피겨하는 여자', 10000,2);
insert into book values(15, '이재용의 성공신화', 30000,6);

select * from book;
select * from customer;

update book set bookname ='연금술사' where bookname='연금술사.';

INSERT INTO orders(custid, bookid, saleprice) VALUES (1, 4, (select price from book where bookid=4));
INSERT INTO orders(custid, bookid, saleprice) VALUES (2, 1, (select price from book where bookid=1));
INSERT INTO orders(custid, bookid, saleprice) VALUES (3, 2, (select price from book where bookid=2));
INSERT INTO orders(custid, bookid, saleprice) VALUES (1, 3, (select price from book where bookid=3));
INSERT INTO orders(custid, bookid, saleprice) VALUES (4, 5, (select price from book where bookid=5));
INSERT INTO orders(custid, bookid, saleprice) VALUES (5, 6, (select price from book where bookid=6));
INSERT INTO orders(custid, bookid, saleprice) VALUES (2, 7, (select price from book where bookid=7));
INSERT INTO orders(custid, bookid, saleprice) VALUES (3, 8, (select price from book where bookid=8));
INSERT INTO orders(custid, bookid, saleprice) VALUES (4, 9, (select price from book where bookid=9));
INSERT INTO orders(custid, bookid, saleprice) VALUES (5, 10, (select price from book where bookid=10));



select * from orders;

INSERT INTO orders(custid, bookid, saleprice) VALUES (6, 9, (select price from book where bookid=9));
INSERT INTO orders(custid, bookid, saleprice) VALUES (7, 10, (select price from book where bookid=10));

INSERT INTO orders(custid, bookid, saleprice) VALUES (6, 11, (select price from book where bookid=11));
INSERT INTO orders(custid, bookid, saleprice) VALUES (5, 12, (select price from book where bookid=12));
INSERT INTO orders(custid, bookid, saleprice) VALUES (4, 13, (select price from book where bookid=13));
INSERT INTO orders(custid, bookid, saleprice) VALUES (5, 14, (select price from book where bookid=14));
INSERT INTO orders(custid, bookid, saleprice) VALUES (7, 15, (select price from book where bookid=15));


select * from orders;

select orderid, customer.name, book.bookname, saleprice from
orders join customer on orders.custid = customer.custid join book on 
orders.bookid = book.bookid order by orderid;



-- 시퀀스는 오류날 경우에도 자동 증가하므로 이 부분 유의할 것
INSERT INTO orders(orderid, custid, bookid, saleprice) VALUES (myorder.nextval,'A','B','C'); -- 부적절한 구문
INSERT INTO orders(custid, bookid, saleprice) VALUES (7, 15, (select price from book where bookid=15));
select * from orders;





commit;
set autocommit on;
set autocommit off;
show autocommit;


-- 프로시저 : 함수랑 유사한 것
-- 하나 이상의 트랜 잭션을 손쉽게 호출해주는 것
-- 함수 : 함수는 러프하게 말하면 리턴타입있는 것, 프로시저는 리턴타입이 없는 것
-- 엄밀하게 말하면 이게 아니다.
-- 정확하게 말하면 프로시저나 함수나 둘 다 리턴타입도 있고 매개변수도 있다.
-- 이 것들을 잘 활용하면 코드가 훨씬 편해진다.
-- 둘의 차이 : 프로시저 안에 함수 있다. 하나의 프로 시저 안에 여러 개의 함수가 있을 수 있다.
-- 함수가 조금 더 작은 단위

-- 프로시저 : insert, update, delete와 같은 트랜잭션을 좀 더 간단하게 수행하게 해줌
create table simple_test_table(
num int primary key,
name varchar2(30) not null,
hp varchar2(20) unique);

insert into simple_test_table values(1, '이동준', '010-2940-1613');
insert into simple_test_table values(2,'신동훈',null);

--이제부터... 프로시저를 통해서 insert, update, delete 그리고 select를 해볼 것이다.


--alt + f10 sql 워크시트 새로 생성
-- 사람 추가하는 프로시저
-- in : 매개변수
-- myname이랑 myhp 뒤에도 in이 붙어야 하는 데,
--하나만 붙어도 나머지 애들도 다 매개변수라고 생각함
--in은 아예 생략하는 것도  생략이 가능하다.
create or replace procedure add_person
(
mynum in int,
myname varchar2,
myhp varchar2
)
is begin 
insert into simple_test_table values(mynum,myname,myhp);
end add_person;

-- 다 만들었으면 다른 워크시트에서 프로시저를 호출하는 게 좋으나 굳이
--같은 워크시트(.sql파일)에서 하고 싶다면 /를 하나 써주고 나서 그 밑에 호출해본다.

--프로시저를 그냥 함수처럼 호출해서 쓴다.
-- 잘 만들어 두면 insert, update, delete를 좀 더 편하게 호출할 수 있다.
exec add_person(3,'박연진','4444');
select * from simple_test_table;

-- create or replace : 같은 이름의 프로시저를 또 만드려고 하면 덮어쓴다
-- 없으면 새로 만든다.
create or replace procedure delete_person
(mynum in int)
is begin 
    delete from simple_test_table where num=mynum;
end delete_person;
/
exec delete_person(2);
select * from simple_test_table;
exec add_person(2,'서정빈',NULL);


--CREATE OR REPLACE에서 OR REPLACE가 없으면 어떻게 될까?
-- => 같은 이름으로 된 프로시저를 못 만든다. 만들고 싶다면 직접 DROP하고 다시 만들어야 됨
-- => 혹은 SQL DEVELOPER GUI 툴에서 새로 고쳐야 한다.
-- 또 만들려고 할 경우
-- ORA-00955: 기존의 객체가 이름을 사용하고 있습니다. 이런 에러 띄움

--이름 끝에 학생이라는 글자를 추가할 것
CREATE PROCEDURE UPDATE_PERSON
(MYNUM IN INT, NEWNAME IN VARCHAR2)
IS TEMPVAR VARCHAR2(20) := '학생';
    BEGIN TEMPVAR := NEWNAME || TEMPVAR;
    UPDATE SIMPLE_TEST_TABLE SET NAME=TEMPVAR WHERE 
    NUM = MYNUM;
END UPDATE_PERSON;
-- || 기호는 글자 이어 붙이기(SHIFT랑 역슬래시 같이 누르는 OR기호임)
/
EXEC UPDATE_PERSON(1,'박보검');
SELECT * FROM SIMPLE_TEST_TABLE;

--select 
/
CREATE OR REPLACE PROCEDURE PERSON_SELECT(
MYNAME IN VARCHAR2,
O_CURSOR OUT SYS_REFCURSOR)
    IS BEGIN OPEN O_CURSOR 
    FOR 
    SELECT NUM,NAME,HP FROM SIMPLE_TEST_TABLE WHERE 
    NAME = MYNAME;
    EXCEPTION WHEN OTHERS THEN DBMS_OUTPUT.PUT_LINE(
    'SQL ERROR' || SQLERRM);
END PERSON_SELECT; 
/



var o_cursor refcursor 
exec person_select('서정빈', :o_cursor) 
print o_cursor;








