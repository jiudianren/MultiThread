��Cpp Concurrency In Action��

�������
github �����ַ��https://github.com/xiaoweiChen/Cpp_Concurrency_In_Action
gitbook �����Ķ���http://chenxiaowei.gitbooks.io/cpp_concurrency_in_action/
����Դ�룺https://github.com/bsmr-c-cpp/Cpp-Concurrency-in-Action
ѧϰC++11/14: http://www.bogotobogo.com/cplusplus/C11


ѧϰ���ͣ�https://blog.csdn.net/column/details/ccia.html



##3.3 ʹ�û�����������������

#### C++11 std::unique_lock��std::lock_guard���𼰶��߳�Ӧ��ʵ��
https://blog.csdn.net/tgxallen/article/details/73522233
#### std :: defer_lock��std :: try_to_lock��std :: adopt_lock
��������Ϊstd :: lock_guard��std :: unique_lock ��std :: shared_lockָ���������ԡ�
https://en.cppreference.com/w/cpp/thread/lock_tag



##4.1 �ȴ�һ���¼�������������
###4.2.2 std::packetask<>
std::packaged_task���ܼ�ʹ��
https://blog.csdn.net/godmaycry/article/details/72868559

һ��std::packaged_task���
����һƪ�����ǽ�����std::promise��ʹ�÷�������ʵstd::packaged_task��std::promise�ǳ����ƣ�����˵std::packaged_task<F>�Ƕ�std::promise<T= std::function<F>>��T= std::function<F>��һ�ɵ�����(�纯����lambda���ʽ��)�����˰�װ������ʹ�÷�����������һ�ɵ�����ķ��ؽ�����ݸ�������std::future����


###4.2.3 std::promise
std::promise���ܼ�ʹ��
https://blog.csdn.net/godmaycry/article/details/72844159
std::promise��C++11��������г��õ�һ���࣬�����std::futureʹ�á�����������һ���߳�t1�б���һ������typename T��ֵ���ɹ���󶨵�std::future��������һ�߳�t2�л�ȡ

promise����һ���߳��������ݣ�������ݿ�����һ����������һ���̸߳���get_future��ȡ���ݣ����Ի�ȡ������񣬵��������û��ִ�й�

paskeaged_task�򴫵ݵ���һ����������һ���߳̿���get_futureֱ�ӹ�ȥ�����ִ�н��
