#include "blankservice.h"
#include <stdexcept>
#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <random>

/*
 * blank customers
 * */
class Customer{
public :
	Customer(int id_, int arriveTime_, int needServiceTime_) 
		: id(id_), arriveTime(arriveTime_), 
		needServiceTime(needServiceTime_), beginServiceTime(arriveTime_-1) { }
	/*
	 * set begin service , if current time less than arrive time , 
	 * 	throw a logic error exception
	 * */
	bool beginService(int currentTime, int windowId) throw (std::logic_error) {
		if ( currentTime < arriveTime ) {
			throw std::logic_error("Current time earlyer than arrived time !");	
		}
		if ( arriveTime < beginServiceTime ) {
			return false;	// have begin service
		}
		beginServiceTime = currentTime;	// set begin service time
		// print messages
		std::cout << "Customer "<< id <<" begin service at window " << windowId <<", begin time " << currentTime << std::endl;
		return true;
	}
	// test whether the service ok 
	bool serviceOk(int currentTime) const {
		return currentTime - beginServiceTime > needServiceTime;
	}
	// test whether the customer arrived 
	bool arrived(int currentTime) const {
		return arriveTime < currentTime;
	}
	// print customer leave message
	void leave(int currentTime) {
		std::cout << "Customer " << id << "\t" << "arrive time " << arriveTime << "\t leave time " << currentTime << std::endl;
	}
	// print customer info
	void printInfo(std::string const& info) const{
		std::cout << "Customer " << id << "\t" << "arrive time " << arriveTime << "\t " << info << std::endl;
	}
private :
	int id, arriveTime, needServiceTime, beginServiceTime;
};
/*
 * blank , manage customer events
 * */
class Bank{
public :
	typedef std::size_t size_t;
	typedef std::deque<Customer> WindowsType;
	typedef WindowsType EventDequeue;

	Bank(size_t windowsCount_) : windows( windowsCount_ ) {}
	size_t windowsCount() const { return windows.size(); }
	/*
	 * random output customer events
	 * */
	EventDequeue makeCustomerEvents(int fromTime, int toTime,int spaceArrive=8, int spaceService=30) {
		EventDequeue eq ;
		int idCount =1;
		int arriveTime ;
		int needServiceTime;
		std::random_device rd;
		/**
		 *	sure every customer process ok , close before real-close-time than spaceService*2
		 * */
		for (int time=fromTime; time< toTime- spaceService*2 ; ++time){
			arriveTime = time + rd()% spaceArrive;
			needServiceTime = rd()% spaceService;
			eq.push_back(Customer(idCount, arriveTime, needServiceTime) );
			++idCount;
		}
		return eq;
	}
	/*
	 * get arived customer fron eq, and put it to the lessest window
	 * 	return this call got customer count
	 * */
	int processArrived(EventDequeue& eq, int currentTime) {
		int arrivedCount = 0;

		while (eq.empty() == false && eq.front().arrived(currentTime) == true) {
			auto lessWindow = & windows.front() ;
			for ( auto& wnd: windows) {
				if ( lessWindow->size() > wnd.size() ) {
					lessWindow = &wnd;
				}
			}
			lessWindow->push_back(eq.front());
			eq.pop_front();
			++ arrivedCount;
		}
		return arrivedCount;
	}
	/*
	 * start service at the front customer queue
	 * */
	int processService(int currentTime){
		int serviceCount =0;
		
		for (size_t wndId =0; wndId < windows.size(); ++wndId) {
			if (windows[wndId].empty()== false) {
				windows[wndId].front().beginService(currentTime, wndId);
				++ serviceCount;
			}
		}
		return serviceCount;
	}
	/* call customer leave , when his thing ok
	 * */
	int processLeaved(int currentTime) {
		int leaveCount =0;
		
		for (auto& wnd : windows) {
			while (wnd.empty()==false && wnd.front().serviceOk(currentTime) ) {
				wnd.front().leave(currentTime);
				wnd.pop_front();
				++ leaveCount;
			}
		}

		return leaveCount;
	}
	/* 
	 * output the customers which waite on the front of windows
	 * */
	void printWaiters() const {
		for ( auto& wnd: windows) {
			for (auto& cus: wnd) {
				cus.printInfo(" service didn't complete !");
			}
		}
	}
private :
	std::vector<WindowsType> windows;
};

void restonce::blankService() {
	constexpr int workTimeBegin = 0;
	constexpr int workTimeEnd  	= 1000;
	constexpr int windowsCount 	= 4;

	Bank bk(windowsCount);
	auto&& eq = bk.makeCustomerEvents(workTimeBegin, workTimeEnd);
	
	for (int t=workTimeBegin; t<workTimeEnd; ++t) {
		bk.processArrived(eq, t);
		bk.processService(t);
		bk.processLeaved(t);
	}
	bk.printWaiters();
}
