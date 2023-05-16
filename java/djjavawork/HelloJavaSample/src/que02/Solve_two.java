package que02;

import java.util.Scanner;

import que01.Major;
import que01.Student;

public class Solve_two {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		boolean isContinue = true;
		while(isContinue)
		{
			System.out.println("�޴��� ������.");
			System.out.println("1. ����");
			System.out.println("2. �л�");
			System.out.println("3. join�� ���");
			System.out.println("�׿�. ���α׷� ����");
			int menu = Integer.parseInt(s.nextLine());
			int code;
			String name;
			int majcode;
			Major m = null;
			Student stu = null;
			switch (menu) {
			case 1:
				System.out.println("���� ���� �޴��Դϴ�.");
				System.out.println("1. ���� �߰�");
				System.out.println("2. ���� ����");
				System.out.println("3. ���� ����");
				System.out.println("4. ���� ��ȸ");
				System.out.println("5. ��ü ��ȸ");
				int majmenu = Integer.parseInt(s.nextLine());
				switch (majmenu) {
				case 1:
					System.out.println("������ �߰��Ϸ��� �մϴ�.");
					System.out.println("���� �ڵ��?");
					code = Integer.parseInt(s.nextLine());
					System.out.println("���� �̸���?");
					name = s.nextLine();
					m = new Major(code,name);
					DBConnector.doQuery("insert", null, m);
					break;

				case 2:
					System.out.println("������ �����Ϸ��� �մϴ�.");
					System.out.println("������ ������ ���� �ڵ��?");
					code = Integer.parseInt(s.nextLine());
					System.out.println("������ ���� �̸���?");
					name = s.nextLine();
					m = new Major(code,name);
					DBConnector.doQuery("update", null, m);
					break;

				case 3:
					System.out.println("������ �����Ϸ��� �մϴ�.");
					System.out.println("������ ������ ���� �ڵ��?");
					code = Integer.parseInt(s.nextLine());
					m = new Major(code);
					DBConnector.doQuery("delete", null, m);
					break;

				case 4:
					System.out.println("Ư�� ������ ��ȸ�Ϸ��� �մϴ�.");
					System.out.println("��ȸ�� ������ ���� �ڵ��?");
					code = Integer.parseInt(s.nextLine());
					DBConnector.selectQuery("Major", code, false);
					break;
				case 5:
					System.out.println("��ü ������ ��ȸ�Ϸ��� �մϴ�.");
					DBConnector.selectQuery("Major", -1, false);
					break;
				default:
					System.out.println("�߸��� �ڵ��Դϴ�.");
					break;
				}
				break;
			case 2:
				System.out.println("�л� ���� �޴��Դϴ�.");
				System.out.println("1. �л� �߰�");
				System.out.println("2. �л� ����");
				System.out.println("3. �л� ����");
				System.out.println("4. �л� ��ȸ");
				System.out.println("5. �л� ��ȸ");
				int stumenu = Integer.parseInt(s.nextLine());
				switch (stumenu) {
				case 1:
					System.out.println("�л��� �߰��Ϸ��� �մϴ�.");
					System.out.println("�й���?");
					code = Integer.parseInt(s.nextLine());
					System.out.println("�л� �̸���?");
					name = s.nextLine();
					System.out.println("�л� �����ڵ��?");
					majcode =  Integer.parseInt(s.nextLine());
					stu = new Student(code,name,majcode);
					DBConnector.doQuery("insert", stu, null);
					break;

				case 2:
					System.out.println("�л� ������ �����Ϸ��� �մϴ�.");
					System.out.println("������ �л��� �й���?");
					code = Integer.parseInt(s.nextLine());
					System.out.println("������ �л� �̸���?");
					name = s.nextLine();
					System.out.println("������ �л��� �����ڵ��?");
					majcode = Integer.parseInt(s.nextLine());
					stu = new Student(code,name, majcode);
					DBConnector.doQuery("update", stu, null);
					break;

				case 3:
					System.out.println("�л��� �����Ϸ��� �մϴ�.");
					System.out.println("������ �л��� �й���?");
					code = Integer.parseInt(s.nextLine());
					stu = new Student(code);
					DBConnector.doQuery("delete", stu, null);
					break;

				case 4:
					System.out.println("Ư�� �л��� ��ȸ�Ϸ��� �մϴ�.");
					System.out.println("��ȸ�� �л��� �й���?");
					code = Integer.parseInt(s.nextLine());
					DBConnector.selectQuery("Student", code, false);
					break;
				case 5:
					System.out.println("��ü �л��� ��ȸ�Ϸ��� �մϴ�.");
					DBConnector.selectQuery("Student", -1, false);
					break;
				default:
					System.out.println("�߸��� �ڵ��Դϴ�.");
					break;
				}
				break;
			case 3:
				System.out.println("join�� ��� ������Դϴ�.");
				DBConnector.selectQuery("Student", 0, true);
				break;

			default:
				System.out.println("���α׷� ����");
				isContinue = false;
				break;
			}
		}

	}

}
