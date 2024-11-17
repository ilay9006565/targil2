#pragma once
#include <string>

///////////////////////////////////////////////////////////
/*														 //
	Those definitions are used for tests,                //
	you can add your own, but please do not delete any.  //
*/														 //
enum DeviceType {PHONE, PC, LAPTOP, TABLET};		     //
													     //
#define UbuntuOS "UbuntuLinux"                           //						
#define RedHatOS "RedHatLinux"							 //
#define MacOS "MacOS"									 //
#define IOS "IOS"										 //
#define WINDOWS7 "Windows7"                              //
#define WINDOWS10 "Windows10"                            //
#define WINDOWS11 "Windows11"                            //
#define ANDROID "Android"                                //
													     //
/// ///////////////////////////////////////////////////////


class Device
{
private:
    unsigned int id;
    DeviceType type;
    std::string os;
    bool active;

public:
    
    Device() 
    {
        this->id=0;
        this->type=PHONE;
        this->os="Unknown";
        this->active=false;
    }

    // Init Function
    void init(unsigned int id, const DeviceType& type, const std::string& os) 
    {
        this->id = id;
        this->type = type;
        this->os = os;
        this->active = true; // A new device starts as active
    }

    // Getters
    unsigned int getID() const 
    {
        return id;
    }

    DeviceType getType() const 
    {
        return type;
    }

    const std::string& getOS() const 
    {
        return os;
    }

    bool isActive() const 
    {
        return active;
    }

    void activate() 
    {
        active = true;
    }

    void deactivate() 
    {
        active = false;
    }
};



