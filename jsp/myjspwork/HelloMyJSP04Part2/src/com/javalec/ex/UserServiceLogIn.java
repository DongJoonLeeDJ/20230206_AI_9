package com.javalec.ex;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

public class UserServiceLogIn implements UserService {

	@Override
	public ArrayList<MyUser> execute(HttpServletRequest request, HttpServletResponse response) {
		// TODO Auto-generated method stub
		//비밀번호 체크
		PasswordEncoder p = new BCryptPasswordEncoder();
		String id = request.getParameter("id");
		String pw = request.getParameter("pw");
		//아이디 여부 체크
		Dao dao = new Dao();
		MyUser mu = dao.checkMember(id);
		String dbPw = mu.getPw();
		boolean isCorrect = p.matches(pw, dbPw);
		HttpSession hs = request.getSession();
		hs.setAttribute("id", id);
		hs.setAttribute("name", mu.getName());
		hs.setAttribute("gender", mu.getGender());
		//System.out.println(hs);
		//System.out.println(hs.getAttribute("id"));
		//System.out.println(hs.getAttribute("logResult"));
		ArrayList<MyUser> dtos = new ArrayList<MyUser>();
		//MyUser mu = new MyUser();
		if(isCorrect) {
			System.out.println("로그인 성공");
		} else {
			System.out.println("로그인 실패");//로그인 시도한 id
			mu = new MyUser();
		}
		dtos.add(mu);
		return dtos;
	}

}
