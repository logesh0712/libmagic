#include <iostream>
#include "header.h"
//#include "libmagic/magic.h"
#include "/Users/logesh/Development/libmagic/install/libmagic/include/magic.h"
#include <fcntl.h>
#include <unistd.h>

using namespace std;

template<typename T>
class Logger
{
    public:
    static void log(std::string message, T value)
    {
        std::cout << message << value << std::endl;
    }
};


template<typename T> 
void print(T input)
{
    std::cout << input << std::endl;
}

class A 
{
bool loaded;
public:
    A()
    {
        loaded = true;
    }

    operator bool()
    {
        std::cout << "I am in bool operator" << std::endl;
        return true;
    }

    operator int()
    {
        std::cout << "I am in int operator" << std::endl;
        return 4;
    }
};

std::string abcd()
{
    std::string ret="dfasdfadsf";
    return ret;
}

void print_stuffs()
{
    //static_test obj;
    //std::cout << "print_stuff:: " << obj.get_str() << std::endl;
}

void handle_magic_fd()
{
    int fd = open("/Users/logesh/Development/test/header.h",O_RDONLY);

    if(fd < 0)
    {
        cout << "Error: issue opening file\n";
        return;
    }
    //MAGIC_NONE
    //MAGIC_CONTINUE|MAGIC_ERROR|MAGIC_MIME
    magic_set *myt = magic_open(MAGIC_CONTINUE|MAGIC_ERROR|MAGIC_MIME);

    if(myt)
    {
        int ret_val = magic_load(myt,NULL);

        if(magic_load(myt,NULL) < 0)
        {    
            std::string m_magic_output = magic_descriptor(myt, fd);

            //std::cout << "File input is:\n" << m_magic_output.c_str() << std::endl;

            magic_close(myt);
        }
        else
        {
            magic_close(myt);
            std::cout << "Magic lib not loaded\n";
        }
    }
    else
    {
        std::cout << "Failed to create magic lib handle\n";
    }
}

void handle_magic_stuff()
{
    ///Users/logesh/Development/test/header.h
    //header.cpp
    std::string file_path = "/Users/logesh/Development/test/header.h";

    //MAGIC_NONE
    //MAGIC_CONTINUE|MAGIC_ERROR|MAGIC_MIME
    magic_t m_handle = magic_open(MAGIC_NONE);

    if(m_handle)
    {
        int ret_val = magic_load(m_handle, NULL);

        std::cout << "magic_load return value is " << ret_val << std::endl;

        if(ret_val >= 0)
        {
            const char* output = magic_file(m_handle, file_path.c_str());

            std::cout << "File input is:\n" << output << std::endl;

            magic_close(m_handle);
        }
        else
        {
            magic_close(m_handle);
            std::cout << "Magic lib not loaded\n";
        }
    }
    else
    {
        std::cout << "Failed to create magic lib handle\n";
    }
}

int main()
{
    handle_magic_stuff();
    //handle_magic_fd();
    //std::cout << "Enter the file path\n";


    

    //print_stuffs();


    #if 0
    A obj;

    std::cout << "finished calling constructor" << std::endl;

    if(obj)
    {
        std::cout << "wow loaded" << std::endl;
    }

    if(4 == (int)obj)
    {
        std::cout << "int comparison worked" << std::endl;
    }

    

    //print<std::string>("Hello!");
    //Logger logger;
    Logger<int>::log("There is a error. errorcode : ", 4);
    Logger<std::string>::log("There is a error. errormessage : ", "this sucks");

    //print<int>(2);

    #endif




}
