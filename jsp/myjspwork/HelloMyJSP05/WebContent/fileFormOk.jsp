<%@page import="java.util.Enumeration"%>
<%@page import="com.oreilly.servlet.multipart.DefaultFileRenamePolicy"%>
<%@page import="com.oreilly.servlet.MultipartRequest"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%String path = application.getRealPath("myupload");
int size = 1024*1024*10; //10M
String file="";
String oriFile="";
try{
	MultipartRequest multi = new MultipartRequest
			(request,path,size,"utf-8", 
					new DefaultFileRenamePolicy());
	Enumeration files = multi.getFileNames();
	String str = (String)files.nextElement(); //파일 1개 파일명 읽기
	file=multi.getFilesystemName(str); //str 정보를 이용해 파일명 적기
	oriFile=multi.getOriginalFileName(str);
	
}catch(Exception e){
	e.printStackTrace();
}
%>
</body>
</html>













