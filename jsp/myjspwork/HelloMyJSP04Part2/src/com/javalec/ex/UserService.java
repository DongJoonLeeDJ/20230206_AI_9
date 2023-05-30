package com.javalec.ex;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public interface UserService {

	public ArrayList<MyUser> execute 
	(HttpServletRequest request, 
			HttpServletResponse response);
}
