package com.bookstore.dao;

import java.util.List;
import java.util.Map;

import org.mybatis.spring.SqlSessionTemplate;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

/*
 * BookDao를 Bean으로 등록함
 * DB연결 관련된 Bean 객체 = @Repository
 * */
@Repository
public class OrdersDao {

	//bean객체를 생성하는 데, 적절한 인스턴스를 생성해 줌(자동)
	//new 키워드 없어도 자동으로 만들어 줌
	@Autowired
	SqlSessionTemplate sqlSessionTemplate;
	//java.util을 import : List
	//여러 개의 Map<String,Object>을 반환함
	public List<Map<String,Object>> selectList
	(Map<String, Object> map) {
		return this.sqlSessionTemplate.selectList
				("orders.select_list",map);
	}
	
	public int countTotalOrders(Map<String,Object> map) {
		return this.sqlSessionTemplate.selectOne
				("orders.countTotalOrders",map);
	}
	public Map<String,Object> selectDetail
	(Map<String,Object> map) {
		return this.sqlSessionTemplate.
				selectOne("orders.select_detail",map);
	}

	public int insert(Map<String, Object> map) {
		// TODO Auto-generated method stub

		return this.sqlSessionTemplate.insert("orders.insert",map);
	}
	public int update(Map<String,Object> map) {
		return 
		this.sqlSessionTemplate.update
		("orders.update", map);
	}
	
	public int delete(Map<String, Object> map) {
		return 
		this.sqlSessionTemplate.delete
		("orders.delete",map);
	}
	
	
}



















