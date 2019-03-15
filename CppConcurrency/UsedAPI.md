
#std::thread 

std::thread t(func);


#std::threard.detach()
#std::thread.join()


#std::thread::id()
#std::thread::get_id()


#std::mutex 互斥量
#std::recursive_mutex


#std::unqiue_lock 

#std::lock
可以锁住多个
std::lock(lhs.m,rhs.m); // 1
#std::unlock


#std::once_flag
#std::call_once

#std::condition_variable 
#std::condition_variable_any 

#std::async
#std::packaged_task 
#std::launch


# std::promise<T> 
## std::promise<T>.set_exception

#std::lock_guard<std::mutex>
		std::lock_guard<std::mutex> lock_a(lhs.m,std::adopt_lock);
		std::lock_guard<std::mutex> lock_b(rhs.m,std::adopt_lock);