1. sql plus를 켠다.

2. 사용자명 : system
비밀번호 : 1234


만약 안 된 다면?
오류 메시지별로 구글링을 해서 찾아본다.

1. 비밀번호 까먹은거면 비밀번호 찾아야 한다. 본인이 1234로 설정 안한 걸수도 있다.
2. 도저히 기억 안나면 cmd 창에
sql plus "/as sysdba" 

이렇게 입력하고 나서 비밀번호 바꾸고 system 계정 unlock해준다.(구글링해보기)



3. sql plus에서 아래 명령어를 친다.

--scott 게정 생성
create user c##scott identified by tiger;

--기본적인 권한을 부여
grant connect, resource to c##scott;

-- 추후 뷰 수업때 필요
grant create view to c##scott;

-- 유저에 대해서 용량 제한을 풀은 것
-- 이거 안 하면 제대로된 crud를 할 수 없다.
ALTER USER c##scott DEFAULT TABLESPACE USERS QUOTA UNLIMITED ON USERS;