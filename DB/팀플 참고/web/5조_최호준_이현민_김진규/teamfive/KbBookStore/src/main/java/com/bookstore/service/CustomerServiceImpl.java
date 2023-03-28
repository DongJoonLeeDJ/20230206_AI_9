package com.bookstore.service;

import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.bookstore.dao.CustomerDao;

//Controller�� DAO�� �̾��ִ� ��
@Service
public class CustomerServiceImpl implements CustomerService{

	@Autowired
	CustomerDao customerDao;//��ü �ڵ� ���� �� ����
	
	//import�� ���ǻ��� : java.awt �ƴ�
	@Override
	public List<Map<String,Object>> list
	(Map<String,Object> map) {
		return this.customerDao.selectList(map);
	}

	@Override
	public int countTotalCustomer(Map<String, Object> map) {
		return this.customerDao.countTotalCustomer(map);
	}


	@Override
	public Map<String,Object> detail
		(Map<String,Object> map) {
		return this.customerDao.selectDetail(map);
	}	
	
	@Override
	public String create(Map<String, Object> map) {
		int affectRowCount = this.customerDao.insert(map);
		if(affectRowCount==1)
			return map.get("custid").toString();
		return null;
	}
	@Override
	public boolean edit(Map<String, Object> map) {
		int afftectRowCount = 
				this.customerDao.update(map);
		//afftectRowCount�� 1�� �� true����
		//�� update ������ true����
		return afftectRowCount==1;
	}
	
	@Override
	public boolean remove(Map<String,Object> map) {
		int affectRowCount 
		= this.customerDao.delete(map);
		return affectRowCount==1;
	}
}










