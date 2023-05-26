<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<a href="insert.do">insert</a><br>
<a href="delete.do">delete</a><br>
<a href="update.do">update</a><br>

<%--request.getContextPath() 의 정체 : 프로젝트 명이라고 보면 됨 --%>
<%=request.getContextPath() %><br>
<%-- java코드가 태그의 속성 안쪽에도 들어간다(쌍따옴표 안에도 들어감) --%>
<br><a href="http://localhost:8181
<%=request.getContextPath()%>/test.do">
test.do</a><br>
<a href="<%=request.getContextPath()%>
/test2.do">test2</a><br>
<a href="http://localhost:8181/HelloMyJSP05/aaa.do">
aaa</a>
</body>
</html>







