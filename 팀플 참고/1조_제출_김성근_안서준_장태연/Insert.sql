--테이블 항목 추가.SQL

--depart_nation 추가
insert into depart_nation values('KR/ICN', '대한민국/인천');
insert into depart_nation values('KR/CJU', '대한민국/제주');
insert into depart_nation values('JP/HND', '일본/하네다');
insert into depart_nation values('JP/NRT', '일본/나리타');
insert into depart_nation values('US/JFK', '미국/뉴욕');
insert into depart_nation values('US/LAX', '미국/LA');
insert into depart_nation values('GB/LHR', '영국/런던');
insert into depart_nation values('TW/TPE', '대만/타오위안');
insert into depart_nation values('IT/FCO', '이탈리아/로마');
insert into depart_nation values('DE/HHH', '독일/프랑크푸르트');
insert into depart_nation values('CH/ZRH', '스위스/취리히');

--arrive_nation 추가
insert into arrive_nation values('KR/ICN', '대한민국/인천');
insert into arrive_nation values('KR/CJU', '대한민국/제주');
insert into arrive_nation values('JP/HND', '일본/하네다');
insert into arrive_nation values('JP/NRT', '일본/나리타');
insert into arrive_nation values('US/JFK', '미국/뉴욕');
insert into arrive_nation values('US/LAX', '미국/LA');
insert into arrive_nation values('GB/LHR', '영국/런던');
insert into arrive_nation values('TW/TPE', '대만/타오위안');
insert into arrive_nation values('IT/FCO', '이탈리아/로마');
insert into arrive_nation values('DE/HHH', '독일/프랑크푸르트');
insert into arrive_nation values('CH/ZRH', '스위스/취리히');

--passenger 추가
insert into passenger values('SJ960','안서준',27,'010-9465-7709');
insert into passenger values('SJ777','이정석',28,'010-1115-9999');
insert into passenger values('SH987','이승호',27,'010-5156-9977');
insert into passenger values('MW305','김민우',27,'010-1234-7895');
insert into passenger values('HM458','최효민',47,'010-3214-9876');
insert into passenger values('JH667','배재현',82,'010-4567-6543');
insert into passenger values('HW123','한현후',14,'010-6543-7418');
insert into passenger values('MJ872','김민준',47,'010-9009-8888');
insert into passenger values('TY446','장태연',54,'010-4945-7236');
insert into passenger values('SZ996','송지원',22,'010-2233-4411');
insert into passenger values('YY411','윤예일',29,'010-7755-3369');
insert into passenger values('CH119','채상혁',8,'010-5471-6664');
insert into passenger values('JY454','정용운',6,'010-4521-1614');
insert into passenger values('GA777','곽지원',45,'010-4451-6771');
insert into passenger values('MW123','최유석',71,'010-4778-8774');
insert into passenger values('JH852','문지호',44,'010-7891-1234');
insert into passenger values('PK557','박재성',14,'010-5068-4741');
insert into passenger values('SY004','송용수',24,'010-7412-6678');
insert into passenger values('KI112','김계영',26,'010-3214-3369');
insert into passenger values('KL447','김경엽',27,'010-7412-6678');
insert into passenger values('SG524','김성근',24,'010-5242-4439');
insert into passenger values('SI119','어수일',31,'010-2052-9645');
insert into passenger values('SM223','이상목',34,'010-9509-2095');
insert into passenger values('HT605','안현태',18,'010-5312-5239');
insert into passenger values('GM653','최규민',21,'010-7521-1452');
insert into passenger values('YH732','최윤흠',7,'010-2435-5626');
insert into passenger values('MY434','박민주',33,'010-9543-2463');
insert into passenger values('SJ312','김수정',100,'010-5622-1266');
insert into passenger values('BO650','김병오',47,'010-8544-2135');
insert into passenger values('DH926','김도희',55,'010-7161-1253');
insert into passenger values('aa001','테스트',71,'010-3333-1253');
--flight 추가

insert into flight values('KAL-001','2022-09-10 14:45',27,'KR/ICN','JP/HND');
insert into flight values('KAL-002','2022-09-25 07:15',07,'KR/ICN','JP/NRT');
insert into flight values('KAL-003','2022-09-17 22:25',41,'KR/CJU','JP/NRT');
insert into flight values('KAL-004','2022-09-17 08:30',15,'KR/ICN','US/LAX');
insert into flight values('OZ-001','2022-10-01 06:00',22,'KR/ICN','US/JFK');
insert into flight values('OZ-002','2022-10-10 05:30',23,'KR/ICN','GB/LHR');
insert into flight values('OZ-003','2022-09-30 07:30',26,'KR/ICN','TW/TPE');
insert into flight values('OZ-004','2022-10-21 20:30',20,'KR/ICN','IT/FCO');
insert into flight values('KAL-005','2022-11-09 08:20',31,'KR/ICN','DE/HHH');
insert into flight values('OZ-005','2022-11-10 22:00',24,'KR/ICN','CH/ZRH');
insert into flight values('7C-001','2022-09-05 09:00',02,'KR/ICN','KR/CJU');

--ticket 추가
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-001','SJ960',27,'51D','2022-09-10 14:45','KR/ICN','JP/HND');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-001','SJ777',27,'51C','2022-09-10 14:45','KR/ICN','JP/HND');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-002','SH987',07,'15A','2022-09-25 07:15','KR/ICN','JP/NRT');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-002','MW305',07,'34C','2022-09-25 07:15','KR/ICN','JP/NRT');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-003','HM458',41,'01A','2022-09-17 22:25','KR/CJU','JP/NRT');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-003','JH667',41,'26D','2022-09-17 22:25','KR/CJU','JP/NRT');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-004','HW123',15,'22B','2022-09-17 08:30','KR/ICN','US/LAX');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-004','MJ872',15,'22A','2022-09-17 08:30','KR/ICN','US/LAX');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-004','TY446',15,'22C','2022-09-17 08:30','KR/ICN','US/LAX');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-004','SZ996',15,'22D','2022-09-17 08:30','KR/ICN','US/LAX');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-005','YY411',31,'02A','2022-11-09 08:20','KR/ICN','DE/HHH');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-005','CH119',31,'19D','2022-11-09 08:20','KR/ICN','DE/HHH');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'7C-001','JY454',02,'30A','2022-09-05 09:00','KR/ICN','KR/CJU');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'7C-001','MW123',02,'30B','2022-09-05 09:00','KR/ICN','KR/CJU');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'OZ-001','JH852',22,'18D','2022-10-01 06:00','KR/ICN','US/JFK');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'OZ-001','PK557',22,'05C','2022-10-01 06:00','KR/ICN','US/JFK');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'OZ-002','SY004',23,'11D','2022-10-10 05:30','KR/ICN','GB/LHR');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'OZ-002','KI112',23,'16A','2022-10-10 05:30','KR/ICN','GB/LHR');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'OZ-003','KL447',26,'20E','2022-09-30 07:30','KR/ICN','TW/TPE');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'OZ-003','SG524',26,'29A','2022-09-30 07:30','KR/ICN','TW/TPE');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'OZ-004','SI119',20,'11D','2022-10-21 20:30','KR/ICN','IT/FCO');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'OZ-004','SM223',20,'11C','2022-10-21 20:30','KR/ICN','IT/FCO');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'OZ-005','HT605',24,'46D','2022-11-10 22:00','KR/ICN','CH/ZRH');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'OZ-005','GM653',24,'32A','2022-11-10 22:00','KR/ICN','CH/ZRH');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-001','YH732',27,'15E','2022-09-10 14:45','KR/ICN','JP/HND');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-002','SJ312',07,'29D','2022-09-25 07:15','KR/ICN','JP/NRT');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-003','BO650',41,'41A','2022-09-17 22:25','KR/CJU','JP/NRT');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-004','DH926',15,'05A','2022-09-17 08:30','KR/ICN','US/LAX');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-005','MY434',31,'02D','2022-11-09 08:20','KR/ICN','DE/HHH');
insert into ticket values('ticket-'||lpad(ticket_cnt.nextval,3, 0),'KAL-005','GA777',31,'11D','2022-11-09 08:20','KR/ICN','DE/HHH');

--컬럼명 변경 없이 전부 조회하는 select 문
select * from ticket
order by flight_num;

--Flight 테이블에 price 칼럼 추가.
alter table flight add(price number);

select * from flight;

update flight set price=90000 where flight_num='KAL-001';
update flight set price=85000 where flight_num='KAL-002';
update flight set price=50000 where flight_num='KAL-003';
update flight set price=2200000 where flight_num='KAL-004';
update flight set price=3600000 where flight_num='OZ-001';
update flight set price=2900000 where flight_num='OZ-002';
update flight set price=465000 where flight_num='OZ-003';
update flight set price=2700000 where flight_num='OZ-004';
update flight set price=2500000 where flight_num='KAL-005';
update flight set price=2100000 where flight_num='OZ-005';
update flight set price=80000 where flight_num='7C-001';

select * from flight;

commit;
--개인 사정으로 항공권 취소
delete ticket where ticket_num='ticket-020';
select * from ticket;
