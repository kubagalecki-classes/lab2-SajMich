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
    ResourceManager(const ResourceManager& RM) { R = new Resource(*(RM.R)); }

    //kopiujacy opertor przypisania
    ResourceManager& operator=(const ResourceManager&  RM)
    {

    if (this != &RM)
     {
            *R = *(RM.R);
      }
    return *this;

    }
    
    //konstruktor przenoszacy
    ResourceManager(ResourceManager&& RM) : R(RM.R)
    {
        RM.R         = nullptr;
    }

    //przenoszacy operator przypisania
    ResourceManager& operator=(ResourceManager&& RM )
    {
        if (&RM == this)
            return *this;
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
    double get() { return R->get(); };  
};


