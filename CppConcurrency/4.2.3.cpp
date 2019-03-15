/*
 * 4.2.3.cpp
 *
 *  Created on: 2019��3��15��
 *      Author: lian.pengfei
 */




#include <future>
void process_connections(connection_set& connections)
{
    while(!done(connections)) // 1
    {
        for(connection_iterator connection=connections.begin(),end=connections.end(); // 2
                connection!=end;
                ++connection)
        {
            if(connection->has_incoming_data()) // 3
            {
                data_packet data=connection->incoming();
                std::promise<payload_type>& p =  connection->get_promise(data.id); // 4
                p.set_value(data.payload);
            }
            if(connection->has_outgoing_data()) // 5
            {
                outgoing_packet data =    connection->top_of_outgoing_queue();
                connection->send(data.payload);
                data.promise.set_value(true); // 6
            }
        }
    }
}
