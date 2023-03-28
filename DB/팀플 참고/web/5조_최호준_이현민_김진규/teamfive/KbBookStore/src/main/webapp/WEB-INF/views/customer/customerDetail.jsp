<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>고객 상세 정보</title>
</head>
<body>
	<div class="d-grip gap-3">
		<%@ include file="../nav.jsp"%>
		<div class="container">
			<h1 class="text-center p-2">고객 상세 정보</h1>
			<h3 class="text-start p-2">아이디 : ${ data.custid }</h3>
			<h3 class="text-start p-2">이름 : ${ data.name }</h3>
			<h3 class="text-start p-2">주소 : ${ data.address }</h3>
			<h3 class="text-start p-2">연락처 : ${ data.phone }</h3>
			<h3 class="text-start p-2">
					<fmt:parseDate value="${data.insert_date}" pattern="yyyy-MM-dd'T'HH:mm:ss" var="parsedDateTime" type="both"/>
					고객 추가 시점 : <fmt:formatDate pattern="dd.MM.yyyy HH:mm:ss" value="${parsedDateTime}"/> </p>
			</h3>

			<div class="row">&nbsp;</div>
			<div class="text-center">
				<form method="POST" action="/customer/delete">
					<input type="hidden" name="custid" value="${custid}" /> 
					<input type="submit" value="삭제" class="btn btn-outline-primary" /> 
					<a class="btn btn-outline-primary" href="/customer/list">목록으로</a> 
					<a href="/customer/update?custid=${custid}" class="btn btn-outline-primary">수정</a>
				</form>
			</div>
			
			<div class="row">&nbsp;</div>
			<div class="text-center">
				<form action = "/orders/create">
					<input type="hidden" name="custid" value="${custid}" /> 
					<input type="submit" class="btn btn-outline-danger" value="해당 고객으로 주문 진행">
				</form>
			</div>
		</div>
	</div>

	<%@ include file="../footer.jsp"%>
</body>
</html>