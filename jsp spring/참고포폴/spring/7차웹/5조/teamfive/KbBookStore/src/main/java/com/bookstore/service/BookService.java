package com.bookstore.service;

import java.util.List;
import java.util.Map;

public interface BookService {

	List<Map<String, Object>> list(Map<String, Object> map);

	int countBookBoard(Map<String, Object>map);
	Map<String, Object> detail(Map<String, Object> map);

	String create(Map<String, Object> map);

	boolean edit(Map<String,Object> map);

	boolean remove(Map<String, Object> map);
}
















