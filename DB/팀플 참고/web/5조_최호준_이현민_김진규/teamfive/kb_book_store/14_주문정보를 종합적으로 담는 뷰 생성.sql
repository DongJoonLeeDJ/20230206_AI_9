
create view total_order as 
select orderid, orders.custid, 
orders.bookid, bookisbn, saleprice, 
book.bookname, customer.name, orderdate 
from orders join book on orders.bookid=book.bookid 
join customer on orders.custid = customer.custid;