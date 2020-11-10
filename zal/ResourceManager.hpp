#pragma once

#include "Resource.hpp"

class ResourceManager
{
  public:
    Resource* R;

    //Konstruktor domyslny
    ResourceManager()
    {
      R= new Resource;
    };


    //Konstruktor kopiujacy
    ResourceManager(const ResourceManager& RM)
    {
        R = new Resource;
        R = RM.R;
    }

    //kopiujacy opertor przypisania
    ResourceManager& operator=(const ResourceManager&  RM)
    {

    if (this != &RM)
     {
        delete R;
        R = new Resource;
        R = RM.R;
      }
    return *this;

    }

    //konstruktor przenoszacy
    ResourceManager(ResourceManager&& RM)
    {
        R = new Resource;
        R           = RM.R;
        RM.R         = nullptr;
    }

    //przenoszacy operator przypisania
    ResourceManager& operator=(ResourceManager&& RM )
    {
        delete R;
        R=RM.R;
        RM.R = nullptr;
        return *this;
    }
    
    //destruktor
    ~ResourceManager()
    {
        delete R;
    }


    //Metoda get
     double get() {return R->get()};
};


