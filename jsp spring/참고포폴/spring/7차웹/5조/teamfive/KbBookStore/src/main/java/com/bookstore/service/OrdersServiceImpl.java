package com.bookstore.service;

import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.bookstore.dao.CustomerDao;
import com.bookstore.dao.OrdersDao;

//Controller랑 DAO를 이어주는 것
@Service
public class OrdersServiceImpl implements OrdersService{

	@Autowired
	OrdersDao ordersDao;//객체 자동 생성 및 관리
	
	//import시 주의사항 : java.awt 아님
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
		//afftectRowCount가 1일 때 true리턴
		//즉 update 성공시 true리턴
		return afftectRowCount==1;
	}
	
	@Override
	public boolean remove(Map<String,Object> map) {
		int affectRowCount 
		= this.ordersDao.delete(map);
		return affectRowCount==1;
	}
}










