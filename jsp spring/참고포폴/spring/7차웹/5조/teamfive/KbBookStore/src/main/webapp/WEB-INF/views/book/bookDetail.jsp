<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>책 상세 정보</title>
</head>
<body>
	<div class="d-grip gap-3">
		<%@ include file="../nav.jsp"%>
		<div class="container">
			<h1 class="text-center p-2">책 상세 정보</h1>
			<h3 class="text-start p-2">번호 : ${ bookid }</h3>
			<h3 class="text-start p-2">제목 : ${ data.bookname }</h3>
			<h3 class="text-start p-2">ISBN : ${ data.bookisbn }</h3>
			<h3 class="text-start p-2">출판사 : ${ data.publisher }</h3>
			<h3 class="text-start p-2">
				가격 :
				<fmt:formatNumber type="number" maxFractionDigits="3"
					value="${data.price}" />
			</h3>
			<h3 class="text-start p-2">책 이미지</h3>
			<img style="height: 500px" src="${data.bookImg}" />


			<div class="row">&nbsp;</div>
			<div class="text-center">
				<form method="POST" action="/book/delete">
					<input type="hidden" name="bookid" value="${bookid}" /> 
					<input type="submit" value="삭제" class="btn btn-outline-primary" /> 
					<a class="btn btn-outline-primary" href="/book/list">목록으로</a> 
					<a href="/book/update?bookid=${bookid}" class="btn btn-outline-primary">수정</a>
				</form>
			</div>
			
			<div class="row">&nbsp;</div>
			<div class="text-center">
				<form action = "/orders/create">
					<input type="hidden" name="bookid" value="${bookid}" /> 
					<input type="submit" class="btn btn-outline-danger" value="해당 도서 주문 진행">
				</form>
			</div>
		</div>
	</div>

	<%@ include file="../footer.jsp"%>
</body>
</html>