#include "process_query.hpp"

int parse_update(std::string buffer) {
	
	json webhook_update_json = json::parse(buffer);
	
	bool sender_message_text_is_null = webhook_update_json["message"]["text"].is_null()  ; 
	
	bool callback_data_is_null = webhook_update_json["callback_query"].is_null() ; 
	
	if ( sender_message_text_is_null == false ){ 
	
	std::string sender_message_text = webhook_update_json["message"]["text"]  ;
	
	long int  sender_chat_id = webhook_update_json["message"]["chat"]["id"]  ;
	
	long int sender_message_id = webhook_update_json["message"]["message_id"] ; 
	
	std::string sender_first_name =  webhook_update_json["message"]["from"]["first_name"] ; 
	
	process_query(sender_message_text , sender_chat_id , sender_first_name , sender_message_id ) ; 
	
	}
	
	else if ( callback_data_is_null == false ){
	
	std::string callback_query_data = webhook_update_json["callback_query"]["data"] ; 
	
	std::string callback_query_id =  webhook_update_json["callback_query"]["id"] ; 
	
	long int callback_query_from_message_id = webhook_update_json["callback_query"]["message"]["message_id"] ; 
	
	long int callback_query_from_chat_id = webhook_update_json["callback_query"]["message"]["chat"]["id"] ;
	
	process_callback_query(callback_query_id , callback_query_data , callback_query_from_message_id , callback_query_from_chat_id ) ; 
	 
	}
	

	return 0 ; 
	
} 
	 
	
	
	
	
