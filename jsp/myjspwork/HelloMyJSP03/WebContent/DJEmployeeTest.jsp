<%@page import="java.util.ArrayList"%>
<%@page import="com.javalec.ex.MyDAO"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<table border=1>
		<tr>
			<th>이름,사번,부서</th>
		</tr>
		<% ArrayList<String> results = new MyDAO().showMembers(); 
		for(String item : results) {%>
		<tr>
			<td><%=item %></td>
		</tr>
		<%} %>
	</table>
</body>
</html>