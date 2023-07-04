#include <cpr/cpr.h>
#include <iostream> 

#include "/root/json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;

int sendMessage(json response  ) {
	
	/*
	 * make sure to replace secret with your bot token */
	 
    cpr::Response r = cpr::Post(cpr::Url{"https://api.telegram.org/botsecret/sendMessage"},
                   
                   cpr::Body{response.dump()},
                   
                   cpr::Header{{"Content-Type", "application/json"}});
                   
                   std::cout << r.text << std::endl;
                   
         return 0 ; 
}

int answerCallbackQuery(json response ) {
	
	
    cpr::Response r = cpr::Post(cpr::Url{"https://api.telegram.org/botsecret/answerCallbackQuery"},
                   
                   cpr::Body{response.dump()},
                   
                   cpr::Header{{"Content-Type", "application/json"}});
                   
                   std::cout << r.text << std::endl;
                   
         return 0 ; 
	
}

int editMessageText(json response) {
	
	  cpr::Response r = cpr::Post(cpr::Url{"https://api.telegram.org/botsecret/editMessageText"},
                   
                   cpr::Body{response.dump()},
                   
                   cpr::Header{{"Content-Type", "application/json"}});
                   
                   std::cout << r.text << std::endl;
                   
         return 0 ; 

}
        

