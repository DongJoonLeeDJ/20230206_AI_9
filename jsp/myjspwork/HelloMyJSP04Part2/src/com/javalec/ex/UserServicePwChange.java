package com.javalec.ex;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class UserServicePwChange implements UserService {

	@Override
	public ArrayList<MyUser> execute(HttpServletRequest request, HttpServletResponse response) {
		// TODO Auto-generated method stub
		HttpSession hs = request.getSession();
		String id = (String)hs.getAttribute("id");
		String pw = request.getParameter("pw");
		Dao m = new Dao();
		m.chagePw(id, pw);
		return null;
	}

}
