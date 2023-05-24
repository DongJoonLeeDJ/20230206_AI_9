<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%Class.forName("com.mysql.cj.jdbc.Driver");
Connection conn = null;
Statement stmt = null;
ResultSet rs = null;
try{
	String jdbcDriver = 
			"jdbc:mysql://localhost:3306/myjsp?"+
			"useUnicode=true&characterEncoding=utf8&"+
			"serverTimezone=UTC";
	String dbUser = "root";
	String dbPass = "1234";
	String query = "select * from student";
	//DB접근 및 연결
	conn = DriverManager.getConnection(jdbcDriver,dbUser,dbPass);
	stmt = conn.createStatement();
	rs=stmt.executeQuery(query); //select문 실행
	while(rs.next()){
		%>
		<tr>
			<td><%=rs.getString("beonho") %></td>
			<td><%=rs.getString("name") %></td>
		</tr>
		<br>
		
		<% 
	}
} catch(Exception e) {
	e.printStackTrace();
} finally{
	rs.close();
	stmt.close();
	conn.close();
}

%>
</body>
</html>