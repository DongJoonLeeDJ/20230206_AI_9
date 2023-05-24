<%@page import="java.util.Enumeration"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%Enumeration enu = session.getAttributeNames();
int i = 0;
while(enu.hasMoreElements()){
	//nextElement() 그 다음 엘리먼트 호출이 된다.
	String sName = enu.nextElement().toString();
	i++; 
}
out.print("남아있는 세션의 수 : "+i);
%>

</body>
</html>














