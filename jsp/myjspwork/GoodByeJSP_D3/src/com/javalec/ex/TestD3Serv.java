package com.javalec.ex;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class TestD3Serv
 */
@WebServlet("*.do")
public class TestD3Serv extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public TestD3Serv() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		Vo v1 = new Vo();
		Vo v2 = new Vo();
		Vo v3 = new Vo();
		Vo v4 = new Vo();
		Vo v5 = new Vo();
		v1.setName("a1");
		v1.setValue(11);
		v2.setName("b1");
		v2.setValue(21);
		v3.setName("c1");
		v3.setValue(1);
		v4.setName("d1");
		v4.setValue(31);
		v5.setName("e1");
		v5.setValue(51);
		ArrayList<Vo> vs = new ArrayList<Vo>();
		vs.add(v1);
		vs.add(v2);
		vs.add(v3);
		vs.add(v4);
		vs.add(v5);
		
		request.setAttribute("datas", vs);
		
		RequestDispatcher dispatcher =
				request.getRequestDispatcher("showD3Chart.jsp");
		dispatcher.forward(request, response);
		
		
		// TODO Auto-generated method stub
		//response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//doGet(request, response);
	}

}
