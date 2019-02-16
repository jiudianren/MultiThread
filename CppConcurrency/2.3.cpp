

std::thread f()
{
	void some_function();
	return std::thread(some_function);
} s
td::thread g()
{
	void some_other_function(int);
	std::thread t(some_other_function,42);
	return t;
}


void f(std::thread t);
void g()
{
	void some_function();
	f(std::thread(some_function));
	std::thread t(some_function);
	f(std::move(t));
}








void do_work(unsigned id);
void f()
{
	std::vector<std::thread> threads;
	for(unsigned i=0; i < 20; ++i)
	{
		threads.push_back(std::thread(do_work,i)); // 产生线程
	}
	std::for_each(threads.begin(),threads.end(),
			std::mem_fn(&std::thread::join)); // 对每个线程调用join()
}
