<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%-- param = request.getParameter --%>
아이디 : ${param.id }<br>
비밀번호 : <%out.println(request.getParameter("pw")); %><br>
비번 : ${param["pw"] }<br>

</body>
</html>