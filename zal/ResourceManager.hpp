#pragma once

#include "Resource.hpp"

class ResourceManager
{
  public:
    Resource* R;


    //Konstruktor domyslny
    ResourceManager(){};

/*
    //Konstruktor kopiujacy
    ResourceManager(const ResourceManager& RM)
    {
        R = new Resource[rozmiar];
        R = RM.R;
    }

    //kopiujacy opertor przypisania//
    ResourceManager& operator=(const ResourceManager&)
    {
    return *this;
    }

    //konstruktor przenoszacy//
    ResourceManager(ResourceManager&& RM)
    {
        R           = RM.R;
        RM.R         = nullptr;
        delete RM.R;
    }

    //przenoszacy operator przypisania//
    ResourceManager& operator=(ResourceManager&&)
    {
    R         = std::move(RM.R);
    return *this;
    }
    
    //destruktor//
    ~ResourceManager()
    {
        delete[] R;
    }
*/

    //Metoda get//
     double get(){return R.get()};
};


