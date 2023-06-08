<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>책 목록</title>
	<style>
		/*a태그에 밑줄 없애기*/
		a{text-decoration: none}
	</style>
</head>
<body>
<h1>책 리스트</h1>

<p>
<form>
<input type="text" placeholder="검색" name="keyword" value="${keyword}">
<input type="submit" value="검색">
</form>
</p>


<table border=1>
	<thead>
		<th>제목</th>
		<th>카테고리</th>
		<th>가격</th>
	</thead>
	<tbody>
		<c:forEach	var="row" items="${data}">
			<tr>
				<td><a href="/detail?bookId=${row.book_id}">${row.title}</a></td>
				<td>${row.category}</td>
				<td><fmt:formatNumber type="number" maxFractionDigits="3" value="${row.price}"/></td>
			</tr>
		
		</c:forEach>
	</tbody>
</table>
<c:if test="${startPage!=1}">
	<a href="/list?nowPage=${startPage-1}&keyword=${keyword}">&lt;</a>
</c:if>
<c:forEach var="idx" begin="${startPage}" end="${endPage}">
	<c:choose>
		<c:when test="${nowPage!=idx }">
			<a href="/list?nowPage=${idx}&keyword=${keyword}">${idx}&nbsp;</a>
		</c:when>
		<c:when test="${nowPage==idx}">
			<b>${idx}&nbsp;</b>
		</c:when>
	</c:choose>
</c:forEach>
<c:if test="${endPage!=totalCount}">
	<a href="/list?nowPage=${endPage+1}&keyword=${keyword}">&gt;</a>
</c:if>


<p><a href="/create">책 추가</a></p>
</body>
</html>











