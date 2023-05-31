<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>책 목록</title>

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
			<h1 class="text-center p-2">책 목록</h1>

			<form>
				<div class="row pt-2 pb-2">
					<div class="col-6">
						<input class="form-control" type="search" placeholder="Search"
							aria-label="Search" name="keyword" value="${keyword}">
					</div>
					<div class="col-4"></div>
					<div class="col-2 text-end">
						<button class="btn btn-outline-success" type="submit">검색</button>
					</div>
				</div>

			</form>

	<div class="row">&nbsp;</div>


			<%--<form>
			<input type="text" placeholder="검색" name="keyword" value="${keyword}">
			<input type="submit" value="검색">
		</form>
 --%>

			<table class="table table-striped table-bordered" >
				<thead class="bg-secondary text-light">
					<tr>
						<td>책 번호</td>
						<td>책 제목</td>
						<td>책 ISBN</td>
						<td>책 출판사</td>
						<td>책 가격</td>
					</tr>
				</thead>
				<tbody>
					<c:forEach var="row" items="${data}">
						<tr>
							<td>${row.bookid}</td>
							<td><a href="/book/detail?bookid=${row.bookid}">${row.bookname}</a></td>
							<td>${row.bookisbn}</td>
							<td>${row.publisher}</td>
							<td><fmt:formatNumber type="number" maxFractionDigits="3"
									value="${row.price}" /></td>
						</tr>
					</c:forEach>
				</tbody>
			</table>
			
	<div class="row">&nbsp;</div>
			<div class="text-center">
				<c:if test="${startPage!=1}">
					<a class="btn btn-outline-primary" href="/book/list?nowPage=${startPage-1}&keyword=${keyword}">이전</a>
				</c:if>
				<c:forEach var="idx" begin="${startPage}" end="${endPage}">
					<c:choose>
						<c:when test="${nowPage!=idx}">
							<a class="btn btn-warning" href="/book/list?nowPage=${idx}&keyword=${keyword}">
								${idx}</a>
						</c:when>
						<c:when test="${nowPage==idx}">
							<b class="btn btn-dark" >${idx}</b>
							<!-- 현재껀 진하게 표시 -->
						</c:when>
					</c:choose>
				</c:forEach>
				<c:if test="${endPage!=totalCount}">
					<a class="btn btn-outline-danger"  href="/book/list?nowPage=${endPage+1}&keyword=${keyword}">다음</a>
				</c:if>
			</div>


			<p>
				<a  class="btn btn-outline-info" href="/book/create">책 추가</a>
			</p>
			<%-- 	<p>
	 <a href="javascript:void(window.open('/detail?bookId=1', 'test','width=#, height=#'))">새창</a> 
	
	</p>
	--%>
		</div>
	</div>
	
		<%@ include file="../footer.jsp"%>
</body>
</html>