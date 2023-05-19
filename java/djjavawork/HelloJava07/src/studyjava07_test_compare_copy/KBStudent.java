package studyjava07_test_compare_copy;

import studyjava06_basic_interface.Student;

public class KBStudent extends Student {

	private int cScore;
	private int javaScore;
	
	
	public int getcScore() {
		return cScore;
	}

	public void setcScore(int cScore) {
		this.cScore = cScore;
	}

	public int getJavaScore() {
		return javaScore;
	}

	public void setJavaScore(int javaScore) {
		this.javaScore = javaScore;
	}
	
	public int getSum() {
		return this.cScore+this.javaScore;
	}

	@Override
	public int compareTo(Student o) {
		// TODO Auto-generated method stub
		
		return  ((KBStudent)o).getSum() - getSum();
		//return super.compareTo(o);
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "번호:"+getNum()+",이름:"+getName()+",총점:"+getSum();
	}
	
	public KBStudent(String num, String name, int age, int cScore, int javaScore) {
		super(num, name, age);
		this.cScore = cScore;
		this.javaScore = javaScore;
	}

	public KBStudent(String num, String name, int age) {
		super(num, name, age);
		// TODO Auto-generated constructor stub
	}

}
