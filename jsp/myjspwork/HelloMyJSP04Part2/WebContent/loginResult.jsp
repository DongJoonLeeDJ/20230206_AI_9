<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%! String Name, Gender;%>
<%Name = (String)session.getAttribute("id");
Gender = (String)session.getAttribute("gender");
if(Name==null) {
	response.sendRedirect("login.html");
}
out.println(Name);%>
<h1>로그인 성공</h1>

<form action="pwchange.do" method="post">
	<input type="password" name="pw">
	<input type="submit" value="비밀번호변경">
</form>
<br>
<form action="update.do" method="post">
	<input type="text" name="id" value=<%=Name %> readonly style="color:gray; background:black">
	<input type="text" name="name">
	<label>성별</label>
	<%if(Gender.equals("man")) { %>
		<input type="radio" id ="man" name="gender" value="man" checked>
		<label for="man">남자</label>
		<input type="radio" id="woman" name="gender" value="woman">
	<label for="woman">여자</label>
	<%} else { %>
		<input type="radio" id ="man" name="gender" value="man" >
		<label for="man">남자</label>
		<input type="radio" id="woman" name="gender" value="woman" checked>
	<label for="woman">여자</label>
	<% } %>
	<input type="submit" value="회원 정보 변경">
</form>
<a href="delete.do">회원탈퇴</a>
<a href="logout.do">로그아웃</a>
</body>
</html>