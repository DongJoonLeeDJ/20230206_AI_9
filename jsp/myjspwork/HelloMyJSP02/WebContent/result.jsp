<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
String str = request.getParameter("year");
int age = 2023-Integer.parseInt(str);
if(age>=20)
	response.sendRedirect("adult.jsp");
else
	response.sendRedirect("jammin.jsp");
%>
</body>
</html>