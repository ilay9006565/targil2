#include "User.h"

void User::init(unsigned int id, std::string username, unsigned int age) 
{
    this->id = id;
    this->username = username;
    this->age = age;
}

void User::clear() 
{
    this->devicesList.clear();  
}

unsigned int User::getID() const 
{
    return id;
}

std::string User::getUserName() const 
{
    return username;
}

unsigned int User::getAge() const 
{
    return age;
}

DevicesList& User::getDevices() 
{
    return devicesList;
}

void User::addDevice(Device newDevice) 
{
    devicesList.add(newDevice);
}

bool User::checkIfDevicesAreOn() const
{
    DeviceNode* current = devicesList.get_first();
    while (current != NULL)
    {
        if (!current->get_data().isActive())
        {
            return false;
        }
        current = current->get_next();
    }
    return true;
}
