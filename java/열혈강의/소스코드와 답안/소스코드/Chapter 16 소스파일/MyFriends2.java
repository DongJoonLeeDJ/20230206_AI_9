class Friend {
    protected String name;
    protected String phone;

    public Friend(String na, String ph) {
        name = na;
        phone = ph;
    }

    public void showInfo() {
        System.out.println("�̸�: " + name);
        System.out.println("��ȭ: " + phone);
    }
    
}

class UnivFriend extends Friend {
    private String major;

    public UnivFriend(String na, String ma, String ph) {
        super(na, ph);
        major = ma;
    }

    public void showInfo() {
        super.showInfo();
        System.out.println("����: " + major);
    }
}


class CompFriend extends Friend {
    private String department;

    public CompFriend(String na, String de, String ph) {
        super(na, ph);
        department = de;
    }
    
    public void showInfo() {
        super.showInfo();
        System.out.println("�μ�: " + department);
    }
}


class MyFriends2 {
    public static void main(String[] args) {
        Friend[] frns = new Friend[10];
        int cnt = 0;
        
        frns[cnt++] = new UnivFriend("LEE", "Computer", "010-333-555");
        frns[cnt++] = new UnivFriend("SEO", "Electronics", "010-222-444");
        frns[cnt++] = new CompFriend("YOON", "R&D 1", "02-123-999");
        frns[cnt++] = new CompFriend("PARK", "R&D 2", "02-321-777");


        // ��� ��â �� ������ ���� ��ü ���
        for(int i = 0; i < cnt; i++) {
            frns[i].showInfo();
            System.out.println();
        }        
    }
}