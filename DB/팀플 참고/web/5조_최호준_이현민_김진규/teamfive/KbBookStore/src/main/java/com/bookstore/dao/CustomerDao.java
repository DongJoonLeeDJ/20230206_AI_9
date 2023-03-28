package com.bookstore.dao;

import java.util.List;
import java.util.Map;

import org.mybatis.spring.SqlSessionTemplate;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

/*
 * BookDao�� Bean���� �����
 * DB���� ���õ� Bean ��ü = @Repository
 * */
@Repository
public class CustomerDao {

	//bean��ü�� �����ϴ� ��, ������ �ν��Ͻ��� ������ ��(�ڵ�)
	//new Ű���� ��� �ڵ����� ����� ��
	@Autowired
	SqlSessionTemplate sqlSessionTemplate;
	//java.util�� import : List
	//���� ���� Map<String,Object>�� ��ȯ��
	public List<Map<String,Object>> selectList
	(Map<String, Object> map) {
		return this.sqlSessionTemplate.selectList
				("customer.select_list",map);
	}
	
	public int countTotalCustomer(Map<String,Object> map) {
		return this.sqlSessionTemplate.selectOne
				("customer.countTotalCustomer",map);
	}
	public Map<String,Object> selectDetail
	(Map<String,Object> map) {
		return this.sqlSessionTemplate.
				selectOne("customer.select_detail",map);
	}

	public int insert(Map<String, Object> map) {
		// TODO Auto-generated method stub

		return this.sqlSessionTemplate.insert("customer.insert",map);
	}
	public int update(Map<String,Object> map) {
		return 
		this.sqlSessionTemplate.update
		("customer.update", map);
	}
	
	public int delete(Map<String, Object> map) {
		return 
		this.sqlSessionTemplate.delete
		("customer.delete",map);
	}
	
	
}



















