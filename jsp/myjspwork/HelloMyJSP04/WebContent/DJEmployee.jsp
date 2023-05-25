<%@page import="com.javalec.ex.Dao"%>
<%@page import="com.javalec.ex.Employee"%>
<%@page import="java.util.ArrayList"%>
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
			<th>이름</th>
			<th>사번</th>
			<th>부서</th>
		</tr>
		<%ArrayList<Employee> results = new Dao().showMembers(); 
		for(Employee item : results) {		%>
			<tr>
				<td><%=item.getName() %></td>
				<td><%=item.getSabeon() %></td>
				<td><%=item.getBuseo() %></td>
			</tr>
		<%} %>
	</table>
</body>
</html>








