<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>    
<!DOCTYPE>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>

	<c:set var="vatName" value="varValue"/>
	vatName : <c:out value="${vatName}"/>
	<br />
	<c:remove var="vatName"/>
	vatName : <c:out value="${vatName}"/></h3>
	
	<hr />
	
	<c:catch var="error">
		<%=2/0%>
	</c:catch>
	<br />
	<c:out value="${error}"/>
	
	<hr />

	<c:if test="${1+2==3}">
		1 + 2 = 3
	</c:if>
	
	<c:if test="${1+2!=3}">
		1 + 2 != 3
	</c:if>
	
	<hr />

	<c:forEach var="fEach" begin="1" end="30" step="3">
		${fEach} <br>
	</c:forEach>
	<!-- 쌍따옴표 안에 공백 있으면 안 됨 ㅡㅡ -->
<c:choose>
<c:when test="${10>100}">10은 100보다 크다???</c:when>
<c:when test="${10==10}">10은 10이랑 같다!</c:when>
<c:otherwise> 이도저도 아닌 경우</c:otherwise>
</c:choose>


</body>
</html>