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
			System.out.println("메뉴를 고르세요.");
			System.out.println("1. 전공");
			System.out.println("2. 학생");
			System.out.println("3. join한 결과");
			System.out.println("그외. 프로그램 종료");
			int menu = Integer.parseInt(s.nextLine());
			int code;
			String name;
			int majcode;
			Major m = null;
			Student stu = null;
			switch (menu) {
			case 1:
				System.out.println("전공 관련 메뉴입니다.");
				System.out.println("1. 전공 추가");
				System.out.println("2. 전공 수정");
				System.out.println("3. 전공 삭제");
				System.out.println("4. 전공 조회");
				System.out.println("5. 전체 조회");
				int majmenu = Integer.parseInt(s.nextLine());
				switch (majmenu) {
				case 1:
					System.out.println("전공을 추가하려고 합니다.");
					System.out.println("전공 코드는?");
					code = Integer.parseInt(s.nextLine());
					System.out.println("전공 이름은?");
					name = s.nextLine();
					m = new Major(code,name);
					DBConnector.doQuery("insert", null, m);
					break;

				case 2:
					System.out.println("전공을 수정하려고 합니다.");
					System.out.println("수정할 전공의 전공 코드는?");
					code = Integer.parseInt(s.nextLine());
					System.out.println("수정할 전공 이름은?");
					name = s.nextLine();
					m = new Major(code,name);
					DBConnector.doQuery("update", null, m);
					break;

				case 3:
					System.out.println("전공을 삭제하려고 합니다.");
					System.out.println("삭제할 전공의 전공 코드는?");
					code = Integer.parseInt(s.nextLine());
					m = new Major(code);
					DBConnector.doQuery("delete", null, m);
					break;

				case 4:
					System.out.println("특정 전공을 조회하려고 합니다.");
					System.out.println("조회할 전공의 전공 코드는?");
					code = Integer.parseInt(s.nextLine());
					DBConnector.selectQuery("Major", code, false);
					break;
				case 5:
					System.out.println("전체 전공을 조회하려고 합니다.");
					DBConnector.selectQuery("Major", -1, false);
					break;
				default:
					System.out.println("잘못된 코드입니다.");
					break;
				}
				break;
			case 2:
				System.out.println("학생 관련 메뉴입니다.");
				System.out.println("1. 학생 추가");
				System.out.println("2. 학생 수정");
				System.out.println("3. 학생 삭제");
				System.out.println("4. 학생 조회");
				System.out.println("5. 학생 조회");
				int stumenu = Integer.parseInt(s.nextLine());
				switch (stumenu) {
				case 1:
					System.out.println("학생을 추가하려고 합니다.");
					System.out.println("학번은?");
					code = Integer.parseInt(s.nextLine());
					System.out.println("학생 이름은?");
					name = s.nextLine();
					System.out.println("학생 전공코드는?");
					majcode =  Integer.parseInt(s.nextLine());
					stu = new Student(code,name,majcode);
					DBConnector.doQuery("insert", stu, null);
					break;

				case 2:
					System.out.println("학생 정보를 수정하려고 합니다.");
					System.out.println("수정할 학생의 학번은?");
					code = Integer.parseInt(s.nextLine());
					System.out.println("수정할 학생 이름은?");
					name = s.nextLine();
					System.out.println("수정할 학생의 전공코드는?");
					majcode = Integer.parseInt(s.nextLine());
					stu = new Student(code,name, majcode);
					DBConnector.doQuery("update", stu, null);
					break;

				case 3:
					System.out.println("학생을 삭제하려고 합니다.");
					System.out.println("삭제할 학생의 학번은?");
					code = Integer.parseInt(s.nextLine());
					stu = new Student(code);
					DBConnector.doQuery("delete", stu, null);
					break;

				case 4:
					System.out.println("특정 학생을 조회하려고 합니다.");
					System.out.println("조회할 학생의 학번은?");
					code = Integer.parseInt(s.nextLine());
					DBConnector.selectQuery("Student", code, false);
					break;
				case 5:
					System.out.println("전체 학생을 조회하려고 합니다.");
					DBConnector.selectQuery("Student", -1, false);
					break;
				default:
					System.out.println("잘못된 코드입니다.");
					break;
				}
				break;
			case 3:
				System.out.println("join한 출력 결과물입니다.");
				DBConnector.selectQuery("Student", 0, true);
				break;

			default:
				System.out.println("프로그램 종료");
				isContinue = false;
				break;
			}
		}

	}

}
