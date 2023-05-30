package com.javalec.ex;

import java.util.ArrayList;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

public class MemberServiceLogin implements MemberService {

	@Override
	public ArrayList<MemberDTO> execute(HttpServletRequest request, HttpServletResponse response) {
		MemberDAO m = MemberDAO.getInstance();
		MemberDTO dto = new MemberDTO();
		dto.setId(request.getParameter("id"));
		dto.setPw(request.getParameter("pw"));
		String cpw = m.memberSelect(dto);
		PasswordEncoder p = new BCryptPasswordEncoder();
		System.out.println(p.matches(dto.getPw(), cpw));
		return null;
	}

}
