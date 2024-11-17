#include "Profile.h"

void Profile::init(User owner) 
{
    this->owner = owner;
    this->page.init(); 
}

void Profile::clear() 
{
    this->owner.clear();   
    this->page.clearPosts(); 
    this->friends.clear(); 
}

User Profile::getOwner() const 
{
    return owner;
}

void Profile::setStatus(const std::string& new_status) 
{
    page.setStatus(new_status);
}

void Profile::addPostToProfilePage(const std::string& post) 
{
    page.addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add) 
{
    friends.add(friend_to_add);
}

std::string Profile::getPage() const 
{
    std::string result = "Status: " + page.getStatus() + "\n*******************\n";
    result += page.getPosts();
    return result;
}

std::string Profile::getFriends() const
{
    std::string result = "";
    UserNode* current = friends.get_first();  // שימוש ב-UserNode ולא ב-DeviceNode
    while (current != NULL)
    {
        if (!result.empty())
        {
            result += ",";
        }
        result += current->get_data().getUserName();  // גישה למתודה getUserName מתוך User
        current = current->get_next();
    }
    return result;
}

std::string Profile::getFriendsWithSameNameLength() const
{
    std::string result = "";
    UserNode* current = friends.get_first();  // שימוש ב-UserNode ולא ב-DeviceNode
    while (current != NULL)
    {
        if (current->get_data().getUserName().length() == owner.getUserName().length())
        {
            if (!result.empty())
            {
                result += ",";
            }
            result += current->get_data().getUserName();
        }
        current = current->get_next();
    }
    return result;
}

