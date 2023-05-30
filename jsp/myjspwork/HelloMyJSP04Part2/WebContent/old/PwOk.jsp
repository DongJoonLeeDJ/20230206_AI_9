<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%out.println((String)session.getAttribute("id")); %>
비밀번호 변경 페이지
<form action="PwOk" method="post">
	<input type="password" name="pw">
	<input type="submit" value="비밀번호변경">
</form>
</body>
</html>