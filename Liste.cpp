#include "liste.h"

Liste::Liste() {
    list = nullptr; 
    cout << "Construction à l'adresse: " << this << endl;
}

Liste::~Liste() {
    element* temp;
    while (list != nullptr) {
        temp = list;
        list = list->suiv;
        delete temp;
    }
    cout << "Destruction à l'adresse: " << this << endl;
}


Liste::Liste(const Liste& other) {
    if (other.list == nullptr) {
        list = nullptr;
    } else {
        list = new element;
        list->cle = other.list->cle;
        list->valeur = other.list->valeur;
        list->suiv = nullptr;

        element* courantOther = other.list->suiv;
        element* courant = list;

        while (courantOther != nullptr) {
            courant->suiv = new element;
            courant = courant->suiv;
            courant->cle = courantOther->cle;
            courant->valeur = courantOther->valeur;
            courant->suiv = nullptr;
            courantOther = courantOther->suiv;
        }
    }
}


void Liste::insertion(element e) {
    element* newElement = new element;
    newElement->cle = e.cle;
    newElement->valeur = e.valeur;
    newElement->suiv = nullptr;

    if (list == nullptr) {
        list = newElement;
    } else {
        element* courant = list;
        while (courant->suiv != nullptr) {
            courant = courant->suiv;
        }
        courant->suiv = newElement;
    }
}

void Liste::supprimer(int cle) {
    element* courant = list;
    element* precedent = nullptr;

    while (courant != nullptr && courant->cle != cle) {
        precedent = courant;
        courant = courant->suiv;
    }

    if (courant) {
        if (precedent == nullptr) {
            list = courant->suiv;
        } else {
            precedent->suiv = courant->suiv;
        }
        delete courant;
    } else {
        cout << "Element non trouvé" << endl;
    }
}

bool Liste::rechercher(int cle) const {
    element* courant = list;
    while (courant != nullptr && courant->cle != cle)
        courant = courant->suiv;
    return courant != nullptr;
}

Liste Liste::unir(const Liste& other) {
    Liste result = *this;
    element* courantOther = other.list;

    while (courantOther != nullptr) {
        if (!result.rechercher(courantOther->cle)) {
            result.insertion(*courantOther);
        }
        courantOther = courantOther->suiv;
    }

    return result;
}

Liste Liste::intersection(const Liste& other) {
    Liste result;
    element* courant = list;

    while (courant != nullptr) {
        if (other.rechercher(courant->cle)) {
            result.insertion(*courant);
        }
        courant = courant->suiv;
    }

    return result;
}

Liste Liste::difference(const Liste& other) {
    Liste result;
    element* courant = list;

    while (courant != nullptr) {
        if (!other.rechercher(courant->cle)) {
            result.insertion(*courant);
        }
        courant = courant->suiv;
    }

    return result;
}

void Liste::afficher() const {
    element* c = list;
    while (c != nullptr) {
        cout << c->cle << " -> " << c->valeur << endl;
        c = c->suiv;
    }
}

Liste& Liste::operator=(const Liste& other) {
    if (this != &other) {
        element* temp;
        while (list != nullptr) {
            temp = list;
            list = list->suiv;
            delete temp;
        }

        list = nullptr;
        element* courantOther = other.list;

        while (courantOther != nullptr) {
            insertion(*courantOther);
            courantOther = courantOther->suiv;
        }
    }
    return *this;
}
