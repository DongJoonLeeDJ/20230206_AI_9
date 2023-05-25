<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<!-- 생략시 get 방식 -->
<form action="HiWorld" method="get">
	<input type="submit" value="전송(안녕세상)">
</form>
<form action="Bye" method="post">
	<input type="submit" value="전송(잘가)">
	</form>
	<% System.out.println("ㅎㅇㅎㅇ"); //그냥 자바코드, 이건 소스보기에서 안 보임 %>
<!-- 일반 HTML용 주석 -->
<%-- JSP용 주석(JSP = Java Server Page) --%>
<%-- Server단에만 써지므로 클라이언트 단에는 이 주석은 안 보임 --%>
</body>
</html>