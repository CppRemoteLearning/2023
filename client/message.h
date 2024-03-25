#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <boost/archive/text_oarchive.hpp>

namespace smart_home_client
{
    
class Message
{
public:
    Message();
    Message(const std::string& text, const std::string& sender, const std::string& date);
    
    std::string text_;
    std::string sender_;
    std::string date_;
};

} // namespace smart_home_client

namespace boost{
    namespace serialization{
        template<class Archieve>
        void serialize(Archieve &a, smart_home_client::Message &m, const unsigned version)
        {
            a & m.sender_ & m.date_ & m.text_;
        }
    }
}



#endif