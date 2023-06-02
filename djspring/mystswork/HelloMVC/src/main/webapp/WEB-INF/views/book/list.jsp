<%@ page pageEncoding="UTF-8" contentType="text/html;charset=utf-8"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head>
<title>책 목록</title>
<style>
/* 밑줄 없앰 */
a{text-decoration: none}</style>
</head>
<body>
	<h1>책 목록</h1>
	<p>
	<form>
	<!-- placeholder 기본으로 쓰여있는 값 -->
		<input type="text" 
		placeholder="검색" 
		name="keyword" 
		value="${keyword}">
		<input type="submit" value="검색">
	</form>
	</p>
	
	
	<table>
		<thead>
			<tr>
				<td>제목</td>
				<td>카테고리</td>
				<td>가격</td>
			</tr>
		</thead>
		<tbody>
			<c:forEach var="row" items="${data}">
				<tr>
					<td><a href="/detail?bookId=${row.book_id}"> ${row.title}
					</a></td>
					<td>${row.category}</td>
					<td><fmt:formatNumber type="number" maxFractionDigits="3"
							value="${row.price}" /></td>
				</tr>
			</c:forEach>
		</tbody>
	</table>
	<c:if test="${startPage!=1}">
		<a href="/list?nowPage=${startPage-1}&keyword=${keyword}">&lt;</a>
	</c:if>
	<c:forEach var="idx" begin="${startPage}" end="${endPage}">
		<c:choose>
			<c:when test="${nowPage!=idx}">
				<a href="/list?nowPage=${idx}&keyword=${keyword}">
				${idx}&nbsp;</a>
			</c:when>
			<c:when test="${nowPage==idx}">
				<b>${idx}&nbsp;</b> <!-- 현재껀 진하게 표시 -->
			</c:when>
		</c:choose>
	</c:forEach>
	<c:if test="${endPage!=totalCount}">
		<a href="/list?nowPage=${endPage+1}&keyword=${keyword}">&gt;</a>
	</c:if>
	
	
	
	<p>
		<a href="/create">생성</a>
	</p>
</body>
</html>












