<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%String Name = (String)session.getAttribute("id");
out.println(Name);%>
<h1>로그인 성공</h1>
<a href="pwchange.jsp">비밀번호 수정</a>
<a href="DeleteOk">회원탈퇴</a>
</body>
</html>