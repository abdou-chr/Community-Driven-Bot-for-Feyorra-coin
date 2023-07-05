#include <cpr/cpr.h>
#include "/home/abdo/Desktop/json/single_include/nlohmann/json.hpp" 
#include <iostream>
using json = nlohmann::json;

int sendMessage(json response  ) {
	
    cpr::Response r = cpr::Post(cpr::Url{"https://api.telegram.org/bot6262260391:AAFNePMkdwgmc9OXG9mfoZWOCr0aBm75Jfw/sendMessage"},
                   
                   cpr::Body{response.dump()},
                   
                   cpr::Header{{"Content-Type", "application/json"}});
                   
                   std::cout << r.text ; 
                                 
         return 0 ; 
}

int answerCallbackQuery(json response ) {
	
	
    cpr::Response r = cpr::Post(cpr::Url{"https://api.telegram.org/bot6262260391:AAFNePMkdwgmc9OXG9mfoZWOCr0aBm75Jfw/answerCallbackQuery"},
                   
                   cpr::Body{response.dump()},
                   
                   cpr::Header{{"Content-Type", "application/json"}});
                   
                   std::cout << r.text ; 
                   
         return 0 ; 
	
}

int editMessageText(json response) {
	
	  cpr::Response r = cpr::Post(cpr::Url{"https://api.telegram.org/bot6262260391:AAFNePMkdwgmc9OXG9mfoZWOCr0aBm75Jfw/editMessageText"},
                   
                   cpr::Body{response.dump()},
                   
                   cpr::Header{{"Content-Type", "application/json"}});
                   
                   std::cout << r.text ; 
         
         return 0 ; 
}

std::string get_feyorra_data() {
	
	cpr::Response buffer = cpr::Get(cpr::Url{"https://feyorra.com/data/statistics"});
		
	json Feyorra_data = json::parse(buffer.text);
		
	std::string usd_price = Feyorra_data["usd_price"] ; 
	
	std::string circulating_supply = Feyorra_data["circulating_supply"] ; 
	
	long int cirulating_supply_to_int = stoi(circulating_supply) ; 
	
	circulating_supply = std::to_string(cirulating_supply_to_int) ; 
		
	std::string total_supply = Feyorra_data["total_supply"] ;
	
	long int total_supply_to_int = stoi(total_supply) ; 
	
	total_supply = std::to_string(total_supply_to_int) ; 
		
	std::string apy = Feyorra_data["apy"] ;
		
	std::string total_staked_amount = Feyorra_data["total_staked_amount"] ;
	
	long int total_staked_amount_to_int = stoi(total_staked_amount) ; 
	
	total_staked_amount = std::to_string(total_staked_amount_to_int) ;
		
	std::string total_stakers = Feyorra_data["total_stakers"] ;
		
	return  "\U0001F4B2 USD-PRICE : " + usd_price +"\n" +  "\U0001F4A5TOTAL-SUPPLY : " + total_supply +"\n" + "\U0001F4CAAPY : " + apy + "\n" + "\U0001F512TOTAL-STAKED-AMOUNT : " + total_staked_amount + "\n" +"\U0001F513circulating supply : " + circulating_supply + "\n" + "\U0001F465TOTAL-STAKERS : " + total_stakers  + "." ; 
		
	}
        
