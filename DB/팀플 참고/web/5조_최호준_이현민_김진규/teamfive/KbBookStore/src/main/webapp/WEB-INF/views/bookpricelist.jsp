<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<script src="https://d3js.org/d3.v3.min.js"></script>
<style>
#myg {
	height: 500px;
	width: 900px;
}

rect{
	fill: green
}
</style>
</head>
<body>
		<%@ include file="nav.jsp"%>
	<div class="row">&nbsp;</div>
		<div class="container" style="text-align:center">
		
		<svg id="myg"></svg>
		<h1 id="total">총 도서 수량 : </h1>
		</div>
		
	<script>
	let data = []
	let sum = 0
	<c:forEach items="${data}" var="item">
	data.push({
		name: "${item.priceRange}",
		value : "${item.countPrice}"}
	)
	sum += Number("${item.countPrice}")
</c:forEach>

    
    let total = document.querySelector("#total")
    total.innerText = "총 도서 수량 : " + sum

 d3.select("#myg")
.selectAll("rect")
.data(data)
.enter()
.append("rect")
.attr("x",function(d,i){return i*120})
.attr("y",function(d,i){return 450-data[i].value} )
.attr("height",(d,i)=>{return d.value})
.attr("width", "25")
.attr("value", (d)=> {return d.value})
.attr("color")

d3.select("#myg")
.selectAll("text")
.data(data)
.enter()
.append("text")
.attr("x",function(d,i){return -35+(i*120)})
.attr("y",function(d,i){return 470-data[0].value} )
.attr("font-family", "D2Coding")
    .attr("font-size", "15px")
    .attr("fill", "black")
    .text((d)=>{return d.name});
	
for(let i = 0; i<data.length; i++) {
		
	let item = data[i]
	
	if(i==0) {

		d3.select('#myg')
		.append('text')
		.attr('x', 10)
		.attr('y', 440-data[0].value)
		.attr("font-family", "D2Coding")
	    .attr("font-size", "15px")
	    .attr("fill", "black")
	    .text(item.value)
	} else {

		if(data[i].value<300) {

			d3.select('#myg')
			.append('text')
			.attr('x', (i*120))
			.attr('y', 445-data[i].value)
			.attr("font-family", "D2Coding")
		    .attr("font-size", "15px")
		    .attr("fill", "black")
		    .text(item.value)
		}  else {d3.select('#myg')
			.append('text')
			.attr('x', (i*120))
			.attr('y', 445-data[i].value)
			.attr("font-family", "D2Coding")
		    .attr("font-size", "15px")
		    .attr("fill", "black")
		    .text(item.value)
		}
	}
	
}

    </script>
		<%@ include file="footer.jsp" %>
</body>
</html>