<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<table border=1 width=500>
	<form action="write.do" method="post">
		<tr>
			<th>이름</th>
			<td><input type="text" name="bName"></td>
		</tr>
		<tr>
			<th>제목</th>
			<td><input type="text" name="bTitle"></td>
		</tr>
		<tr>
			<th>내용</th>
			<td><textarea rows=10 name="bContent"></textarea>
			</td>
		</tr>
		<tr colspan=2>
			<input type="submit" value="글쓰기">&nbsp;
			<a href="list.do">목록보기</a>
		</tr>
		</form>
	</table>
</body>
</html>













