#include "liste.h"

int main() {
    Liste l1;
    element e1 = {1, "valeur1", nullptr};
    element e2 = {2, "valeur2", nullptr};
    element e3 = {3, "valeur3", nullptr};

    l1.insertion(e1);
    l1.insertion(e2);
    l1.insertion(e3);

    cout << "Liste l1 après insertion:" << endl;
    l1.afficher();

    Liste l2(l1); 

    cout << "Liste l2 après copie de l1:" << endl;
    l2.afficher();

    return 0;
}
