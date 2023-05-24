<%@page import="com.javalec.ex.Student"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!-- Bean : 자바 객체를 jsp 태그 형태로 사용함. 
getter setter를 좀 더 태그에 가까운 문법으로 쓸 수 있다. -->
<!-- id="student1" 변수명이 student1이다. -->
<jsp:useBean id="student1" 
class="com.javalec.ex.Student" scope="page"/>
<jsp:useBean id="student2" 
class="com.javalec.ex.Student" scope="page">
</jsp:useBean>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<jsp:setProperty 
property="name" name="student1" value="최은지"/>
<jsp:setProperty property="age" name="student1" value="35"/>
<jsp:setProperty 
property="name" name="student2" value="서정빈"/>
<jsp:setProperty property="age" name="student2" value="30"/>

<jsp:getProperty property="name" name="student1"/><br>
<jsp:getProperty property="age" name="student1"/><br>
<jsp:getProperty property="name" name="student2"/><br>
<jsp:getProperty property="age" name="student2"/><br>

<!-- 빈 태그 없는 버전 -->
<%--순수 java로만 해보자 --%>
<%Student student3 = new Student();
Student student4 = new Student();
student3.setName("정홍근");
student3.setAge(59);
student4.setName("박세진");
student4.setAge(62);
out.println("이름:"+student3.getName());
out.println("나이:"+student3.getAge()+"<br>");
out.println("이름:"+student4.getName());
out.println("나이:"+student4.getAge());%>
</body>
</html>







