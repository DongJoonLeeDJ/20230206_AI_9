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
			
		return "해당학과없음";
		
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
			System.out.println("메뉴 입력");
			System.out.println("1. 전공");
			System.out.println("2. 학생");
			System.out.println("3. join 결과 출력");
			System.out.println("그 외. 종료");
			int menu = Integer.parseInt(s.nextLine());
			switch (menu) {
			case 1:
				System.out.println("메뉴 입력");
				System.out.println("1. 전공 추가");
				System.out.println("2. 전공 수정");
				System.out.println("3. 전공 삭제");
				System.out.println("4. 전공 조회");
				System.out.println("5. 전체 조회");
				int majmenu = Integer.parseInt(s.nextLine());
				int code;
				String name;
				switch (majmenu) {
				case 1:
					System.out.println("전공 추가!");
					System.out.println("새로 추가할 전공의 코드?");
					code = Integer.parseInt(s.nextLine());
					for(Major item : majors)
					{
						if(item.getCode() == code)
						{
							System.out.println("기본키 중복!(전공)");
							isPKoK = false;
							break;
						}
					}
					if(isPKoK==false)
					{
						isPKoK = true;
						break;
					}
					System.out.println("새로 추가할 전공의 이름은?");
					name = s.nextLine();
					majors.add(new Major(code,name));
					break;

				case 2:
					System.out.println("전공 수정!");
					System.out.println("수정할 전공 코드?");
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
						System.out.println("해당 전공은 존재하지 않습니다.");
						break;
					}
					System.out.println("수정할 전공명?");
					name = s.nextLine();
					majors.get(index).setName(name);
					index = -1;
					break;

				case 3:
					System.out.println("전공 삭제!");
					System.out.println("삭제할 전공 코드?");
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
						System.out.println("해당 전공은 존재하지 않습니다.");
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
					if(isFKoK) //학과가 1번인 학생이 있는 데, 부모 테이블인 학과테이블에서 1번 학과를 지울 순 없다.
					{
						System.out.println("자식 테이블에 해당 학과코드를 갖는 튜플이 있습니다! 따라서 삭제할 수 없습니다!");
						isFKoK = false;
						break;
					}
					majors.remove(index);
					index = -1;
					break;

				case 4:
					System.out.println("전공 조회!");
					System.out.println("조회할 전공 코드?");
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
						System.out.println("해당 전공은 존재하지 않습니다.");
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
					System.out.println("(전공)존재하지 않는 메뉴!");
					break;
				}
				break;
			case 2:
				System.out.println("메뉴 입력");
				System.out.println("1. 학생 추가");
				System.out.println("2. 학생 수정");
				System.out.println("3. 학생 삭제");
				System.out.println("4. 학생 조회");
				System.out.println("5. 전체 조회");
				int stumenu = Integer.parseInt(s.nextLine());				
				int stucode;
				String stuname;
				int majcode;
				switch (stumenu) {
				case 1:
					System.out.println("학생 추가!");
					System.out.println("새로 추가할 학생의 학번?");
					stucode = Integer.parseInt(s.nextLine());
					for(Student item : students)
					{
						if(item.getCode() == stucode)
						{
							System.out.println("기본키 중복!(학생)");
							isPKoK = false;
							break;
						}
					}
					if(isPKoK==false)
					{
						isPKoK = true;
						break;
					}
					System.out.println("새로 추가할 학생의 이름은?");
					stuname = s.nextLine();
					System.out.println("새로 추가할 학생의 학과코드는?");
					majcode = Integer.parseInt(s.nextLine());
					for(int i = 0; i<majors.size(); i++) //FK 체크
					{
						if(majcode == majors.get(i).getCode())
						{
							isFKoK = true;
						}
					}
					
					if(isFKoK==false) //학과테이블에 학과코드가 777인 게 없는 데, 학과코드가 777인 학생을 추가할 순 없다.
					{
						System.out.println("해당 학과 코드 없음!");
						break;
					}
					isFKoK = false;
					students.add(new Student(stucode,stuname,majcode));
					break;

				case 2:
					System.out.println("학생 수정!");
					System.out.println("수정할 학생의 번호?");
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
						System.out.println("해당 학생은 존재하지 않습니다.");
						break;
					}
					System.out.println("수정할 학생 이름?");
					stuname = s.nextLine();
					System.out.println("수정할 학생의 학과 코드?");
					majcode = Integer.parseInt(s.nextLine());
					for(int i = 0; i<majors.size(); i++) //FK 체크
					{
						if(majcode == majors.get(i).getCode())
						{
							isFKoK = true;
						}
					}
					if(isFKoK==false) //학과테이블에 학과코드가 777인 게 없는 데, 학과 코드를 777로 수정할 순 없다.
					{
						System.out.println("해당 학과 코드 없음!");
						break;
					}
					isFKoK = false;

					//해당 학생의 이름과 학과 코드를 수정
					students.get(index).setName(stuname);
					students.get(index).setMajCode(majcode);
					index = -1;
					break;

				case 3:
					System.out.println("학생 삭제!");
					System.out.println("삭제할 학생의 학번?");
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
						System.out.println("해당 학생은 존재하지 않습니다.");
						break;
					}
					students.remove(index);
					index = -1;
					break;

				case 4:
					System.out.println("학생 조회!");
					System.out.println("조회할 학생의 학번?");
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
						System.out.println("해당 학생은 존재하지 않습니다.");
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
					System.out.println("(학생)존재하지 않는 메뉴!");
					break;
				}
				break;
				
			case 3:
				System.out.print("학번\t");
				System.out.print("이름\t");
				System.out.print("학과\n");
				for (Student student : students) {
					System.out.print(student.getCode()+"\t");
					System.out.print(student.getName()+"\t");
					System.out.print(findMajName(student.getMajCode(), majors) +"\n");
				}
				break;
			

			default:
				isContinue = false;
				System.out.println("프로그램 종료");
				break;
			}
		}

	}
}
