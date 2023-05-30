package com.javalec.ex;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class UserServiceAllMember implements UserService {

	@Override
	public ArrayList<MyUser> execute(HttpServletRequest request, HttpServletResponse response) {
		Dao m = new Dao();
		ArrayList<MyUser> dtos = m.AllmemberSelect();
		//System.out.println(dtos.size());
		request.setAttribute("list", dtos);//°´Ã¼¸¦ º¸³¿
		
		// TODO Auto-generated method stub
		return dtos;
	}

}
