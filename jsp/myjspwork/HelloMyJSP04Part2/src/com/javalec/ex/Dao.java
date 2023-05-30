package com.javalec.ex;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

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
			//jar랑 연결
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
			
			PasswordEncoder p = new BCryptPasswordEncoder();
			pw = p.encode(pw);
			
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
			//result가 저장하는 값 : insert, update, delete했을 때 영향받는 행의 수
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
	
	
	public MyUser checkMember(String id) {
		
		conn = null;
		stmt = null;
		MyUser mu = new MyUser();
		try {
			conn = DriverManager.getConnection(url,uid,upw);
			//stmt = conn.createStatement();
			String query = "select * from myuser where id = ?";
			pstmt = conn.prepareStatement(query);
			pstmt.setString(1, id);
			rs = pstmt.executeQuery();
			rs.next(); //1줄만 읽어들임
			mu.setId(rs.getString("id"));
			mu.setPw(rs.getString("pw"));
			mu.setName(rs.getString("name"));
			mu.setGender(rs.getString("gender"));
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
		
		return mu;
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
	public int myuserJoin(MyUser dto) {
		//ArrayList<Employee> results = new ArrayList<Employee>();
		int result = 0;
		conn = null;
		stmt = null;
		try {
			conn = DriverManager.getConnection(url,uid,upw);
			stmt = conn.createStatement();
			PasswordEncoder p = new BCryptPasswordEncoder();
			dto.setPw(p.encode(dto.getPw()));
			String query = String.format
					("insert into myuser values('%s','%s','%s','%s')", dto.getId(),dto.getPw(),dto.getName(),dto.getGender());
			result = stmt.executeUpdate(query);
			//result가 저장하는 값 : insert, update, delete했을 때 영향받는 행의 수
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
	public ArrayList<MyUser> AllmemberSelect() {
		ArrayList<MyUser> results = new ArrayList<MyUser>();
		conn = null;
		stmt = null;
		try {
			conn = DriverManager.getConnection(url,uid,upw);
			stmt = conn.createStatement();
			rs = stmt.executeQuery("select * from myuser where id != 'admin'");
			while(rs.next()) {
				MyUser temp = new MyUser();
				temp.setId(rs.getString("id"));
				temp.setName(rs.getString("name"));
				temp.setGender(rs.getString("gender"));
				results.add(temp);
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
	public int updateUser(String id, String name, String gender) {
		
		int result = 0;
		conn = null;
		stmt = null;
		try {
			conn = DriverManager.getConnection(url,uid,upw);
			String query = "update myuser set name=?, gender=? where id=?";
			pstmt = conn.prepareStatement(query);
			
			
			pstmt.setString(1, name);
			pstmt.setString(2, gender);
			pstmt.setString(3, id);
			
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
