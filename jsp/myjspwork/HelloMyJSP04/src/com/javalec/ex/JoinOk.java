package com.javalec.ex;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

/**
 * Servlet implementation class JoinOk
 */
@WebServlet({"/JoinOk", "/JoinOK"})
public class JoinOk extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JoinOk() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doAction(request,response);
	}
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doAction(request,response);
	}
	
	protected void doAction(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		String strId = request.getParameter("id");
		String strPw = request.getParameter("pw");
		PasswordEncoder p = new BCryptPasswordEncoder();
//		PasswordEncoder pp = new PasswordEncoder() {
//			
//			@Override
//			public boolean matches(CharSequence rawPassword, String encodedPassword) {
//				// TODO Auto-generated method stub
//				return true;
//			}
//			
//			@Override
//			public String encode(CharSequence rawPassword) {
//				// TODO Auto-generated method stub
//				return "1111";
//			}
//		};
		String cPassword = p.encode(strPw);
		System.out.println(p.matches(strPw, cPassword));
		Dao mydao = new Dao();
		int result = mydao.insertUser(strId, cPassword); //DB에 결과 들어감
		if(result==1) {
			//회원가입 성공
			response.sendRedirect("joinResult.jsp");
			
		} else {
			//회원가입 실패
			response.sendRedirect("join.html");
		}
	}

}












