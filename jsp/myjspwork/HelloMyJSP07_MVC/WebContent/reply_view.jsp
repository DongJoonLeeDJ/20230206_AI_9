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
		<form action="reply.do" method="post">
			<input type="hidden" name="bId" 
			value="${reply_view.bId}">
			<input type="hidden" name="bGroup" 
			value="${reply_view.bGroup}">
			<input type="hidden" name="bStep" 
			value="${reply_view.bStep}">
			<input type="hidden" name="bIndent" 
			value="${reply_view.bIndent}">
			<tr>
				<th>번호</th>
				<td>${reply_view.bId}</td>
			</tr>
			<tr>
				<th>조회수</th>
				<td>${reply_view.bHit}</td>
			</tr>
			<tr>
				<th>글쓴이</th>
				<td><input type="text" name="bName" 
				value="${reply_view.bName}"></td>
			</tr>
			<tr>
				<th>제목</th>
				<td><input type="text" name="bTitle" 
				value="${reply_view.bTitle}">
				</td>
			</tr>
			
			<tr>
				<th>내용</th>
				<td>
					<textarea name="bContent" rows="10">${reply_view.bContent}</textarea>
				</td>
			</tr>
			<tr>
				<td colspan=2>
					<input type="submit" value="글쓰기(답글)">&nbsp;
					<a href="list.do">목록보기</a>
				</td>
				
			</tr>
		</form>
	</table>
</body>
</html>