package com.bookstore.service;

import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.bookstore.dao.CustomerDao;
import com.bookstore.dao.OrdersDao;
import com.bookstore.dao.PriceDao;

//Controller랑 DAO를 이어주는 것
@Service
public class PriceServiceImpl implements PriceService{

	@Autowired
	PriceDao priceDao;//객체 자동 생성 및 관리
	
	//import시 주의사항 : java.awt 아님
	@Override
	public List<Map<String,Object>> list() {
		return this.priceDao.selectList(null);
	}

	
}










