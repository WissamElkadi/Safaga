#pragma once

#include "DataStructure.h"

namespace Platform 
{ 
	namespace Render
	{
	    class Buffer
	    {
	    public:
	    	Buffer() = delete;
    
	    	Buffer(void** _content);
    
	    	void* data();
    
	    private:
	    	void* mContent;
	    };
    }
}
