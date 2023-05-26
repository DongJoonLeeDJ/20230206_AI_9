<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <jsp:useBean id="memberDto1" 
    class="com.javalec.ex.Dto" scope="page"/>
    <jsp:setProperty name="memberDto1" property="name" value="홍길동"/>
    <jsp:setProperty name="memberDto1" property="id" value="hero430"/>
    <jsp:setProperty name="memberDto1" property="pw" value="1234"/>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%=100+100 %><br> <!-- java 코드 -->
${100+100 } <br><!-- EL -->
<%="안녕" %><br>
${"안녕" }<br>
이름 : <jsp:getProperty property="name" name="memberDto1"/><br>
아이디 : ${memberDto1.id }<br>
비밀번호 : ${memberDto1.pw }<br>

<form action="objectELOk.jsp" method="get">
아이디 : <input type="text" name="id"><br> 
비밀번호 : <input type="password" name="pw"><br>
<input type="submit" value="logintest">
</form>

</body>
</html>











