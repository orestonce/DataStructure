/**
 * Semaphore example, written in C++ May 4, 2014
 * Compiled on OSX 10.9, using:
 * g++ -std=c++11 semaphore.cpp
 **/

#include <iostream>      
#include <thread>        
#include <mutex>         
#include <condition_variable>
#include <vector>
#include <random>

class Semaphore
{
public :
	Semaphore(int i_)
		: i(i_){}
	void p()
	{
		std::unique_lock<std::mutex> lk(m);
		cv.wait(lk, [&](){ return i > 0 ; } );
		-- i;
	}
	void v()
	{
		std::unique_lock<std::mutex> lk(m);
		if ( ++ i >0 ) {
			cv.notify_one();
		}
	}
private:
	int i;
	std::mutex m;
	std::condition_variable cv;
};

class Box 
{
public :
	Box(int sz)
		: sem_empty(sz), sem_full(0)
	{
		products.resize(sz);
		pos_read = pos_write = 0;
	}
	void put(int x)
	{
		sem_empty.p();
		{
			std::lock_guard<std::mutex> lg(mtx_write);
			products[pos_write] = x ;
			pos_write = (pos_write+1) % products.size();
		}
		sem_full.v();
	}
	int get()
	{
		sem_full.p();
		int x;
		{
			std::lock_guard<std::mutex> lg(mtx_read);
			x = products[pos_read];
			pos_read = (pos_read +1) % products.size();
		}
		sem_empty.v();
		return x;
	}
private:
	std::vector<int> products;
	Semaphore sem_empty, sem_full;
	int pos_read, pos_write;
	std::mutex mtx_write, mtx_read;
};

std::mutex mtx_io;

void producter(Box& b,std::random_device& rd, int count)
{
	while ( count -- )
	{
		int x = rd() % 19;
		b.put( x );
		
		std::lock_guard<std::mutex> lock_io(mtx_io);
		std::cout << __func__ << " " << x << std::endl;
	}
}

void customer(Box& b, int count)
{
	while ( count -- )
	{
		int x = b.get();
		std::lock_guard<std::mutex> lock_io(mtx_io);

		std::cout << __func__ << " " << x << std::endl;
	}
}

int main()
{
	Box b(6);

	std::vector<std::thread> producters;
	std::vector<std::thread> customers;
	std::random_device rd;
	constexpr int total_products = 300;
	int min_size = 50;
	
	int temp_total = total_products;

	while ( temp_total > 0 )
	{
		if ( temp_total <= min_size ) {
			producters.push_back(std::thread(producter, std::ref(b), std::ref(rd), temp_total));
			break;
		} else {
			int current_product = rd() % min_size;
			temp_total -= current_product;
			producters.push_back(std::thread(producter, std::ref(b), std::ref(rd), current_product));
		}
	}
	temp_total = total_products;
	while ( temp_total > 0 )
	{
		if ( temp_total <= min_size ) {
			customers.push_back(std::thread(customer, std::ref(b), temp_total));
			break;
		} else {
			int current_product = rd() % min_size;
			temp_total -= current_product;
			customers.push_back(std::thread(customer, std::ref(b), current_product));
		}
	}
	
	for(auto&& t : producters)
	{
		t.join();
	}	
	for(auto&& t : customers)
	{
		t.join();
	}
	return 0;
}
