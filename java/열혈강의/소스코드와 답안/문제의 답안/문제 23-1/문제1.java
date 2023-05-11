import java.util.HashSet;

class Person {
    private String name;
    private int age;
    
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    
    public String toString() {
        return name + "(" + age + "技)";
    }
    
    public int hashCode() {
        return name.hashCode() + (age % 7);
    }
    
    public boolean equals(Object obj) {
        Person comp = (Person)obj;
        
        if(comp.name.equals(name) && (comp.age == age))
            return true;
        else
            return false;
    }
}

class PersonORDemo {
    public static void main(String[] args) {
        HashSet<Person> hSet = new HashSet<Person>();
        hSet.add(new Person("LEE", 10));
        hSet.add(new Person("LEE", 10));
       	hSet.add(new Person("PARK", 35));
        hSet.add(new Person("PARK", 35));

        System.out.println("历厘等 单捞磐 荐: " + hSet.size());
        System.out.println(hSet);
    }
}