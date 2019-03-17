/*
 *
 * aa.cpp
 *
 *  Created on: 2019年3月13日
 *      Author: Administrator
 */



#include <deque>
#include <mutex>
#include <future>
#include <thread>
#include <utility>
std::mutex mget;
std::mutex mput;
/*遗留问题： 代码并无优化时间问题。
如果一个任务持续时间过长，并且是最后一个任务。
由于无法预估每个函数的执行时间。
 */
float work(float input);
std::map<int, float> result;

void thread_work()
{
	std::packaged_task<float()> task;
	{
		std::lock_guard<std::mutex> lk(mget);
		if(tasks.empty())
			return;
		task= tasks.pop();
	}
    auto futRe =  task.sencond.get_future();
	{
		std::lock_guard<std::mutex> lk(mput);
		result.insert( std::make_pair(task.first,futRe.get() ));
	}
}

int main()
{
	std::map<int,std::packaged_task<float()> > tasks;
	std::vector<float> inputs; 中已经有N个输入。
	std::vector<float> outputs ;为一个空数组用来存放输出

	int index=0;
	for(auto it : inputs)
	{
		auto func = std::bind(work, *it );
		std::packaged_task<float()> task(func);
		tasks.insert( std::make_pair(index++, task));
	}

	/*使用线程 集合 */
	std::thread t1(gui_thread);
	std::thread t2(gui_thread);
	std::thread t3(gui_thread);
	std::thread t4(gui_thread);


	t1.join();
	t2.join();
	t3.join();
	t4.join();

	for(auto it: result)
	{
		outputs.push(it.second);
	}
}

主要信息来源：《Cpp_Concurrency_In_Action 》中第4.2.2小结代码
