<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>책 등록</title>
</head>
<body>
	<h1>책 등록하기</h1>
	<form method="POST">
		<p>제목 : <input type="text" name="title"> </p>
		<p>카테고리 : <input type="text" name="category"> </p>
		<p>가격 : <input type="text" name="price"> </p>
		<p><input type="submit" value="등록"> </p>
	</form>
</body>
</html>