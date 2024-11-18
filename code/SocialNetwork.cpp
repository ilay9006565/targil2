#include "SocialNetwork.h"
#include "ProfileList.h"

void SocialNetwork::init(const std::string& networkName, int minAge) 
{
    this->networkName = networkName;
    this->minAge = minAge;
    this->profiles.init();
}

void SocialNetwork::clear() 
{
    this->profiles.clear();
}

std::string SocialNetwork::getNetworkName() const 
{
    return this->networkName;
}

int SocialNetwork::getMinAge() const 
{
    return this->minAge;
}

bool SocialNetwork::addProfile(const Profile& profile_to_add) 
{
    if (profile_to_add.getOwner().getAge() < this->minAge) 
    {
        return false;
    }
    return this->profiles.add(profile_to_add);
}
