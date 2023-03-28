package com.bookstore.controller;

import java.util.List;
import java.util.Map;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

import com.bookstore.service.OrdersService;
import com.bookstore.service.PriceService;

@Controller
public class UtilController {

	private static final Logger Logger = LoggerFactory.getLogger(UtilController.class);
	@RequestMapping(value="error")
	public String error() {
		return "error";
	}

	@Autowired
	PriceService priceService;
	
	@RequestMapping(value="bookpricelist")
	public ModelAndView priceChart() {

		List<Map<String,Object>> list =
				this.priceService.list();
		ModelAndView mav = new ModelAndView();
		mav.addObject("data",list);
		mav.setViewName("/bookpricelist");
		return mav;
	}
}
