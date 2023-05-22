/**
 * 
 */
window.onload = () => {
	let id = document.querySelector("input[name=id]")
	let pw = document.querySelector("input[name=pw]")
	let pw_check = document.querySelector("input[name=pw_check]")
	
	let name = document.querySelector("input[name=name]")
	let eMail = document.querySelector("input[name=eMail]")
	
	
	
//	let mysubmit = document.getElementById("submit") //id에 submit 주지마
	let reg_frm = document.querySelector("form[name=reg_frm]")
	let submitbtn = document.getElementById("submitbtn")
//	alert(reg_frm.name)
//	alert(reg_frm.method)
//	alert(reg_frm.action)
//	alert(reg_frm.innerHTML)
	//reg_frm.submit()
		
function infoConfirm() {
//	alert("!!!")
	//if(document.reg_frm.id.value.length == 0) 
	if(id.value.length==0){
		alert("아이디는 필 수 사항입니다!!!!!")
		//reg_frm.id.focus()
		id.focus()
		return
		}
	//
	
//	if(document.reg_frm.id.value.length < 4) 
	if(id.value.length < 4){
		alert("아아디는 4글자 이상이어야 하비니다.")
		id.focus()
		return
	}
	
//	if(document.reg_frm.pw.value.length == 0) 
	if(pw.value.length==0)
	{
		alert("비밀번호는 필 수 사항입니다.")
		pw.focus()
		return
	}
	
//	if(document.reg_frm.pw.value != document.reg_frm.pw_check.value) 
	if(pw.value != pw_check.value)
	{
		alert("비밀번호가 일치하지 않습니다.")
		pw.focus()
		return
	}
	
	//if(document.reg_frm.name.value.length == 0) 
	if(name.value.length==0)
	{
		alert("이름는 필 수 사항입니다.")
		name.focus()
		return
	}
	
//	if(document.reg_frm.id.value.length == 0) 
	if(id.value.length == 0) {
		alert("아아디는 필 수 사항입니다.")
		id.focus()
		return
	}
	
//	if(document.reg_frm.eMail.value.length == 0) 
	if(document.reg_frm.eMail.value.length == 0) {
		alert("메일은 필 수 사항입니다.")
		eMail.focus()
		return
	}
	
	//document.reg_frm.submit();
	reg_frm.submit()
	
	}
	
	submitbtn.onclick = infoConfirm
}
function updateInfoConfirm() {
	if(document.reg_frm.pw.value == "") {
		alert("패스워드를 입력하세요.");
		document.reg_frm.pw.focus();
		return;
	}
	
	
	if(document.reg_frm.pw.value != document.reg_frm.pw_check.value) {
		alert("패스워드가 일치하지 않습니다.");
		reg_frm.pw.focus();
		return;
	}
	
	if(document.reg_frm.eMail.value.length == 0) {
		alert("메일은 필 수 사항입니다.");
		reg_frm.eMail.focus();
		return;
	}
	
	document.reg_frm.submit();
	
}