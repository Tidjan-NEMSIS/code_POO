#ifndef LISTE_H
#define LISTE_H

#include <iostream>
#include <string>

using namespace std;

struct element {
    int cle;
    string valeur;
    element* suiv;
};

class Liste {
private:
    element* list;
public:
    Liste();
    ~Liste();
    Liste(const Liste& other); 
    void insertion(element e); 
    void supprimer(int cle);
    bool rechercher(int cle) const;
    Liste unir(const Liste& other);
    Liste intersection(const Liste& other);
    Liste difference(const Liste& other);
    void afficher() const;
    Liste& operator=(const Liste& other); 
};

#endif

