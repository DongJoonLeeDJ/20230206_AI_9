package com.bookstore.service;

import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.bookstore.dao.BookDao;

//Controller�� DAO�� �̾��ִ� ��
@Service
public class BookServiceImpl implements BookService{

	@Autowired
	BookDao bookDao;//��ü �ڵ� ���� �� ����
	
	//import�� ���ǻ��� : java.awt �ƴ�
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
		//afftectRowCount�� 1�� �� true����
		//�� update ������ true����
		return afftectRowCount==1;
	}
	
	@Override
	public boolean remove(Map<String,Object> map) {
		int affectRowCount 
		= this.bookDao.delete(map);
		return affectRowCount==1;
	}
}










