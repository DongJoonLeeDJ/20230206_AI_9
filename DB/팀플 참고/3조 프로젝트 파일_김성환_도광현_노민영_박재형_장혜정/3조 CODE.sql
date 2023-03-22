--3조 오라클 코드 시작

--테이블 생성( 고객, 옷, 주문, 사이즈)

create table customer ( --고객 : 고객코드(기본키), 이름, 주소
code varchar2(100) primary key,
name varchar2(100),
address varchar2(100),
p_num varchar2(100) unique
);

create table wear( -- 옷: 옷코드(기본키), 이름, 가격, 브랜드
code varchar2(100) primary key,
name varchar2(100),
price varchar2(100),
brand varchar2(100)
);

create table orders( --주문 : 주문코드(기본키), 주문번호, 고객코드, 옷코드, 날짜)
code varchar2(100) primary key,
order_num varchar2(100),
cust_code varchar2(100),
wear_code varchar2(100),
dates varchar2(100)
);

create table wear_size( --사이즈 : 사이즈코드(기본키), 사이즈
code varchar2(100) primary key,
sizes varchar2(100)
);

alter table orders add sizes varchar2(100);
--주문 테이블에 사이즈 컬럼을 추가

alter table wear modify price int;
--옷 테이블의 가격 컬럼 데이터 타입을 varchar2 에서 int로 변경

select *from customer;
select *from wear;
select *from orders;
select *from wear_size;

commit;


--고객 정보 삽입 

insert into customer values ('a8-4562', '이재용', '전라북도 익산시','010-1234-4321');
insert into customer values ('a8-5462', '최태원', '서울특별시 서초구','010-5046-8796');
insert into customer values ('a8-6492', '기성용', '서울특별시 강남구','010-4272-3141');
insert into customer values ('a4-5837', '이윤환', '강원도 강릉시','010-5462-6404');
insert into customer values ('a3-2547', '임윤아', '대구광역시 달서구','010-3716-1025');
insert into customer values ('a5-3184', '손예진', '대구광역시 수성구','010-7056-9599');
insert into customer values ('a2-1533', '김태평', '울산광역시 남구','010-2588-2002');
insert into customer values ('a1-8122', '김혜수', '인천광역시 미추홀구','010-3433-8765');
insert into customer values ('a5-2149', '박보영', '경상남도 합천군','010-9974-0425');
insert into customer values ('a9-1234', '안유진', '충청북도 청주시','010-8896-3142');

select *from customer;

--옷 정보 삽입 

insert into wear values ('bcfe2547', '플라워 마르디 피그먼트', 94000, '마르디 메크르디');
insert into wear values ('rcbf1839', '레드하트와펜 후드집업',308000 ,'꼼데가르송 플레이');
insert into wear values ('krdc4586', '칠랙스폭스 조거팬츠',247500 ,'메종키츠네');
insert into wear values ('oygh4539','타루가 퍼 트리밍 후디 구스다운',379000,'내셔널지오그래픽');
insert into wear values ('ymca6863','마뗑 킴 로고 크롭 탑',39000,'마뗑킴');
insert into wear values ('ibsf2444','크롭 데님 자켓',259000,'마리떼');
insert into wear values ('uysd8966','데이브레이크',199000,'나이키');
insert into wear values ('rprs5490','에어 하이웨이스트 바이크 쇼츠 레킹스',69900,'나이키');
insert into wear values ('zxyr3396','스티치 카드 케이스',387000,'메종 마르지엘라');
insert into wear values ('ptun2809','레이디 디올',7500000,'크리스찬 디올');
insert into wear values ('algl1004','알마BB',2010000,'루이비통');
insert into wear values ('nbss9654','트리오페 아세테이트 선글라스',590000,'셀린느');
insert into wear values ('ootd3522','셀린느 프린트 생티렁 스트랩 웨스턴 벨트',790000,'셀린느');
insert into wear values ('vtiq7511','셀린느 스카프',990000,'셀린느');
insert into wear values ('ljcp4545','인타르시아 니트 캐시미어',1890000,'미우미우');
insert into wear values ('ysdj1992','사블레 미니스커트',2020000,'미우미우');
insert into wear values ('mbgh2016','쟈도르 퍼퓸 100ML',248000,'크리스찬 디올');
insert into wear values ('sbit6604','CD귀걸이',560000,'크리스찬 디올');
insert into wear values ('cjis0762','1461스무스',19000,'닥터마틴');
insert into wear values ('shie3161','잔스포츠 엔보이 백팩',109000,'잔스포츠');

--옷 테이블의 특정 옷코드를 가지는 행의 가격 변경, 19000 -> 190000
update wear set price = 190000 where code='cjis0762';

select *from wear;

--주문 정보 삽입

insert into orders values ('akc458-1', 'akc458', 'a8-5462', 'ibsf2444', '2022-09-04', '01');
insert into orders values ('akc458-2', 'akc458', 'a8-5462', 'ysdj1992', '2022-09-04', '01');
insert into orders values ('bhc756-1', 'bhc756', 'a8-6492', 'uysd8966', '2022-08-31', '15');
insert into orders values ('kfc184-1', 'kfc184', 'a3-2547', 'ptun2809', '2021-12-25', '21');
insert into orders values ('cix887-1', 'cix887', 'a2-1533', 'algl1004', '2021-12-31', '20');
insert into orders values ('ttf119-1', 'ttf119', 'a8-4562', 'oygh4539', '2022-08-13', '04');
insert into orders values ('ttf119-2', 'ttf119', 'a8-4562', 'ljcp4545', '2022-08-13', '03');
insert into orders values ('ttf119-3', 'ttf119', 'a8-4562', 'cjis0762', '2022-08-13', '13');
insert into orders values ('sle345-1', 'sle345', 'a5-3184', 'algl1004', '2022-08-01', '22');
insert into orders values ('apk448-1', 'apk448', 'a5-3184', 'algl1004', '2022-09-01', '23');

select *from orders;

--외래키 지정

--주문 테이블의 고객코드는 고객 테이블의 고객코드를 참조한다.(외래키)
alter table orders add constraint fk_custcode
foreign key(cust_code) references customer(code);

--주문 테이블의 옷코드는 옷 테이블의 옷코드를 참조한다.(외래키)
alter table orders add constraint fk_wearcode
foreign key(wear_code) references wear(code);


--사이즈 정보 삽입

insert into wear_size values ('01','XS');
insert into wear_size values ('04','L');
insert into wear_size values ('03','M');
insert into wear_size values ('13','230');
insert into wear_size values ('15','250');
insert into wear_size values ('20','ONE SIZE');
insert into wear_size values ('21','S');
insert into wear_size values ('22','M');
insert into wear_size values ('23','L');

insert into wear_size values ('17','270');
insert into wear_size values ('18','280');
insert into wear_size values ('19','290');
insert into wear_size values ('24','XL');
insert into wear_size values ('25','2XL');

select *from wear_size;

commit;

--group by

--옷 테이블의 브랜드별 최고가격을 출력
select brand 브랜드, max(price) MAX from wear group by brand;

--옷 테이블의 브랜드별 최고가격이 2백만원 이상인 것을 출력
select brand 브랜드, max(price) MAX from wear group by brand having max(price)>2000000;


--행 삭제 delete -- 사이즈 테이블의 특정 사이즈코드를 가지는 행삭제

delete from wear_size where code='24';
delete from wear_size where code='25';
delete from wear_size where code='17';
delete from wear_size where code='18';
delete from wear_size where code='19';

select *from customer;


--행 수정 update

--고객 테이블의 특정 고객코드를 가지는 사람의 고객이름을 수정
update customer set name ='한혜진' where code='a8-6492';
update customer set name ='김현빈' where code='a2-1533';
--고객 테이블의 특정 고객코드를 가지는 행의 주소를 수정
update customer set address ='대전광역시 유성구' where code='a5-3184';
update customer set address ='대전광역시 유성구' where code='a2-1533';
--옷 테이블의 특정 옷코드를 가지는 행의 옷가격을 수정
update wear set price = 200000 where code='cjis0762';


--join
-- 주문 테이블의 고객코드와 고객 테이블의 고객코드를 연결하여
-- 주문번호, 주문날짜, 고객성명, 주소 등을 출력
select orders.order_num 주문번호, dates 주문날짜, customer.name 고객성명, address 주소 
from orders join customer on customer.code=orders.cust_code;

--<<  view  >>

--view 1
-- 주문 테이블의 고객코드와 고객 테이블의 고객코드를 연결하여
-- 주문번호, 주문날짜, 고객성명, 주소 등을 출력하는 가상테이블인 order_info를 생성
create view order_info as
select orders.order_num , dates , customer.name, address  
from orders join customer on customer.code=orders.cust_code;
select *from order_info;

--view2
--주문테이블의 고객코드를 고객테이블의 고객코드, 옷테이블의 옷코드와 각각 연결하여
--주문번호, 주문날짜, 고객성명, 주소, 상품명, 가격을 출력 (join)
select orders.order_num 주문번호, dates 주문날짜, customer.name 고객성명, address 주소, wear.name 상품명, wear.price 가격 
from orders join customer on customer.code=orders.cust_code
join wear on wear.code=orders.wear_code;

--주문테이블의 고객코드를 고객테이블의 고객코드, 옷테이블의 옷코드와 각각 연결하여
--주문번호, 주문날짜, 고객성명, 주소, 상품명, 가격을 출력하는 가상테이블인 order_info2 를 생성 
select *from order_info2;
create view order_info2 as
select orders.order_num , dates , customer.name cust_name, address , wear.name wear_name, wear.price  
from orders join customer on customer.code=orders.cust_code
join wear on wear.code=orders.wear_code;

--view3
--주문테이블의 고객코드를 고객테이블의 고객코드, 옷테이블의 옷코드와 각각 연결하여
--주문코드, 주문날짜, 고객성명, 주소, 상품명, 가격을 출력하는 가상테이블인 order_info3 를 생성
select *from order_info3;
create view order_info3 as
select orders.code , dates , customer.name cust_name, address , wear.name wear_name, wear.price  
from orders join customer on customer.code=orders.cust_code
join wear on wear.code=orders.wear_code;

select *from order_info3;

--view4
--주문테이블의 고객코드를 고객테이블의 고객코드와 연결하여
--주문번호와 전화번호를 출력하는 가상테이블인 find_pnum을 생성
create view find_pnum as
select distinct orders.order_num 주문번호, customer.p_num
from orders join customer on orders.cust_code=customer.code;

select *from find_pnum;

--중첩질의
--고객테이블의 특정 고객코드를 가지는 행의 이름이 주문정보 뷰의 특정고객 이름과
--같다면 그 고객의 주문정보를 출력
select *from order_info2 where cust_name = (select name from customer where code = 'a5-3184');

commit;


--------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------
--프로시저

--사이즈 관련, update문을 실행하는 프로시저 (주문 코드와 변경하는 사이즈를 입력하면
--해당 코드의 사이즈를 변경해주고 (수정)이라고 표시해준다.)

CREATE PROCEDURE UPDATE_SIZE
(
MYorder_code VARCHAR2 ,
changesize VARCHAR2 
)
IS TEMPVAR VARCHAR2(20) := '(수정)';
BEGIN TEMPVAR := changesize || TEMPVAR; 
UPDATE orders SET sizes=TEMPVAR WHERE 
code=MYorder_code;
END UPDATE_SIZE;

/
select *from orders;
exec update_size('akc458-1','02');
rollback;


--------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------
--함수

--고객 이름 관련, select문을 실행시켜주는 함수(주문코드를 입력하면
--고객정보 뷰의 고객명을 출력해준다.)

create or replace function find_name (v_order_code varchar2)
return varchar2
is v_cust_name varchar2(100);
begin select cust_name into v_cust_name
from order_info3 where code=v_order_code;
return v_cust_name;
exception when others then 
DBMS_OUTPUT.PUT_LINE('exception occurred! ('||sqlcode||'):'||sqlerrm);
return '';
end;

/
select find_name('ttf119-1') from dual;


--------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------
--함수2

--고객 전화번호 관련, select 문을 실행시켜주는 함수 (주문번호를 입력하면
--전화번호 찾기 뷰의 전화번호를 출력시켜준다.)

create or replace procedure find_phone (v_order_num  varchar2,
o_cursor out sys_refcursor)
is begin open o_cursor 
for
select p_num from find_pnum where v_order_num=find_pnum.order_num;
exception when others then 
dbms_output.put_line('sql error : ' || sqlerrm);
END find_phone;


/
var o_cursor refcursor
exec find_phone('ttf119', :o_cursor)
print o_cursor;



















