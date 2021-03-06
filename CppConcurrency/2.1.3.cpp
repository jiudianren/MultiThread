struct func; // 定义在清单2.1中
void f()
{
	int some_local_state=0;
	func my_func(some_local_state);
	std::thread t(my_func);
	try
	{
		do_something_in_current_thread();
	}
	catch(...)
	{
		t.join(); // 1
		throw;
	}
	t.join(); // 2
}


class thread_guard
{
	std::thread& t;
public:
	explicit thread_guard(std::thread& t_):
	t(t_)
	{}
	~thread_guard()
	{
		if(t.joinable()) // 1
		{
			t.join(); // 2
		}
	}
	thread_guard(thread_guard const&)=delete; // 3
	thread_guard& operator=(thread_guard const&)=delete;
};
struct func; // 定义在清单2.1中
void f()
{
	int some_local_state=0;
	func my_func(some_local_state);
	std::thread t(my_func);
	thread_guard g(t);
	do_something_in_current_thread();
} // 4
