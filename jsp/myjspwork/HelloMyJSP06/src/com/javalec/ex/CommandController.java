package com.javalec.ex;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.sun.org.apache.xerces.internal.impl.xpath.regex.REUtil;

/**
 * Servlet implementation class CommandController
 */
@WebServlet("*.do")
public class CommandController extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CommandController() {
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
	public void doAction(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		String uri = request.getRequestURI();
		String conPath = request.getContextPath();
		// /insert.do 인지 뭔지 보기 위함
		String command = uri.substring(conPath.length());
		
		MemberService mService = null;
		
		if(command.equals("/insert.do")) {
			System.out.println("insert!");
			mService = new MemberServiceInsert();
		} else if(command.equals("/update.do")) {
			System.out.println("update!");
			mService = new MemberServiceUpdate();
		} else if(command.equals("/delete.do")) {
			System.out.println("delete!");
			mService = new MemberServiceDelete();
		} else if(command.equals("/select.do")) {
			System.out.println("select!");
			mService = new MemberServiceSelect();
			
		} else {
			System.out.println("command="+command);
			//mService= new MemberServiceInsert();//임의의 값을 넣음
			mService = new MemberServiceLogin();
		}
		ArrayList<MemberDTO> dtos = 
		mService.execute(request, response);
		if(dtos!=null) {
			//null이 아닌 경우 즉 select로 읽어온 경우
			for(MemberDTO item : dtos) {
				System.out.println(item.getId());
				System.out.println(item.getPw());
				System.out.println(item.getName());
			}
			RequestDispatcher dispatcher =
					request.getRequestDispatcher("/list.jsp");
			dispatcher.forward(request, response);
			return;
		}
		//원위치로 돌아간다.
		response.sendRedirect("CommandController.html");
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
}
