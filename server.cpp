#include <iostream>
#include "parse_update.cpp"
#include <App.h>

using json = nlohmann::json;
 
#include <App.h>

/* Note that uWS::SSLApp({options}) is the same as uWS::App() when compiled without SSL support */

int main() {
	/* Chose a secret path to avoid fake updates*/
	
	uWS::SSLApp({
	  .key_file_name = "/path_to/YOURPRIVATE.key",
	  .cert_file_name = "/path_to/YOURPUBLIC.pem",
	  .passphrase = "1234"
	}).post("/secretpath", [](auto *res, auto */*req*/) {
	    res->end("200");
	     std::string buffer;
	    res->onData([res, buffer = std::move(buffer)](std::string_view data, bool last) mutable {
            /* * Mutate the captured data */
            
           buffer.append(data.data(), data.length());
              
           parse_update(buffer) ; 
                          
             /* When this socket dies (times out) it will RAII release everything */
     
        });
	}).listen(88, [](auto *listen_socket) {
	    if (listen_socket) {
			std::cout << "Listening on port " << 88 << std::endl;
	    }
	}).run();

	std::cout << "Failed to listen on port 88" << std::endl;
}
