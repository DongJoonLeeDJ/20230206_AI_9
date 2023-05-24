<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
Cookie[] cookies = request.getCookies();
for(int i = 0; i<cookies.length;i++) {
	String id = cookies[i].getValue();
	if(id.equals("admin")){
		out.println("안녕하세요 운영자님!");
	}
}
%>
</body>
</html>









