package com.mymvc.myproject;

import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class BookController {
	
	@Autowired
	BookService bookService;
	
	@RequestMapping(value="/create", method=RequestMethod.GET)
	public ModelAndView create() {
		//화면정보랑 데이터 정보를 같이 넘김
		return new ModelAndView("book/create");
	}
	
	@RequestMapping(value="/create", method=RequestMethod.POST)
	public ModelAndView createPost(@RequestParam Map<String, Object> map) {
		ModelAndView mav = new ModelAndView();
		String bookId = this.bookService.create(map);
		if(bookId == null)
			mav.setViewName("redirect:/create");
		else
			mav.setViewName("redirect:/detail?bookId="+bookId);
		return mav;
	}
	
	
	@RequestMapping(value="/detail", method=RequestMethod.GET)
	public ModelAndView detail(@RequestParam Map<String, Object> map) {
		Map<String, Object> detailMap = this.bookService.detail(map);
		System.out.println(detailMap);
		ModelAndView mav = new ModelAndView();
		mav.addObject("data", detailMap);
		String bookId = map.get("bookId").toString();
		mav.addObject("bookId", bookId);
		mav.setViewName("/book/detail");
		return mav;
	}
	
	@RequestMapping(value="/update", method=RequestMethod.GET)
	public ModelAndView update(@RequestParam Map<String, Object> map) {
		Map<String, Object> detailMap = this.bookService.detail(map);
		ModelAndView mav = new ModelAndView();
		mav.addObject("data",detailMap);
		mav.setViewName("/book/update");
		return mav;
	}
	@RequestMapping(value="/update", method=RequestMethod.POST)
	public ModelAndView updatePost(@RequestParam Map<String, Object> map) {
		ModelAndView mav = new ModelAndView();
		boolean isUpdateSuccess = this.bookService.edit(map);
		if(isUpdateSuccess) {
			String bookId = map.get("bookId").toString();
			mav.setViewName("redirect:/detail?bookId="+bookId);
		} else {
			mav = this.update(map); //원래 화면으로 돌아옴
		}
		return mav;
	}
	
	@RequestMapping(value="/delete", method=RequestMethod.POST)
	public ModelAndView deletePost(@RequestParam Map<String,Object> map) {
		ModelAndView mav = new ModelAndView();
		boolean isDeleteSuccess = this.bookService.remove(map);
		if(isDeleteSuccess)
			mav.setViewName("redirect:/list");
		else {
			String bookId=map.get("bookId").toString();
			mav.setViewName("redirect:/detail?bookId="+bookId);
		}
		return mav;
	}
	
	@RequestMapping(value="list")
	public ModelAndView list(@RequestParam Map<String, Object> map,
			@RequestParam(value="nowPage", required = false) String nowPage) {
		System.out.println("map?");
		System.out.println(map);
		
		double CNT =  2.0; //한 번에 보여지는 페이지 수를 의미
		int LIMITCOUNT = (int)CNT;
		if(nowPage!=null) {
			int now = Integer.parseInt(nowPage);
			int skipCount = 0;
			if(now>1)
				skipCount = (now-1)*LIMITCOUNT;
			map.put("skipCount", skipCount);
		} else {
			map.put("skipCount", 0);
		}
		
		
		List<Map<String,Object>> list = this.bookService.list(map);
		
		ModelAndView mav = new ModelAndView();
		mav.addObject("data",list);
		
		int totalCount = (int)Math.ceil(this.bookService.countBookBoard(map)/CNT);
		mav.addObject("totalCount", totalCount);
		
		int nowPos = nowPage==null?1:Integer.parseInt(nowPage);
		if(nowPos<=0)
			nowPos=1;
		mav.addObject("nowPage",nowPos);
		
		int endPage = (int)(Math.ceil(nowPos/CNT)*LIMITCOUNT);
		int startPage = 0;
		if(endPage>totalCount) { //끝부분
			startPage = endPage-LIMITCOUNT+1;
			endPage=totalCount;
		} else {
			startPage = endPage-LIMITCOUNT+1;
		}
		if(startPage<=0)
			startPage=1;
		
		mav.addObject("startPage",startPage);
		mav.addObject("endPage",endPage);
		
		if(map.containsKey("keyword")) {
			mav.addObject("keyword", map.get("keyword"));
		}
		
		
		mav.setViewName("/book/list");
		System.out.println(list);
		System.out.println(mav);
		return mav;
	}
	
}




