/*
 *
 * aa.cpp
 *
 *  Created on: 2019��3��13��
 *      Author: Administrator
 */



#include <deque>
#include <mutex>
#include <future>
#include <thread>
#include <utility>
std::mutex mget;
std::mutex mput;
/*�������⣺ ���벢���Ż�ʱ�����⡣
���һ���������ʱ����������������һ������
�����޷�Ԥ��ÿ��������ִ��ʱ�䡣
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
	std::vector<float> inputs; ���Ѿ���N�����롣
	std::vector<float> outputs ;Ϊһ������������������

	int index=0;
	for(auto it : inputs)
	{
		auto func = std::bind(work, *it );
		std::packaged_task<float()> task(func);
		tasks.insert( std::make_pair(index++, task));
	}

	/*ʹ���߳� ���� */
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

��Ҫ��Ϣ��Դ����Cpp_Concurrency_In_Action ���е�4.2.2С�����
