package com.bookstore.service;

import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.bookstore.dao.BookDao;

//Controller랑 DAO를 이어주는 것
@Service
public class BookServiceImpl implements BookService{

	@Autowired
	BookDao bookDao;//객체 자동 생성 및 관리
	
	//import시 주의사항 : java.awt 아님
	@Override
	public List<Map<String,Object>> list
	(Map<String,Object> map) {
		return this.bookDao.selectList(map);
	}

	@Override
	public int countBookBoard(Map<String, Object> map) {
		return this.bookDao.countBookBoard(map);
	}


	@Override
	public Map<String,Object> detail
		(Map<String,Object> map) {
		return this.bookDao.selectDetail(map);
	}	
	
	@Override
	public String create(Map<String, Object> map) {
		int affectRowCount = this.bookDao.insert(map);
		if(affectRowCount==1)
			return map.get("bookid").toString();
		return null;
	}
	@Override
	public boolean edit(Map<String, Object> map) {
		int afftectRowCount = 
				this.bookDao.update(map);
		//afftectRowCount가 1일 때 true리턴
		//즉 update 성공시 true리턴
		return afftectRowCount==1;
	}
	
	@Override
	public boolean remove(Map<String,Object> map) {
		int affectRowCount 
		= this.bookDao.delete(map);
		return affectRowCount==1;
	}
}










