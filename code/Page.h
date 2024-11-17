#pragma once
#include <string>

class Page
{

private:
    std::string status;
    std::string posts;


public:
    void init();

    std::string getPosts() const;

    std::string getStatus() const;

    void setStatus(const std::string& status);

    void addLineToPosts(const std::string& new_line);

    void clearPosts();
};