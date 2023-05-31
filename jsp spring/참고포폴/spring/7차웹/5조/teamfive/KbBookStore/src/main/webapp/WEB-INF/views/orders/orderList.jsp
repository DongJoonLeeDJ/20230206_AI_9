<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>주문 현황</title>

<style>
a {
	text-decoration: none
}
</style>
</head>
<body>
		<%@ include file="../nav.jsp"%>
	<div class="d-grip gap-3">
		<div class="container">
			<h1 class="text-center p-2">주문 현황</h1>

			<form>
				<div class="row pt-2 pb-2">
					<div class="col-6">
						<input class="form-control" type="search" placeholder="책 혹은 고객 이름"
							aria-label="Search" name="keyword" value="${keyword}">
					</div>
					<div class="col-4"></div>
					<div class="col-2 text-end">
						<button class="btn btn-outline-success" type="submit">검색</button>
					</div>
				</div>

			</form>

	<div class="row">&nbsp;</div>


<%--   <p>입력일 : <fmt:formatDate value="${data.insert_date}" pattern="yyyy.MM.dd HH:mm:ss" /></p> --%>

<%--
	<fmt:parseDate value="${data.insert_date}" pattern="yyy-MM-dd'T'HH:mm:ss" var="parsedDateTime" type="both"/>
	<p>입력일 : <fmt:formatDate pattern="dd.MM.yyy HH:mm:ss" value="${parsedDateTime}"/> </p>
 --%>

			<table class="table table-striped table-bordered" >
				<thead class="bg-secondary text-light">
					<tr>
						<td>주문 ID</td>
						<td>고객 ID</td>
						<td>고객 이름</td>
						<td>주문 책</td>
					</tr>
				</thead>
				<tbody>
					<c:forEach var="row" items="${data}">
							<tr>
								<td><a href="/orders/detail?orderid=${row.orderid}">${row.orderid}</a></td>
								<td><a href="/orders/detail?orderid=${row.orderid}">${row.custid}</a></td>
								<td><a href="/orders/detail?orderid=${row.orderid}">${row.name}</a></td>
								<td><a href="/orders/detail?orderid=${row.orderid}">${row.bookname}</a></td>
							</tr>
					</c:forEach>
				</tbody>
			</table>
			
	<div class="row">&nbsp;</div>
			<div class="text-center">
				<c:if test="${startPage!=1}">
					<a class="btn btn-outline-primary" href="/orders/list?nowPage=${startPage-1}&keyword=${keyword}">이전</a>
				</c:if>
				<c:forEach var="idx" begin="${startPage}" end="${endPage}">
					<c:choose>
						<c:when test="${nowPage!=idx}">
							<a class="btn btn-warning" href="/orders/list?nowPage=${idx}&keyword=${keyword}">
								${idx}</a>
						</c:when>
						<c:when test="${nowPage==idx}">
							<b class="btn btn-dark" >${idx}</b>
							<!-- 현재껀 진하게 표시 -->
						</c:when>
					</c:choose>
				</c:forEach>
				<c:if test="${endPage!=totalCount}">
					<a class="btn btn-outline-danger"  href="/orders/list?nowPage=${endPage+1}&keyword=${keyword}">다음</a>
				</c:if>
			</div>

			<p>
				<a  class="btn btn-outline-info" href="/orders/create">책 주문하기</a>
			</p>
		</div>
	</div>
	
		<%@ include file="../footer.jsp"%>
</body>
</html>