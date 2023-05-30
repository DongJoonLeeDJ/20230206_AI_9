package com.javalec.ex;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class UserServiceJoin implements UserService {

	@Override
	public ArrayList<MyUser> execute(HttpServletRequest request, HttpServletResponse response) {
		// TODO Auto-generated method stub
		Dao d = new Dao();
		MyUser dto = new MyUser();
		dto.setId(request.getParameter("id"));
		dto.setPw(request.getParameter("pw"));
		dto.setName(request.getParameter("name"));
		dto.setGender(request.getParameter("gender"));
		d.myuserJoin(dto);
		return null;
	}

}
