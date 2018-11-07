《Cpp Concurrency In Action》

本书相关
github 翻译地址：https://github.com/xiaoweiChen/Cpp_Concurrency_In_Action
gitbook 在线阅读：http://chenxiaowei.gitbooks.io/cpp_concurrency_in_action/
书中源码：https://github.com/bsmr-c-cpp/Cpp-Concurrency-in-Action
学习C++11/14: http://www.bogotobogo.com/cplusplus/C11


学习博客：https://blog.csdn.net/column/details/ccia.html



##3.3 使用互斥量保护共享数据

#### C++11 std::unique_lock与std::lock_guard区别及多线程应用实例
https://blog.csdn.net/tgxallen/article/details/73522233
#### std :: defer_lock，std :: try_to_lock，std :: adopt_lock
它们用于为std :: lock_guard，std :: unique_lock 和std :: shared_lock指定锁定策略。
https://en.cppreference.com/w/cpp/thread/lock_tag



##4.1 等待一个事件或者其他条件
###4.2.2 std::packetask<>
std::packaged_task介绍及使用
https://blog.csdn.net/godmaycry/article/details/72868559

一、std::packaged_task简介
在上一篇，我们介绍了std::promise的使用方法，其实std::packaged_task和std::promise非常相似，简单来说std::packaged_task<F>是对std::promise<T= std::function<F>>中T= std::function<F>这一可调对象(如函数、lambda表达式等)进行了包装，简化了使用方法。并将这一可调对象的返回结果传递给关联的std::future对象。


###4.2.3 std::promise
std::promise介绍及使用
https://blog.csdn.net/godmaycry/article/details/72844159
std::promise是C++11并发编程中常用的一个类，常配合std::future使用。其作用是在一个线程t1中保存一个类型typename T的值，可供相绑定的std::future对象在另一线程t2中获取

promise是在一个线程设置数据，这个数据可以是一个任务，另外一个线程负责get_future获取数据，可以获取这个任务，但这个任务并没有执行过

paskeaged_task则传递的是一个任务，另外一个线程可以get_future直接过去任务的执行结果
