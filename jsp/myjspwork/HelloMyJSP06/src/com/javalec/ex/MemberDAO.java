package com.javalec.ex;

import java.sql.*;
import java.util.ArrayList;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;

import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

public class MemberDAO {
	
	private Connection conn = null;
	private Statement stmt = null;
	private ResultSet rs = null;
	private PreparedStatement pstmt = null;
	
	private DataSource ds = null;
	
	private static MemberDAO instance = new MemberDAO();
	public static MemberDAO getInstance() {
		if(instance == null)
			instance = new MemberDAO();
		return instance;
	}
	public MemberDAO() {
		try {
			Context ctx = new InitialContext();
			ds = (DataSource)ctx.lookup
					("java:comp/env/jdbc/mysql");
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public int memberInsert(MemberDTO m) {
		int result = 0;
		conn = null;
		pstmt = null;
		try { //db�����ؼ� insert �����ϴ� �κ�
			conn = ds.getConnection();
			String sql = "insert into memberDTO values("
					+ "?,?,?)";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, m.getId());
			
			//�ܼ� ���� ���
			//pstmt.setString(2, m.getPw());
			
			//pw�� ��ȣȭ�ؼ� �����ϴ� ���
			PasswordEncoder p = new BCryptPasswordEncoder();
			m.setPw(p.encode(m.getPw()));
			pstmt.setString(2, m.getPw());
			pstmt.setString(3, m.getName());
			result = pstmt.executeUpdate(); //������� row�� �� ��ȯ
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				pstmt.close(); //insert�� �����ų� �߰��� ����Ǹ�
				conn.close(); //������ �� �����ش�.
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		return result;
	}
	public ArrayList<MemberDTO> AllmemberSelect() {
		ArrayList<MemberDTO> dtos = 
				new ArrayList<MemberDTO>();
		conn = null;
		stmt = null;
		try {
			conn = ds.getConnection();
			stmt = conn.createStatement();
			rs = stmt.executeQuery
					("select * from memberdto");
			while(rs.next()) {
				MemberDTO dto = new MemberDTO();
				dto.setId(rs.getString("id"));
				dto.setName(rs.getString("name"));
				dto.setPw(rs.getString("pw"));
				dtos.add(dto);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}finally {
			try {
				rs.close();
				stmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
				
		return dtos;
	}
	public int updateMember(MemberDTO dto) {
		int result = 0;
		conn = null;
		pstmt = null;
		try { //db�����ؼ� insert �����ϴ� �κ�
			conn = ds.getConnection();
			String sql = "update memberdto set pw=?, name=? "
					+ " where id=?";
			pstmt = conn.prepareStatement(sql);
			
			PasswordEncoder p = new BCryptPasswordEncoder();
			dto.setPw(p.encode(dto.getPw()));
			pstmt.setString(1, dto.getPw());
			pstmt.setString(2, dto.getName());
			pstmt.setString(3, dto.getId());
			
			result = pstmt.executeUpdate(); //������� row�� �� ��ȯ
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				pstmt.close(); //insert�� �����ų� �߰��� ����Ǹ�
				conn.close(); //������ �� �����ش�.
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		return result;
	}
	public int deleteMember(MemberDTO dto) {
		int result = 0;
		conn = null;
		pstmt = null;
		try { //db�����ؼ� insert �����ϴ� �κ�
			conn = ds.getConnection();
			String sql = "delete from memberdto where id=?";
			pstmt = conn.prepareStatement(sql);
			pstmt.setString(1, dto.getId());
			
			result = pstmt.executeUpdate(); //������� row�� �� ��ȯ
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				pstmt.close(); //insert�� �����ų� �߰��� ����Ǹ�
				conn.close(); //������ �� �����ش�.
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
		return result;
	}
	public String memberSelect(MemberDTO d) {
		String pw = null;
		conn = null;
		stmt = null;
		try {
			conn = ds.getConnection();
			String query = "select * from memberdto where id = ?";
			pstmt = conn.prepareStatement(query);
			pstmt.setString(1, d.getId());
			rs = pstmt.executeQuery();
			rs.next(); //1�ٸ� �о����
			pw = rs.getString("pw");
			System.out.println("pw = " + pw);
		} catch (Exception e) {
			e.printStackTrace();
		}finally {
			try {
				rs.close();
				pstmt.close();
				conn.close();
			} catch (Exception e2) {
				e2.printStackTrace();
			}
		}
			
		
		return pw; //null�� ���ϵǸ� �������� �ʴ� ���̵���
	}

}











