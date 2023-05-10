import java.util.Optional;

class Friend {
    String name;
    Optional<Company> cmp;    // null 일 수 있음

    public Friend(String n, Optional<Company> c) {
        name = n;
        cmp = c;
    }
    public String getName() { return name; }
    public Optional<Company> getCmp() { return cmp; }
}

class Company {
    String cName;
    Optional<ContInfo> cInfo;    // null 일 수 있음

    public Company(String cn, Optional<ContInfo> ci) {
        cName = cn;
        cInfo = ci;
    }
    public String getCName() { return cName; }
    public Optional<ContInfo> getCInfo() { return cInfo; }

}

class ContInfo {
    Optional<String> phone;   // null 일 수 있음
    Optional<String> adrs;    // null 일 수 있음

    public ContInfo(Optional<String> ph, Optional<String> ad) {
        phone = ph;
        adrs = ad;
    }
    public Optional<String> getPhone() { return phone; }
    public Optional<String> getAdrs() { return adrs; }

}

class NullPointerCaseStudy3 {
    public static void showCompAddr(Optional<Friend> f) {

        String addr = f.flatMap(Friend::getCmp)
                .flatMap(Company::getCInfo)
                .flatMap(ContInfo::getAdrs)
                .orElse("There's no address information.");

        System.out.println(addr);    
    }

    public static void main(String[] args) {
        Optional<ContInfo> ci = Optional.of(
                    new ContInfo(Optional.ofNullable(null), Optional.of("Republic of Korea"))
        );
        Optional<Company> cp = Optional.of(new Company("YaHo Co., Ltd.", ci));
        Optional<Friend> frn = Optional.of(new Friend("LEE SU", cp));

        // 친구 정보에서 회사 주소를 출력
        showCompAddr(frn);
    }
}