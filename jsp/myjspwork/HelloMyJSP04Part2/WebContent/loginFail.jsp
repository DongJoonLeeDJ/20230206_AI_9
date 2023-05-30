<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%!String Id; %>
<%Id = (String)session.getAttribute("id");
out.println(Id+"가 없거나 비밀번호가 틀렸습니다.");%>
<h1 style="color:red">로그인 실패</h1>
</body>
</html>