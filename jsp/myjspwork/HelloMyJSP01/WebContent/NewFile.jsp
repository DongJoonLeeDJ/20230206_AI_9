<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

<h1>안녕하세요.</h1>
<% System.out.println("Hello"); %>
<%! int sum = 0; %>
<%for(int i = 0; i<=10; i++)
	sum+=i;%>
<h1><%=sum %></h1>
</body>
</html>