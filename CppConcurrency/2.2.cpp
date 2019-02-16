void update_data_for_widget(widget_id w,widget_data& data); // 1
void oops_again(widget_id w)
{
	widget_data data;
	std::thread t(update_data_for_widget,w,data); // 2
	display_status();
	t.join();
	process_widget_data(data); // 3
}


class X
{
public:
	void do_lengthy_work();
};
X my_x;
std::thread t(&X::do_lengthy_work,&my_x); // 1





void process_big_object(std::unique_ptr<big_object>);
std::unique_ptr<big_object> p(new big_object);
p->prepare_data(42);
std::thread t(process_big_object,std::move(p));
