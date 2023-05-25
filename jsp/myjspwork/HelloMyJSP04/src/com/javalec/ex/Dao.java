package com.javalec.ex;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

public class Dao {
	private String url =
			"jdbc:mysql://localhost:3306/myjsp?"+
			"useUnicode=true&characterEncoding=utf8&"+
			"serverTimezone=UTC";
	private String uid = "root";
	private String upw = "1234";
	
	private Connection conn = null;
	private Statement stmt = null;
	private ResultSet rs = null;
	private PreparedStatement pstmt =null;
	
	
	public Dao() {
		try {
			//jar�� ����
			Class.forName("com.mysql.cj.jdbc.Driver");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public int chagePw(String id, String pw) {
		//ArrayList<Employee> results = new ArrayList<Employee>();
		int result = 0;
		conn = null;
		stmt = null;
		try {
			conn = DriverManager.getConnection(url,uid,upw);
			String query = "update myuser set pw=? where id=?";
			pstmt = conn.prepareStatement(query);
			pstmt.setString(1, pw);
			pstmt.setString(2, id);
			result = pstmt.executeUpdate();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				stmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		return result;
	}
	
	public int insertUser(String id, String pw) {
		//ArrayList<Employee> results = new ArrayList<Employee>();
		int result = 0;
		conn = null;
		stmt = null;
		try {
			conn = DriverManager.getConnection(url,uid,upw);
			stmt = conn.createStatement();
			String query = String.format
					("insert into myuser values('%s','%s')", id,pw);
			result = stmt.executeUpdate(query);
			//result�� �����ϴ� �� : insert, update, delete���� �� ����޴� ���� ��
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				//rs.close();
				stmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		return result;
	}
	
	public ArrayList<Employee> showMembers() {
		ArrayList<Employee> results = new ArrayList<Employee>();
		conn = null;
		stmt = null;
		try {
			conn = DriverManager.getConnection(url,uid,upw);
			stmt = conn.createStatement();
			rs = stmt.executeQuery("select * from djemployee");
			while(rs.next()) {
				Employee temp = new Employee();
				temp.setName(rs.getString("name"));
				temp.setSabeon(rs.getInt("sabeon"));
				temp.setBuseo(rs.getString("buseo"));
				results.add(temp);
				//String result = "";
				//result +=rs.getString("name")+",";
				//result +=rs.getString("sabeon")+",";
				//result +=rs.getString("buseo");
				//results.add(result);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				rs.close();
				stmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		return results;
	}
	
	public String checkMember(String id) {
		String pw = null;
		conn = null;
		stmt = null;
		try {
			conn = DriverManager.getConnection(url,uid,upw);
			//stmt = conn.createStatement();
			String query = "select * from myuser where id = ?";
			pstmt = conn.prepareStatement(query);
			pstmt.setString(1, id);
			rs = pstmt.executeQuery();
			rs.next(); //1�ٸ� �о����
			pw = rs.getString("pw");
			System.out.println("pw = " + pw);
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				rs.close();
				stmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		
		
		return pw; //null�� ���ϵǸ� �������� �ʴ� ���̵���
	}
	public int DeleteUser(String id) {

		int result = 0;
		conn = null;
		stmt = null;
		try {
			conn = DriverManager.getConnection(url,uid,upw);
			String query = "delete from myuser where id=?";
			pstmt = conn.prepareStatement(query);
			pstmt.setString(1, id);
			result = pstmt.executeUpdate();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				stmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		return result;
	
	}
	

}
