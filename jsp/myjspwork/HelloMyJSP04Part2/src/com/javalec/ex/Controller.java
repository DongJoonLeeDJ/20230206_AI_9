package com.javalec.ex;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

/**
 * Servlet implementation class Controller
 */
@WebServlet("*.do")
public class Controller extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Controller() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doAction(request, response);
		// TODO Auto-generated method stub
		//response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doAction(request, response);
	}
	
	public void doAction(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		String uri = request.getRequestURI();
		String conPath = request.getContextPath();
		// /insert.do ���� ���� ���� ����
		String command = uri.substring(conPath.length());
		
		UserService uService = null;
		//HttpSession hs = request.getSession();
		//hs.setAttribute("logResult", null);
		
		if(command.equals("/join.do")) {
			System.out.println("ȸ������");
			uService = new UserServiceJoin();
		} else if(command.equals("/login.do")) {
			System.out.println("�α���");
			uService = new UserServiceLogIn();
		} else if(command.equals("/logout.do")) {
			System.out.println("�α׾ƿ�");
			uService = new UserServiceLogOut();
		} else if(command.equals("/pwchange.do")) {
			System.out.println("�������");
			uService = new UserServicePwChange();
		}else if(command.equals("/update.do")) {
			System.out.println("�̸��� ���� ����");
			uService = new UserServiceUpdate();
		} else if(command.equals("/delete.do")) {
			uService = new UserServiceDelete();
		}
		else {
			System.out.println("command="+command);
			//mService= new MemberServiceInsert();//������ ���� ����
		}
		ArrayList<MyUser> dtos = 
				uService.execute(request, response);
		if(dtos!=null) {
			if(dtos.size()==1) { //�α����� ���!
				if(dtos.get(0).getId()!=null) {
					if(dtos.get(0).getId().equals("admin")) {
						uService = new UserServiceAllMember();
						dtos = uService.execute(request, response);
						for(MyUser item : dtos) {
							System.out.println(item.getId());
							System.out.println(item.getName());
							System.out.println(item.getGender());
						}
						RequestDispatcher dispatcher =
								request.getRequestDispatcher("/list.jsp");
						dispatcher.forward(request, response);
						return;
					} else {
						response.sendRedirect("loginResult.jsp");
					}
				} else {
					response.sendRedirect("loginFail.jsp");	
				}
				return; //���⼭ �׳� ������.
			}
				
			
//			if(!((String)hs.getAttribute("logResult")).equals("ok")) {
//				response.sendRedirect("loginResult.jsp");
//			} else {
//				if(hs.getAttribute("logResult")!=null)
//					response.sendRedirect("loginFail.jsp");	
//			}
			//null�� �ƴ� ��� �� select�� �о�� ���
			
			
		}


		//����ġ�� ���ư���.
		response.sendRedirect("login.html");
		
	}

}
