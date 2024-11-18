#pragma once
#include "ProfileList.h"
#include <string>

class SocialNetwork 
{

private:
    std::string networkName;
    int minAge;
    ProfileList profiles;

public:
    
    void init(const std::string& networkName, int minAge);

    void clear();

    // Getters
    std::string getNetworkName() const;
    int getMinAge() const;

    bool addProfile(const Profile& profile_to_add);

    std::string getWindowsDevices() const;

    
};
