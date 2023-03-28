package com.bookstore.controller;

import java.io.File;
import java.io.IOException;
import java.text.DateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.UUID;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.servlet.ModelAndView;

import com.bookstore.service.CustomerService;



/**
 * Handles requests for the application home page.
 */
@RequestMapping("/customer/*") 
@Controller
public class CustomerController {

	private static final Logger Logger = LoggerFactory.getLogger(CustomerController.class);

	@Autowired
	CustomerService customerService;

	//����¡ ó�� ���ؼ� �Ű� ������ 2���� ��
		//������ ��ü �Ű������� map�� ���Ҿ
		//���� �������� �ǹ��ϴ� nowPage�� ���� ������
		@RequestMapping(value="list")
		public ModelAndView list
		(@RequestParam Map<String,Object> map,
		 @RequestParam(value="nowPage", 
		 required=false) String nowPage) {
			double CNT = 5.0; //�� ���� �������� ������ �ǹ�(�ؿ� ����)
			int LIMITCOUNT = (int)CNT;
			if(nowPage!=null) {
				int now = Integer.parseInt(nowPage);
				int skipCount=0;
				if(now>1)
					skipCount = (now-1)*LIMITCOUNT;
				map.put("skipCount", skipCount);
			} else {
				map.put("skipCount",0);
			}
			
			List<Map<String,Object>> list =
					this.customerService.list(map);
			ModelAndView mav = new ModelAndView();
			mav.addObject("data",list);
			int totalCount = 
					(int)Math.ceil
					(this.customerService.countTotalCustomer(map)/CNT);
					//ceil : �ø�
			mav.addObject("totalCount", totalCount);//�� �� ������ ����
			
			int nowPos = nowPage==null?1:Integer.parseInt(nowPage);
			if(nowPos<=0)
				nowPos=1;
			mav.addObject("nowPage",nowPos);
			
			int endPage = (int)(Math.ceil(nowPos/CNT)*(LIMITCOUNT));
			int startPage = 0;
			if(endPage>totalCount) { //�� �κ�
				startPage = endPage-(LIMITCOUNT)+1;
				endPage=totalCount;
			} else {
				startPage = endPage-(LIMITCOUNT)+1;
			}
			if(startPage<=0)
				startPage=1;
			
			mav.addObject("startPage", startPage);
			mav.addObject("endPage", endPage);
			
			
			
			//�˻��� �Ķ���� �� �߰���
			//�˻� �ƹ� �͵� �Է� �� �ϸ� ������ ��Ϻ��� ó�� ����
			if(map.containsKey("keyword"))
				mav.addObject("keyword", map.get("keyword"));
			
			mav.setViewName("/customer/customerList");
			return mav;
			
		}
		
		
		@RequestMapping(value="detail", 
				method=RequestMethod.GET)
		public ModelAndView detail
		(@RequestParam Map<String,Object> map) {
			Map<String,Object> detailMap = 
					this.customerService.detail(map);
			//ModelAndView : ����������� ����, � ������ ������
			//���� �����ؼ� �� ���� ������.
			ModelAndView mav = new ModelAndView();
			mav.addObject("data", detailMap);
			String custId = map.get("custid").toString();
			mav.addObject("custid", custId);
			mav.setViewName("/customer/customerDetail");
			return mav;
		}
		
		@RequestMapping(value="create", 
				method=RequestMethod.GET)
		public ModelAndView create() {
			return new ModelAndView("customer/customerCreate");
		}
		
		@RequestMapping(value="create", 
				method = RequestMethod.POST) 
		public ModelAndView createPost
		(@RequestParam Map<String,Object>map) {

			Logger.info("create map = " + map.toString());
			
			ModelAndView mav = new ModelAndView();
			
			String custId = this.customerService.create(map);
			
			if(custId==null)
				mav.setViewName("redirect:/customer/create");
			else
				mav.setViewName
				("redirect:/customer/detail?custid="+custId);
			return mav;
		}
	
	@RequestMapping(value="delete", method= RequestMethod.POST) 
	public ModelAndView deletePost (@RequestParam Map<String,Object> map) {
		ModelAndView mav = new ModelAndView();
		Logger.info("delete map = {}", map);
		boolean isDeleteSuccess = this.customerService.remove(map);
		if(isDeleteSuccess) {
			mav.setViewName("redirect:/customer/list");
		} else {
			String custId = map.get("custid").toString();
			mav.setViewName	("redirect:/customer/detail?custid="+custId);
		}
		return mav;
	}
	
	@RequestMapping(value="update",
			method=RequestMethod.GET)
	public ModelAndView update
	(@RequestParam Map<String,Object> map) {
		Map<String,Object> detailMap = this.customerService.detail(map);
		ModelAndView mav = new ModelAndView();
		mav.addObject("data", detailMap);
		System.out.println(detailMap);
		mav.setViewName("/customer/customerUpdate");
		return mav;
	}
	
	@RequestMapping(value="update", method=RequestMethod.POST)
	public ModelAndView updatePost (@RequestParam Map<String, Object> map) {
		
		ModelAndView mav = new ModelAndView();
		boolean isUpdateSuccess = this.customerService.edit(map);
		if(isUpdateSuccess) {
			String custId=map.get("custid").toString();
			mav.setViewName("redirect:/customer/detail?custid="+custId);
		} else {
			mav = this.update(map); //get������� �ٽ� ����
		}
		return mav;
	}
	
	
}
