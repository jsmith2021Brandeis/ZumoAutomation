/*Written by Jacob Smith for Brandeis Robotics club
	Keeps track of current time, can be used for intervals
	without delay statements
	March 15 2018
*/
#ifndef ESPServer_h
#define ESPServer_h
#ifdef ARDUINO_ESP8266_WEMOS_D1R1
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include<ESPServer.h>

class ESPServer{
	
	private:
	
		const char* ssid;
		const char* password;
		String title;
		//no spaces
		String* possibleCodes;
		int numCodes;
		WiFiServer server{80};
		
		// Variable to store the HTTP request
		String header;
		
		WiFiClient client;
		
		int displayWebsite () ;
		int displayBody() ;
		//keeps track of a specified interval, so a procedure can be performed every second for example
		void displayButtons();	
		//gets the command that was most recently called
		int getIndex();
		boolean hasLink(String url);

		void setupHeader();
		void styleButton() ;
	

	public:
		//creates a new ESPServer object
		void wifiConnect();
		ESPServer(String possibleOptions [],int numCodes);
		int runServer();
				
};
#else
	#warning This class doesn't work for your board
#endif
#endif