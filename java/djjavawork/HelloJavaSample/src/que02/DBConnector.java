package que02;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

import que01.Major;
import que01.Student;

public class DBConnector {
	
	
	static void selectQuery(String tableName, int PK, boolean isJoin) {

		Connection con = null;
		try {
			Class.forName("org.sqlite.JDBC");//jar ���Ͽ� ����ִ� Ŭ������ ã��
			String dbFile = "D:\\shareFolder\\java\\HelloDB.db";
			con = DriverManager.getConnection("jdbc:sqlite:"+dbFile);
			
			Statement stat = con.createStatement();
			ResultSet rs = null;

			if(isJoin)
			{
				rs = stat.executeQuery("select Student.code, Student.name, Major.name from Student join Major on Student.majcode=Major.code");
			}
			else
			{

				if(PK!=-1)
				{
					//System.out.println("select * from "+tableName+" where code="+PK);
					//rs = stat.executeQuery("select * from " + tableName);
					rs = stat.executeQuery("select * from "+tableName+" where code="+PK);	
				}
				else
					rs = stat.executeQuery("select * from " + tableName);
			}
			if(isJoin)
			{
				while(rs.next()) {
					System.out.print(rs.getInt(1)+"\t");//�÷��� ���ų� �ε��� ���� ��, �ε����� 1���� ������
					System.out.print(rs.getString(2)+"\t"); //���ڿ� ���� ����̶�� getString�ؾ� �Ѵ�.
					System.out.print(rs.getString(3));
					System.out.println();
				}	
			}
			else
			{
				while(rs.next()) {
					System.out.print(rs.getInt(1)+"\t");//�÷��� ���ų� �ε��� ���� ��, �ε����� 1���� ������
					System.out.print(rs.getString(2)+"\t"); //���ڿ� ���� ����̶�� getString�ؾ� �Ѵ�.
					if(tableName.equals("Student"))
						System.out.print(rs.getInt(3));
					System.out.println();
				}
			}
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		} finally { //DB �۾� �� ������ ���� DB ������ ��������� ��
			//finally : ��ħ��
			//catch���� return; �̷��� ȣ���ϸ鼭
			//�Լ� ��ü�� ������
			//finally�� �ִ� �� ������ �����ϰ� ����
			//�׷��� DB ���� ������ �� ���� ����
			try {
				con.close();
			} catch (Exception e2) {
				// TODO: handle exception
				e2.printStackTrace();
			}
		}
	}
	static void doQuery(String Query, Student s, Major m) {

		Connection con = null;
		try {
			Class.forName("org.sqlite.JDBC");//jar ���Ͽ� ����ִ� Ŭ������ ã��
			String dbFile = "D:\\shareFolder\\java\\HelloDB.db";
			con = DriverManager.getConnection("jdbc:sqlite:"+dbFile);
			
			Statement stat = con.createStatement();
			String sql = null;
			switch (Query) {
			case "insert":
				if(s!=null)
				{
					sql = String.format
							("insert into Student values(%d, '%s', %d)",
							s.getCode(),s.getName(),s.getMajCode());
				}
				else if(m!=null)
				{

					sql = String.format
							("insert into Major values(%d, '%s')",
							m.getCode(),m.getName());
				}
				else
				{
					System.out.println("�߸��� �Է��Դϴ�.(insert)");
					return;
				}
				break;
			case "update":
				if(s!=null)
				{
					sql = String.format
							("update Student set name='%s', majcode=%d where code=%d",
							s.getName(),s.getMajCode(),s.getCode());
				}
				else if(m!=null)
				{

					sql = String.format
							("update Major set name='%s' where code=%d",
									m.getName(), m.getCode());
				}
				else
				{
					System.out.println("�߸��� �Է��Դϴ�.(update)");
					return;
				}
				
				break;
			case "delete":
				if(s!=null)
				{
					sql = String.format
							("delete from Student where code=%d", s.getCode());
				}
				else if(m!=null)
				{

					sql = String.format
							("delete from Major where code=%d", m.getCode());
				}
				else
				{
					System.out.println("�߸��� �Է��Դϴ�.(delete)");
					return;
				}
				
				break;
			default:
				break;
			}
			
			
			//������ ����
			System.out.println(sql);
			stat.executeUpdate("PRAGMA foreign_keys = ON;");
			stat.execute(sql);//insert, update, delete���� ���� ����
			//executeQuery�� select���� �ַ� ����
			//delete���̶� update���� �̰Ŷ� �Ȱ��� ���� �ȴ�.
			
			
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		} finally { //DB �۾� �� ������ ���� DB ������ ��������� ��
			//finally : ��ħ��
			//catch���� return; �̷��� ȣ���ϸ鼭
			//�Լ� ��ü�� ������
			//finally�� �ִ� �� ������ �����ϰ� ����
			//�׷��� DB ���� ������ �� ���� ����
			try {
				con.close();
			} catch (Exception e2) {
				// TODO: handle exception
				e2.printStackTrace();
			}
		}
	}
	
	
}
