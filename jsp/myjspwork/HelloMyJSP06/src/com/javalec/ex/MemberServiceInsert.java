package com.javalec.ex;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class MemberServiceInsert implements MemberService {

	@Override
	public ArrayList<MemberDTO> execute(HttpServletRequest request, HttpServletResponse response) {
		
		//미리 만들어진 인스턴스를 가져온다.
		MemberDAO m = MemberDAO.getInstance();
		
		MemberDTO dto = new MemberDTO();
		dto.setId(request.getParameter("id"));
		dto.setPw(request.getParameter("pw"));
		dto.setName(request.getParameter("name"));
		m.memberInsert(dto);
		
		
		return null;
	}

}
