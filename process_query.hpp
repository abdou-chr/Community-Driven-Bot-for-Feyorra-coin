#include "functions.hpp"


std::string reply ;
json response ;
json reply_markup ; 

int process_query(std::string sender_message_text = "" , long int sender_chat_id = 0  , std::string sender_first_name = "" , long int sender_message_id = 0 ) {

	if (sender_message_text == "/about_feyorra" || sender_message_text == "/about_feyorra@FeyCoin_Bot" ){
		
		reply = "The FaucetPay team is thrilled to announce creating a utility token of our own. This is a very exciting moment for us since we worked actively for a year to develop and launch the token!We would like to present Feyorra (FEY).FEY will be the utility token for all projects associated with Basilisk Entertainment S.R.L. On top of that, it comes with several important DeFi features. Check more about feyorra  here :" ; 
	
	    json inline_keyboard_button ; 
	    
	    response["chat_id"] = sender_chat_id; 
    
        response["text"] = reply ; 
    
        inline_keyboard_button["text"] = "Feyorra"  ; 
    
        inline_keyboard_button["url"] = "https://feyorra.com/" ; 
    
        json inline_keyboard = json::array({json::array({inline_keyboard_button})});
    
        reply_markup["inline_keyboard"] = inline_keyboard ;  
    
        response["reply_markup"] = reply_markup ;
        
        response["reply_to_message_id"] = sender_message_id ;
         
		sendMessage( response  ) ; 		
	}
	
	else if (sender_message_text == "/exchanges" || sender_message_text == "/exchanges@FeyCoin_Bot"){
		
		reply = "You can trade Feyorra here:" ; 
		
	    response["chat_id"] = sender_chat_id; 
    
        response["text"] = reply ;
        
        json inline_keyboard_button1 ;
        
        json inline_keyboard_button2 ;
        
        json inline_keyboard_button3 ;
        
        inline_keyboard_button1["text"] = "UNISWAP"  ; 
    
        inline_keyboard_button1["url"] = "https://v2.info.uniswap.org/pair/0xb6e544c3e420154c2c663f14edad92737d7fbde5" ;
        
        inline_keyboard_button2["text"] = "FAUCETPAY SWAP"  ; 
    
        inline_keyboard_button2["url"] = "https://faucetpay.io/exchange" ;
        
        inline_keyboard_button3["text"] = "PASINO SWAP"  ; 
    
        inline_keyboard_button3["url"] = "https://pasino.com/page/wallet" ;
        
        json inline_keyboard = json::array({ {inline_keyboard_button1}, {inline_keyboard_button2} ,{inline_keyboard_button3} });
        
        reply_markup["inline_keyboard"] = inline_keyboard ;  
    
        response["reply_markup"] = reply_markup ;
        
        response["reply_to_message_id"] = sender_message_id ; 
        
		sendMessage( response  ) ; 	
	}
	
	else if (sender_message_text == "/stake" || sender_message_text == "/stake@FeyCoin_Bot"){
		
		reply = "There are several ways to stake Feyorra :" ; 
		
		response["chat_id"] = sender_chat_id; 
    
        response["text"] = reply ;
        
        json inline_keyboard_button1 ;
        
        json inline_keyboard_button2 ;
        
        json inline_keyboard_button3 ;
        
        inline_keyboard_button1["text"] = "Decentralized staking (INSTALL METAMASK)"  ; 
    
        inline_keyboard_button1["url"] = "https://dapp.feyorra.com/" ;
        
        inline_keyboard_button2["text"] = "Pooled staking"  ; 
    
        inline_keyboard_button2["url"] = "https://faucetpay.io/fey/pooled-staking" ;
        
        inline_keyboard_button3["text"] = "Help"  ; 
    
        inline_keyboard_button3["url"] = "https://feyorra.medium.com/how-to-view-your-feyorra-fey-tokens-in-metamask-19e4efda8231" ;
        
        json inline_keyboard = json::array({ {inline_keyboard_button1}, {inline_keyboard_button2} ,{inline_keyboard_button3} });
        
        reply_markup["inline_keyboard"] = inline_keyboard ;  
    
        response["reply_markup"] = reply_markup ;
        
        response["reply_to_message_id"] = sender_message_id ; 
         
		sendMessage( response  ) ; 
	}
	
	else if (sender_message_text == "/utility" || sender_message_text == "/utility@FeyCoin_Bot"){
		
		reply = "Verify your stakes at Pasino.com and earn a share of the house edge! Pasino pays out 0.1% of the total betting volume to all verified stakers. Payouts are made in over 10 different cryptocurrencies. House edge-sharing is your gateway to an additional passive income." ; 
		
		response["chat_id"] = sender_chat_id; 
    
        response["text"] = reply ;
        
        json inline_keyboard_button1 ;
        
        inline_keyboard_button1["url"] = "https://pasino.com/house-edge-sharing-feyorra" ;
        
        inline_keyboard_button1["text"] = "Pasino"  ;
        
        json inline_keyboard = json::array({json::array({inline_keyboard_button1})});
        
        reply_markup["inline_keyboard"] = inline_keyboard ;  
    
        response["reply_markup"] = reply_markup ;
        
        response["reply_to_message_id"] = sender_message_id ; 
         
		sendMessage( response  ) ; 
	}
	
	else if (sender_message_text == "/stats" ||sender_message_text == "/stats@FeyCoin_Bot"){
		
		reply = get_feyorra_data() ; 
		
		json inline_keyboard_button1 ;
        
        inline_keyboard_button1["callback_data"] = "1" ;
        
        inline_keyboard_button1["text"] = "Reload"  ;
        
        json inline_keyboard = json::array({json::array({inline_keyboard_button1})});
        
        reply_markup["inline_keyboard"] = inline_keyboard ;  
        
        json response ; 
        
        response["reply_markup"] = reply_markup ;
		
		response["chat_id"] = sender_chat_id; 
    
        response["text"] = reply ;
        
        response["parse_mode"] = "html" ; 
        
        response["reply_to_message_id"] = sender_message_id ; 
        
        sendMessage( response  ) ; 	
	}
	 
	else if (sender_message_text == "/start"){
		
		reply = "Welcome " + sender_first_name + " please chose from the list of commands to get started." ; 
		
		json response ; 
		
		response["chat_id"] = sender_chat_id; 
    
        response["text"] = reply ;
        
        sendMessage( response  ) ;    
        
        }
	
	return 0 ; 
}

int process_callback_query(std::string callback_query_id , std::string callback_query_data , long int callback_query_from_message_id , long int  callback_query_from_chat_id ){
	
	reply = "Success" ; 
	
	response["callback_query_id"] = callback_query_id ;
    
    response["text"] = reply ; 
	
	answerCallbackQuery(response ) ;
		
	reply = get_feyorra_data() ; 
		
	json inline_keyboard_button1 ;
        
    inline_keyboard_button1["callback_data"] = "1" ;
        
    inline_keyboard_button1["text"] = "Reload"  ;
        
    json inline_keyboard = json::array({json::array({inline_keyboard_button1})});
        
    reply_markup["inline_keyboard"] = inline_keyboard ;  
    
    response["reply_markup"] = reply_markup ;
     
    response["chat_id"] = callback_query_from_chat_id ; 
    
    response["message_id"] = callback_query_from_message_id ;
    
    response["text"] = reply ;
        
    response["parse_mode"] = "html" ; 
    
    editMessageText(response) ; 
	 
	return 0 ; 
		
}
	
	
	
	
	
	
	
