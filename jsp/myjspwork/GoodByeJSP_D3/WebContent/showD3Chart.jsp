<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
	<script src="https://d3js.org/d3.v7.min.js"></script>
	<style>
		svg {
		height:2400px;
		width:2400px}
		rect{
		fill:blue}
	</style>
</head>
<body>
<svg id="myg"></svg>
	<script><%--스크립트 안에 자바코드 삽입 가능--%>
		console.log('<%="안녕 java 코드"%>')
		let data = []
		<c:forEach items="${datas}" var="dto">
			data.push({
				name:"${dto.name}",
				value:"${dto.value}"
			})
		</c:forEach>
			
		d3.select('#myg')
		.selectAll('rect')
		.data(data)
		.enter()
		.append('rect')
		.attr('x', function(d,i){return i*75})
		.attr('y', function(d,i){return 200-data[i].value})
		.attr('height', (d,i)=>{return d.value})
		.attr('width','25')
		
		<%--글자 쓰고 싶으면 이렇게 따로 추가하든지 다른 코드들 참고하기--%>
		d3.select("#myg")
		.selectAll("text")
		.data(data)
		.enter()
		.append("text")
		.attr("x",function(d,i){return i*77})
		.attr("y",function(d,i){return 200-data[i].value} )
		.attr("height",(d,i)=>{return d.value})
		.attr("width", "25")
		.attr("font-family", "sans-serif")
		    .attr("font-size", "11px")
		    .attr("fill", "black")
		    .attr("text-anchor", "left")
		    .text((d)=>{return d.name});
    
		
	</script>
</body>
</html>







