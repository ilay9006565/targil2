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

void Profile::changeWordInStatus(const std::string& word_to_replace, const std::string& new_word) 
{
    std::string status = page.getStatus();
    std::string updated_status;

    size_t i = 0;
    while (i < status.size()) 
    {
        bool match = true;
        for (size_t j = 0; j < word_to_replace.size(); ++j) 
        {
            if (i + j >= status.size() || status[i + j] != word_to_replace[j]) 
            {
                match = false;
                break;
            }
        }

        if (match && (i + word_to_replace.size() == status.size() || isspace(status[i + word_to_replace.size()]))) 
        {
            updated_status += new_word;
            i += word_to_replace.size(); 
        }
        else 
        {
            updated_status += status[i];
            i++;
        }
    }

    page.setStatus(updated_status); 
}

void Profile::changeAllWordsInStatus(const std::string& word) 
{
    std::string status = page.getStatus();
    std::string new_status;
    std::string whitespace = " \t\n";

    size_t i = 0;
    while (i < status.size()) 
    {
        while (i < status.size() && whitespace.find(status[i]) != std::string::npos) 
        {
            new_status += status[i];
            i++;
        }

        size_t start = i;
        while (i < status.size() && whitespace.find(status[i]) == std::string::npos) 
        {
            i++;
        }

        if (start < i) 
        {
            new_status += word;
        }
    }

    page.setStatus(new_status); 
}


