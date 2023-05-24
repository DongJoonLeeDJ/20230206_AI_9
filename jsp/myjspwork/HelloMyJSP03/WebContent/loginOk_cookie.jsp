<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%! String id,pw; %>
	<% id=request.getParameter("id"); 
	   pw=request.getParameter("pw");
	   if(id.equals("admin") && pw.equals("1234")) {
		   //키 : id, 값 : id변수에 있는 값
		   Cookie cookie = new Cookie("id", id);
	   	   cookie.setMaxAge(60); //쿠기 보관 시간 1분
	   	   response.addCookie(cookie);
	   	   response.sendRedirect("welcome_cookie.jsp");
	   } else {
		   response.sendRedirect("login_cookie.html");
	   }
	   %>
</body>
</html>






