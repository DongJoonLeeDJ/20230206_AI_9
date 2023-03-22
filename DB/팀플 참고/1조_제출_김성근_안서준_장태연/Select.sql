--각종 Select 문 입력 SQL.

--모든 승객 다 조회하는 select 문 
select ticket.flight_num as 탑승편, passenger.name as 승객명, dated as 출발시간, gate as "탑승 게이트",
seat as 좌석번호, depart_nation.name as 출발지 ,arrive_nation.name as 목적지
from ticket
join passenger on ticket.name=passenger.passport
join depart_nation on ticket.depart_nation=depart_nation.code
join arrive_nation on ticket.arrive_nation=arrive_nation.code;

--특정 비행기만 타는 승객들 조회하는 select 문 
select ticket.flight_num as 탑승편, passenger.name as 승객명, ticket.dated as 출발시간, gate as "탑승 게이트",
seat as 좌석번호, depart_nation.name as 출발지 ,arrive_nation.name as 목적지
from ticket
join passenger on ticket.name=passenger.passport
join depart_nation on ticket.depart_nation=depart_nation.code
join arrive_nation on ticket.arrive_nation=arrive_nation.code
where ticket.flight_num='7C-001';

--각 항공편 마다 나이가 제일 많은 승객 찾기.
select ticket.name passname, passenger.birth age, flight.flight_num flightname
from ticket
join passenger on ticket.name=passenger.passport
join flight on ticket.flight_num=flight.flight_num;


create view max_age as
select passenger.name passname, passenger.birth age, flight.flight_num flightname
from ticket
join passenger on ticket.name=passenger.passport
join flight on ticket.flight_num=flight.flight_num;

select * from max_age;

select flightname, max(age)
from max_age
group by flightname;

create view print_name as
select flightname, max(age) maxage
from max_age
group by flightname;

select * from print_name;
    
select passname, age, print_name.flightname
from print_name
join max_age
on print_name.flightname = max_age.flightname
and print_name.maxage = max_age.age
order by age;

--항공편별 총 운임료, 탑승객 수.(총 운임료가 100만 이상인 항공편만 출력)
select flight.flight_num as 탑승편명, sum(flight.price) as "총 운임료", count(*)||'명' as "인원 수"
from ticket
join flight on ticket.flight_num=flight.flight_num
group by flight.flight_num
having sum(flight.price) > 1000000;