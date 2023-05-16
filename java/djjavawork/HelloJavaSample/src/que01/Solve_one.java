package que01;

import java.util.ArrayList;
import java.util.Scanner;

public class Solve_one {
	
	static String findMajName(int majcode, ArrayList<Major> m)
	{
		for(int i=0;i<m.size();i++ )
		{
			if(majcode==m.get(i).getCode())
			{
				return m.get(i).getName();
			}
		}
			
		return "�ش��а�����";
		
	}

	public static void main(String[] args) {

		ArrayList<Major> majors = new ArrayList<Major>();
		ArrayList<Student> students = new ArrayList<Student>();
		Scanner s = new Scanner(System.in);
		boolean isPKoK = true;
		boolean isFKoK = false;
		boolean isContinue = true;
		int index = -1;
		while(isContinue)
		{
			System.out.println("�޴� �Է�");
			System.out.println("1. ����");
			System.out.println("2. �л�");
			System.out.println("3. join ��� ���");
			System.out.println("�� ��. ����");
			int menu = Integer.parseInt(s.nextLine());
			switch (menu) {
			case 1:
				System.out.println("�޴� �Է�");
				System.out.println("1. ���� �߰�");
				System.out.println("2. ���� ����");
				System.out.println("3. ���� ����");
				System.out.println("4. ���� ��ȸ");
				System.out.println("5. ��ü ��ȸ");
				int majmenu = Integer.parseInt(s.nextLine());
				int code;
				String name;
				switch (majmenu) {
				case 1:
					System.out.println("���� �߰�!");
					System.out.println("���� �߰��� ������ �ڵ�?");
					code = Integer.parseInt(s.nextLine());
					for(Major item : majors)
					{
						if(item.getCode() == code)
						{
							System.out.println("�⺻Ű �ߺ�!(����)");
							isPKoK = false;
							break;
						}
					}
					if(isPKoK==false)
					{
						isPKoK = true;
						break;
					}
					System.out.println("���� �߰��� ������ �̸���?");
					name = s.nextLine();
					majors.add(new Major(code,name));
					break;

				case 2:
					System.out.println("���� ����!");
					System.out.println("������ ���� �ڵ�?");
					code = Integer.parseInt(s.nextLine());
					for(int i = 0; i<majors.size(); i++)
					{
						if(majors.get(i).getCode() == code)
						{
							index=i;
							break;
						}
					}
					if(index==-1)
					{
						System.out.println("�ش� ������ �������� �ʽ��ϴ�.");
						break;
					}
					System.out.println("������ ������?");
					name = s.nextLine();
					majors.get(index).setName(name);
					index = -1;
					break;

				case 3:
					System.out.println("���� ����!");
					System.out.println("������ ���� �ڵ�?");
					code = Integer.parseInt(s.nextLine());
					for(int i = 0; i<majors.size(); i++)
					{
						if(majors.get(i).getCode() == code)
						{
							index=i;
							break;
						}
					}
					if(index==-1)
					{
						System.out.println("�ش� ������ �������� �ʽ��ϴ�.");
						break;
					}
					for(int i = 0; i<majors.size(); i++)
					{
						for(int j = 0; j<students.size();j++)
						{
							if(students.get(j).getMajCode() == majors.get(i).getCode())
							{
								isFKoK = true;
							}
						}
					}
					if(isFKoK) //�а��� 1���� �л��� �ִ� ��, �θ� ���̺��� �а����̺��� 1�� �а��� ���� �� ����.
					{
						System.out.println("�ڽ� ���̺� �ش� �а��ڵ带 ���� Ʃ���� �ֽ��ϴ�! ���� ������ �� �����ϴ�!");
						isFKoK = false;
						break;
					}
					majors.remove(index);
					index = -1;
					break;

				case 4:
					System.out.println("���� ��ȸ!");
					System.out.println("��ȸ�� ���� �ڵ�?");
					code = Integer.parseInt(s.nextLine());
					for(int i = 0; i<majors.size(); i++)
					{
						if(majors.get(i).getCode() == code)
						{
							index=i;
							break;
						}
					}
					if(index==-1)
					{
						System.out.println("�ش� ������ �������� �ʽ��ϴ�.");
						break;
					}
					majors.get(index).showMajor();
					index = -1;
					break;

				case 5:
					for(Major item : majors)
						item.showMajor();
					break;
				default:
					System.out.println("(����)�������� �ʴ� �޴�!");
					break;
				}
				break;
			case 2:
				System.out.println("�޴� �Է�");
				System.out.println("1. �л� �߰�");
				System.out.println("2. �л� ����");
				System.out.println("3. �л� ����");
				System.out.println("4. �л� ��ȸ");
				System.out.println("5. ��ü ��ȸ");
				int stumenu = Integer.parseInt(s.nextLine());				
				int stucode;
				String stuname;
				int majcode;
				switch (stumenu) {
				case 1:
					System.out.println("�л� �߰�!");
					System.out.println("���� �߰��� �л��� �й�?");
					stucode = Integer.parseInt(s.nextLine());
					for(Student item : students)
					{
						if(item.getCode() == stucode)
						{
							System.out.println("�⺻Ű �ߺ�!(�л�)");
							isPKoK = false;
							break;
						}
					}
					if(isPKoK==false)
					{
						isPKoK = true;
						break;
					}
					System.out.println("���� �߰��� �л��� �̸���?");
					stuname = s.nextLine();
					System.out.println("���� �߰��� �л��� �а��ڵ��?");
					majcode = Integer.parseInt(s.nextLine());
					for(int i = 0; i<majors.size(); i++) //FK üũ
					{
						if(majcode == majors.get(i).getCode())
						{
							isFKoK = true;
						}
					}
					
					if(isFKoK==false) //�а����̺� �а��ڵ尡 777�� �� ���� ��, �а��ڵ尡 777�� �л��� �߰��� �� ����.
					{
						System.out.println("�ش� �а� �ڵ� ����!");
						break;
					}
					isFKoK = false;
					students.add(new Student(stucode,stuname,majcode));
					break;

				case 2:
					System.out.println("�л� ����!");
					System.out.println("������ �л��� ��ȣ?");
					stucode = Integer.parseInt(s.nextLine());
					for(int i = 0; i<students.size(); i++)
					{
						if(students.get(i).getCode() == stucode)
						{
							index=i;
							break;
						}
					}
					if(index==-1)
					{
						System.out.println("�ش� �л��� �������� �ʽ��ϴ�.");
						break;
					}
					System.out.println("������ �л� �̸�?");
					stuname = s.nextLine();
					System.out.println("������ �л��� �а� �ڵ�?");
					majcode = Integer.parseInt(s.nextLine());
					for(int i = 0; i<majors.size(); i++) //FK üũ
					{
						if(majcode == majors.get(i).getCode())
						{
							isFKoK = true;
						}
					}
					if(isFKoK==false) //�а����̺� �а��ڵ尡 777�� �� ���� ��, �а� �ڵ带 777�� ������ �� ����.
					{
						System.out.println("�ش� �а� �ڵ� ����!");
						break;
					}
					isFKoK = false;

					//�ش� �л��� �̸��� �а� �ڵ带 ����
					students.get(index).setName(stuname);
					students.get(index).setMajCode(majcode);
					index = -1;
					break;

				case 3:
					System.out.println("�л� ����!");
					System.out.println("������ �л��� �й�?");
					stucode = Integer.parseInt(s.nextLine());
					for(int i = 0; i<students.size(); i++)
					{
						if(students.get(i).getCode() == stucode)
						{
							index=i;
							break;
						}
					}
					if(index==-1)
					{
						System.out.println("�ش� �л��� �������� �ʽ��ϴ�.");
						break;
					}
					students.remove(index);
					index = -1;
					break;

				case 4:
					System.out.println("�л� ��ȸ!");
					System.out.println("��ȸ�� �л��� �й�?");
					stucode = Integer.parseInt(s.nextLine());
					for(int i = 0; i<students.size(); i++)
					{
						if(students.get(i).getCode() == stucode)
						{
							index=i;
							break;
						}
					}
					if(index==-1)
					{
						System.out.println("�ش� �л��� �������� �ʽ��ϴ�.");
						break;
					}
					students.get(index).showStudent();
					index = -1;
					break;

				case 5:
					for(Student item : students)
						item.showStudent();
					break;
				default:
					System.out.println("(�л�)�������� �ʴ� �޴�!");
					break;
				}
				break;
				
			case 3:
				System.out.print("�й�\t");
				System.out.print("�̸�\t");
				System.out.print("�а�\n");
				for (Student student : students) {
					System.out.print(student.getCode()+"\t");
					System.out.print(student.getName()+"\t");
					System.out.print(findMajName(student.getMajCode(), majors) +"\n");
				}
				break;
			

			default:
				isContinue = false;
				System.out.println("���α׷� ����");
				break;
			}
		}

	}
}
