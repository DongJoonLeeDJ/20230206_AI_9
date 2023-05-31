<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>주문 상세 정보</title>
</head>
<body>
	<div class="d-grip gap-3">
		<%@ include file="../nav.jsp"%>
		<div class="container">
			<h1 class="text-center p-2">주문 상세 정보</h1>
			<h3 class="text-start p-2">주문ID : ${ data.orderid }</h3>
			<h3 class="text-start p-2">고객ID : ${ data.custid }</h3>
			<h3 class="text-start p-2">도서ID : ${ data.bookid }</h3>
			<h3 class="text-start p-2">도서ISBN : ${ data.bookisbn }</h3>
			<h3 class="text-start p-2">판매 가격 : ${ data.saleprice }</h3>
			<h3 class="text-start p-2">도서 이름 : ${ data.bookname }</h3>
			<h3 class="text-start p-2">고객 이름 : ${ data.name }</h3>
			<h3 class="text-start p-2">
					<fmt:parseDate value="${data.orderdate}" pattern="yyyy-MM-dd'T'HH:mm:ss" var="parsedDateTime" type="both"/>
					주문 시점 : <fmt:formatDate pattern="dd.MM.yyyy HH:mm:ss" value="${parsedDateTime}"/> </p>
			</h3>

			<div class="row">&nbsp;</div>
			<div class="text-center">
				<form method="POST" action="/orders/delete">
					<input type="hidden" name="orderid" value="${orderid}" /> 
					<input type="submit" value="삭제" class="btn btn-outline-primary" /> 
					<a class="btn btn-outline-primary" href="/orders/list">목록으로</a> 
					<a href="/orders/update?orderid=${orderid}" class="btn btn-outline-primary">수정</a>
				</form>
			</div>
		</div>
	</div>

	<%@ include file="../footer.jsp"%>
</body>
</html>