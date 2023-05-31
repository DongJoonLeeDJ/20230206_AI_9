package com.javalec.ex.controller;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.javalec.ex.command.BCommand;
import com.javalec.ex.command.BContentCommand;
import com.javalec.ex.command.BDeleteCommand;
import com.javalec.ex.command.BListCommand;
import com.javalec.ex.command.BModifyCommand;
import com.javalec.ex.command.BReplyCommand;
import com.javalec.ex.command.BReplyViewCommand;
import com.javalec.ex.command.BWriteCommand;

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
		// TODO Auto-generated method stub
		//response.getWriter().append("Served at: ").append(request.getContextPath());
		doAction(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doAction(request, response);
	}
	public void doAction(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//doAction(request, response); //재귀됨;;;
		request.setCharacterEncoding("utf-8");
		String viewPage = null; //어떤 페이지로 갈 건지 지정
		BCommand command = null; //다형성 이용할 것
		
		//주소 가져오는 것
		String uri = request.getRequestURI();
		String conPath = request.getContextPath();
		String com = uri.substring(conPath.length());
		
		if(com.equals("/list.do")) {
			viewPage = "/list.jsp";
			command = new BListCommand();
			command.execute(request, response);
		} else if(com.equals("/content_view.do")) {
			viewPage = "/content_view.jsp";
			command = new BContentCommand();
			command.execute(request, response);
		} else if(com.equals("/modify.do")) {
			viewPage = "/list.do";
			command = new BModifyCommand();
			command.execute(request, response);
		} else if(com.equals("/write_view.do")) {
			viewPage = "/write_view.jsp";
		} else if(com.equals("/write.do")) {
			viewPage = "/list.do";
			command = new BWriteCommand();
			command.execute(request, response);
		} else if(com.equals("/delete.do")) {
			viewPage = "/list.do";
			command = new BDeleteCommand();
			command.execute(request, response);
		}else if(com.equals("/reply_view.do")) {
			viewPage = "/reply_view.jsp";
			command = new BReplyViewCommand();
			command.execute(request, response);
		}else if(com.equals("/reply.do")) {
			viewPage = "/list.do";
			command = new BReplyCommand();
			command.execute(request, response);
		}
		
		if(viewPage.equals("/list.do")) {
			response.sendRedirect(conPath+viewPage);
		} else {
			RequestDispatcher dispatcher = 
					request.getRequestDispatcher(viewPage);
			dispatcher.forward(request, response);
		}
	}

}








