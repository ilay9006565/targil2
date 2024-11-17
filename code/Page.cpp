#include "Page.h"

void Page::init() 
{
    this->status = "";
    this->posts = "";
}

std::string Page::getPosts() const 
{
    return posts;
}

std::string Page::getStatus() const 
{
    return status;
}

void Page::setStatus(const std::string& new_status) 
{
    status = new_status;
}

void Page::addLineToPosts(const std::string& new_line) 
{
    if (posts.empty()) 
    {
        posts = new_line;
    }
    else 
    {
        posts += "\n" + new_line;  
    }
}

void Page::clearPosts() 
{
    posts = "";
}
