/*
 * 4.2.2.cpp
 *
 *  Created on: 2019年3月14日
 *      Author: lian.pengfei
 */




#include <deque>
#include <mutex>
#include <future>
#include <thread>
#include <utility>
std::mutex m;
std::deque<std::packaged_task<void()> > tasks;
bool gui_shutdown_message_received();
void get_and_process_gui_message();


void gui_thread() // 1
{
    while(!gui_shutdown_message_received()) // 2
    {
        get_and_process_gui_message(); // 3
        std::packaged_task<void()> task;
        {
            std::lock_guard<std::mutex> lk(m);
            if(tasks.empty()) // 4
                continue;
            task=std::move(tasks.front()); // 5
            tasks.pop_front();
        }
        task(); // 6  并无返回值 哈哈，之前写错了，如果想获得其返回值，需要通过future
    }
}
std::thread gui_bg_thread(gui_thread);
template<typename Func>
std::future<void> post_task_for_gui_thread(Func f)
{
    std::packaged_task<void()> task(f); // 7
    std::future<void> res=task.get_future(); // 8
    std::lock_guard<std::mutex> lk(m); // 9
    tasks.push_back(std::move(task)); // 10
    return res;
}
