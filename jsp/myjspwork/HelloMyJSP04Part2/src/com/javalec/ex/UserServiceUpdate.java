package com.javalec.ex;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class UserServiceUpdate implements UserService {

	@Override
	public ArrayList<MyUser> execute(HttpServletRequest request, HttpServletResponse response) {
		// TODO Auto-generated method stub
		HttpSession hs = request.getSession();
		String id = (String)hs.getAttribute("id");
		String name = request.getParameter("name");
		String gender = request.getParameter("gender");
		System.out.println("id,name,gender"+id+name+gender);
		Dao m = new Dao();
		m.updateUser(id,name,gender);
		return null;
	}

}
