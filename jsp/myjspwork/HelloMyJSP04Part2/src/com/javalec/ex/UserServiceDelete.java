package com.javalec.ex;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class UserServiceDelete implements UserService {

	@Override
	public ArrayList<MyUser> execute(HttpServletRequest request, HttpServletResponse response) {
		HttpSession hs = request.getSession();
		String id = (String)hs.getAttribute("id");
		Dao m = new Dao();
		m.DeleteUser(id);
		return null;
	}

}
