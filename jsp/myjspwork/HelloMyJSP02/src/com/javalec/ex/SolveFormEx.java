package com.javalec.ex;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class SolveFormEx
 */
@WebServlet("/SolveFormEx")
public class SolveFormEx extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public SolveFormEx() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//response.getWriter().append("Served at: ").append(request.getContextPath());
		request.setCharacterEncoding("UTF-8");//�ѱ۱�������
		String name = request.getParameter("name");
		String age = request.getParameter("age");
		String number = request.getParameter("number");
		Student s = new Student
				(name,Integer.parseInt(age),number);
		System.out.println(s.toString());
		System.out.println("�̸�"+name);
		System.out.println("����"+age);
		System.out.println("��ȣ"+number);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//doGet(request, response);request.setCharacterEncoding("UTF-8");//�ѱ۱�������
		request.setCharacterEncoding("UTF-8");//�ѱ۱�������
		String kinds = request.getParameter("kinds");
		String name = request.getParameter("name");
		String age = request.getParameter("age");
		String number = request.getParameter("number");
		Animal s = new Animal
				(kinds,name,Integer.parseInt(age),number);
		System.out.println(s.toString());
		System.out.println("����"+kinds);
		System.out.println("�̸�"+name);
		System.out.println("����"+age);
		System.out.println("��ȣ"+number);
	}

}
