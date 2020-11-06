#pragma once

#include "Resource.hpp"

class ResourceManager
{
  public:
    Resource* R;

    double get(){return R.get()};


    //Konstruktor kopiujacy
    ResourceManager(const ResourceManager& RM)
    {
        R = new Resource;
        R = RM.R;
    }
    //kopiujacy opertor przypisania

    ResourceManager& operator=(const ResourceManager&);

    //konstruktor przenoszacy
    ResourceManager(ResourceManager&& RM)
    {
        R           = RM.R;
        RM.R         = nullptr;
    }

    //przenoszacy operator przypisania
    ResourceManager& operator=(ResourceManager&&);
    
    //destruktor
    ~ResourceManager()
    {
        delete[] R;
    }
};

//kopiujacy operator przypisania
ResourceManager& ResourceManager::operator=(const ResourceManager& RM)
{
    if (this != &RM) {
        delete R;

        R         = new Resource;
        R=RM;

    }
    return *this;
}


//przenoszacy operator przypisania
ResourceManager& ResourceManager::operator=(ResourceManager&& RM)
{
    R         = std::move(RM.R);
}

