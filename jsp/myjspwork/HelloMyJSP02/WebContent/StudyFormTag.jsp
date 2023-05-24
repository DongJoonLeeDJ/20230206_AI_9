<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<form action="FormEx" method="post">
		이름:<input type="text" name="name"><br>
		비밀번호:<input type="password" name="pw"><br>
	<input type="submit" value="이동">
	</form>
	<form action="FormEx" method="get">
		이름(get):<input type="text" name="name"><br>
		비밀번호():<input type="password" name="pw"><br>
	<input type="submit" value="이동">
	</form>
</body>
</html>