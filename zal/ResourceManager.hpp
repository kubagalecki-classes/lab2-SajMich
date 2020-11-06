#pragma once

#include "Resource.hpp"

class ResourceManager
{
  public:
    rozmiar sizeof(Resource);
    Resource* R;


    //Konstruktor kopiujacy
    ResourceManager(const ResourceManager& RM)
    {
        R = new Resource[rozmiar];
        R = RM.R;
    }

    //kopiujacy opertor przypisania//
    ResourceManager& operator=(const ResourceManager&);

    //konstruktor przenoszacy//
    ResourceManager(ResourceManager&& RM)
    {
        R           = RM.R;
        RM.R         = nullptr;
    }

    //przenoszacy operator przypisania//
    ResourceManager& operator=(ResourceManager&&);
    
    //destruktor//
    ~ResourceManager()
    {
        delete[] R;
    }

    //Metoda get//
     double get(){return R.get()};
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
    return *this;
}

