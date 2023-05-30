package com.javalec.ex;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class MemberServiceSelect implements MemberService {

	@Override
	public ArrayList<MemberDTO> execute(HttpServletRequest request, HttpServletResponse response) {
		MemberDAO m = MemberDAO.getInstance();
		ArrayList<MemberDTO> dtos = m.AllmemberSelect();
		//System.out.println(dtos.size());
		request.setAttribute("list", dtos);//°´Ã¼¸¦ º¸³¿
		
		
		return dtos;
	}

}
