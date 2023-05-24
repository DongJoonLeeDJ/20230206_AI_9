<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

<form action="SolveFormEx">
	이름 : <input type="text" name="name"><br>
	나이 : <input type="text" name="age"><br>
	번호(학번) : <input type="text" name="number"><br>
	<input type="submit" value="학생(Get)">
</form>
<hr>
<form action="SolveFormEx" method="post">
	종류 : <input type="text" name="kinds"><br>
	이름 : <input type="text" name="name"><br>
	나이 : <input type="text" name="age"><br>
	번호 : <input type="text" name="number"><br>
	<input type="submit" value="동물(Post)">
</form>

</body>
</html>







