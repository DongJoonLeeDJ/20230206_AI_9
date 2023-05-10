package studyjava01_method;

public class StudyJava03_rectangle_overloading {
	//직사각형용
	static int getRectArea(int w, int h)
	{
		if(w<0)
			w*=-1;
		if(h<0)
			h*=-1;
		return w*h;
	}
	//정사각형용
	static int getRectArea(int wh)
	{
		if(wh<0)
		{
			System.out.println("Error!");
			return 0;
		}
		return wh*wh;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(getRectArea(2,3));
		System.out.println(getRectArea(-2,10));
		System.out.println(getRectArea(4));
		System.out.println(getRectArea(-4));

	}

}
