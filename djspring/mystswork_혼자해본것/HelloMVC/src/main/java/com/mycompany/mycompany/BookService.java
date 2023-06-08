package com.mycompany.mycompany;

import java.util.List;
import java.util.Map;

public interface BookService {

	String create(Map<String, Object> map);

	Map<String, Object> detail(Map<String, Object> map);

	boolean edit(Map<String, Object> map);

	boolean remove(Map<String, Object> map);

	List<Map<String, Object>> list(Map<String, Object> map);
	

	int countBookBoard(Map<String, Object>map);
	
	

}
