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
<%-- JSTL 주의사항 --%>
<%--1. 끝에 /> 이렇게 마무리할 것(반드시) --%>
<%--2. 쌍따옴표 안에 "${}"이렇게 넣는 데, 
쌍따옴표 안에는 공백이 없어야 함!!! --%>
<%--3. 주석은 html용 말고 jsp용으로 써야 함 --%>

<%! String vatName; %>
<%vatName="안녕"; %>
<%=vatName %><hr>
${vatName }<hr> <%-- EL: 단일 변수 말고 객체 출력에 특화됨 --%>
<%--taglib prefix="c" : 접두사가 c이므로 앞에 c 들어감 --%>
<c:set var="vatName" value="aaa"/> <%--JSTL 변수 선언 --%>
<c:out value="${vatName }"/><hr><%--JSTL 변수 출력 --%>
<br>
<%--No JSTL(Exception) --%>
<%try {
	int a = 2;
	int b = 0;
	int c = a/b;
	
} catch(Exception e) {
	out.println(e.getMessage());
}
%>
<br>
<c:catch var="myerror">
<%=2/0 %>
</c:catch>
<c:out value="${myerror}"/>
<br>
<c:if test="${1+2==3}">
1+2=3이 맞아요.
</c:if>
<br>
<c:if test="${1+2!=3}">
이건 절대 안 찍힘 ㅡㅡ;
</c:if>
<c:forEach var="fEach" begin="1" end="10" step="3">
${fEach}<%--EL태그를 섞었고, 1 4 7 10이 출력됨 --%>
</c:forEach>
<c:choose>
	<c:when test="${10>100}">거짓1</c:when>
	<c:when test="${10==10}">참</c:when>
	<c:otherwise>이도저도 아님 ㅡㅡ</c:otherwise>
</c:choose>


</body>
</html>







