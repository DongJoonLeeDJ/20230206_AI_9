<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%! String name,pw; %>
<%
request.setCharacterEncoding("UTF-8");
name = request.getParameter("name");
pw = request.getParameter("pw");
%>
이름:<%=name %> <br>
비밀번호 : <%=pw %>

</body>
</html>