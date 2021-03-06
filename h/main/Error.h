#pragma once

#include "Token.h"

#include <string>
using std::string;

#define FUNC string(__FUNCTION__)

enum ErrorPriority {
	SOURCE_ERROR,
	SOURCE_WARNING,
	JSYK,
	INTERNAL_ERROR,
};

class ErrorHandler {
    public:
	    static string priorityToStr(ErrorPriority in);
	
	    void log(string msg, ErrorPriority priority, Token token = nullptr);
	
	    void msg(string in);
	
	    bool getIfErrorLogged() {
            return errorHasBeenLogged;
        }
	
    private:
	    bool errorHasBeenLogged = false;
};

extern ErrorHandler error;

class PercleError {
    public:
	    PercleError(string msgIn, ErrorPriority priorityIn, Token tokenIn=nullptr);
	
	void log();
	
    private:
	    string msg;
	    ErrorPriority priority;
	    Token token;
};
