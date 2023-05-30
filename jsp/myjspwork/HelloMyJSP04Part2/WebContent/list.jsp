<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<table border=1>
	<tr>
		<th>아이디</th>
		<th>이름</th>
		<th>성별</th>
	</tr>
	<%--request.setAttribute("list", dtos) 
	list의 길이만큼 반복문이 수행됨--%>
	<%--dto는 이 안의 구성요소를 의미 --%>
	<c:forEach items="${list}" var="dto">
		<tr>
			<td>${dto.id}</td>
			<td>${dto.name}</td>
			<td>${dto.gender}</td>
		</tr>
	</c:forEach>
</table>

<a href="logout.do">로그아웃</a>
</body>
</html>