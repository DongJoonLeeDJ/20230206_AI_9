<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>주문 수정</title>
</head>
<body>
	<div class="d-grip gap-3">
		<%@ include file="../nav.jsp"%>
		<div class="container">
			<form method="post" id="updateOrdersForm">
				<h1 class="text-center p-2">도서 주문 수정</h1>
				<div class="row">&nbsp;</div>
				<div class="row">
					<div class="col-2"></div>
					<div class="col-2">
						<h2>주문 ID</h2>
					</div>
					<div class="col-4">
						<input style="text-align:left" class="input-group-text" name="orderid" value="${data.orderid }" readonly></input>
					</div>
					<div class="col-4"></div>
				</div>
				<div class="row">
					<div class="col-2"></div>
					<div class="col-2">
						<h2>고객 ID</h2>
					</div>
					<div class="col-4">
						<input class="form-control" placeHolder=" 고객 ID" name="custid" value="${data.custid }"></input>
					</div>
					<div class="col-4"></div>
				</div>
				<div class="row">
					<div class="col-2"></div>
					<div class="col-2">
						<h2>도서 ID</h2>
					</div>
					<div class="col-4">
						<input class="form-control" placeHolder="도서 ID" name="bookid" value="${data.bookid }"></input>
					</div>
					<div class="col-4"></div>
				</div>
				<div class="row">
					<div class="col-2"></div>
					<div class="col-2">
						<h2>판매가격</h2>
					</div>
					<div class="col-4">
						<input class="form-control" placeHolder="판매가격" name="saleprice" value="${data.saleprice }"></input>
					</div>
					<div class="col-4"></div>
				</div>
				<div class="row">&nbsp;</div>
				<div class="text-center">
					<input class="btn btn-primary" type="submit" value="주문 수정">
				</div>
			</form>
			<div class="row">&nbsp;</div>

		</div>
	</div>

	<%@ include file="../footer.jsp"%>
	<script>

		let updateOrdersForm = document.querySelector("#updateOrdersForm")
		let custid = document.querySelector('input[name=custid]')
		let bookid = document.querySelector('input[name=bookid]')
	
		function isEmpty(tag) {
			return tag.value==''
		}
		
		updateOrdersForm.addEventListener("submit", function (event) {
			
			//빈 값 있으면 안 됨
			// price는 반드시 숫자 들어가야 함
			let tags = [custid,bookid]
			for(let item of tags) {
				if(isEmpty(item)) {
					event.preventDefault()
					alert('빈 칸이 있습니다.')
					return
				}
			}
			
			
		})
	</script>
</body>
</html>