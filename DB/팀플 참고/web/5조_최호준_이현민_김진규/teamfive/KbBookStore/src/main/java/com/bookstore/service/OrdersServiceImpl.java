package com.bookstore.service;

import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.bookstore.dao.CustomerDao;
import com.bookstore.dao.OrdersDao;

//Controller�� DAO�� �̾��ִ� ��
@Service
public class OrdersServiceImpl implements OrdersService{

	@Autowired
	OrdersDao ordersDao;//��ü �ڵ� ���� �� ����
	
	//import�� ���ǻ��� : java.awt �ƴ�
	@Override
	public List<Map<String,Object>> list
	(Map<String,Object> map) {
		return this.ordersDao.selectList(map);
	}

	@Override
	public int countTotalOrders(Map<String, Object> map) {
		return this.ordersDao.countTotalOrders(map);
	}


	@Override
	public Map<String,Object> detail
		(Map<String,Object> map) {
		return this.ordersDao.selectDetail(map);
	}	
	
	@Override
	public String create(Map<String, Object> map) {
		int affectRowCount = this.ordersDao.insert(map);
		if(affectRowCount==1)
			return map.get("orderid").toString();
		return null;
	}
	@Override
	public boolean edit(Map<String, Object> map) {
		int afftectRowCount = 
				this.ordersDao.update(map);
		//afftectRowCount�� 1�� �� true����
		//�� update ������ true����
		return afftectRowCount==1;
	}
	
	@Override
	public boolean remove(Map<String,Object> map) {
		int affectRowCount 
		= this.ordersDao.delete(map);
		return affectRowCount==1;
	}
}










