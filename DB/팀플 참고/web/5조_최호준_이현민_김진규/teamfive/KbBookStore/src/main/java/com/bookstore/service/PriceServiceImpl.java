package com.bookstore.service;

import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.bookstore.dao.CustomerDao;
import com.bookstore.dao.OrdersDao;
import com.bookstore.dao.PriceDao;

//Controller�� DAO�� �̾��ִ� ��
@Service
public class PriceServiceImpl implements PriceService{

	@Autowired
	PriceDao priceDao;//��ü �ڵ� ���� �� ����
	
	//import�� ���ǻ��� : java.awt �ƴ�
	@Override
	public List<Map<String,Object>> list() {
		return this.priceDao.selectList(null);
	}

	
}










