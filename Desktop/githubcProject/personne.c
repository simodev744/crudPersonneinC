#include <stdio.h>

#define MAX_PERSONNES 10  


struct Adresse {
    char rue[100];
    char ville[50];
    int codePostal;
};


struct Personne {
    char nom[50];
    int age;
    struct Adresse adresse;
};


struct Personne personnes[MAX_PERSONNES];
int nombrePersonnes = 0;  


void ajouterPersonne() {
    if (nombrePersonnes >= MAX_PERSONNES) {
        printf("La limite du nombre de personnes a été atteinte.\n");
        return;
    }

    struct Personne p;
    printf("Entrez le nom de la personne : \n ");
    scanf("%s", p.nom);
    printf("Entrez l'âge de la personne : \n");
    scanf("%d", &p.age);
    printf("Entrez la rue de l'adresse : ");
    scanf("%s", p.adresse.rue);
    printf("Entrez la ville de l'adresse : ");
    scanf("%s", p.adresse.ville);
    printf("Entrez le code postal de l'adresse : ");
    scanf("%d", &p.adresse.codePostal);

    personnes[nombrePersonnes++] = p;
    printf("Personne ajoutée avec succès !\n");
}


void afficherPersonnes() {
    if (nombrePersonnes == 0) {
        printf("Aucune personne à afficher.\n");
        return;
    }

    for (int i = 0; i < nombrePersonnes; i++) {
        //struct Personne p = personnes[i];
        printf("\nPersonne %d:\n", i + 1);
        printf("Nom: %s\n", personnes[i].nom);
        printf("Âge: %d\n", personnes[i].age);
        printf("Adresse: %s, %s, %d\n", personnes[i].adresse.rue, personnes[i].adresse.ville, personnes[i].adresse.codePostal);
    }
}

// Fonction pour mettre à jour les informations d'une personne
void mettreAJourPersonne() {
    int index;
    printf("Entrez le numéro de la personne à mettre à jour (1 à %d) : ", nombrePersonnes);
    scanf("%d", &index);
    if (index < 1 || index > nombrePersonnes) {
        printf("Numéro de personne invalide.\n");
        return;
    }
    index--;
    struct Personne p = personnes[index];

    printf("Modifier le nom (actuel : %s) : ", p.nom);
    scanf("%s", p.nom);


    printf("Modifier l'âge (actuel : %d) : ", p.age);
    scanf("%d", &p.age);

    printf("Modifier la rue (actuelle : %s) : ", p.adresse.rue);
     scanf("%s", p.adresse.rue);

    printf("Modifier la ville (actuelle : %s) : ", p.adresse.ville);
      scanf("%s", p.adresse.ville);


    printf("Modifier le code postal (actuel : %d) : ", p.adresse.codePostal);
    scanf("%d", &p.adresse.codePostal);

     personnes[index] = p;
    printf("Personne mise à jour avec succès !\n");
}


void supprimerPersonne() {
    int index;
    printf("Entrez le numéro de la personne à supprimer (1 à %d) : ", nombrePersonnes);
    scanf("%d", &index);


    if (index < 1 || index > nombrePersonnes) {
        printf("Numéro de personne invalide.\n");
        return;
    }

    index--;  


    for (int i = index; i < nombrePersonnes - 1; i++) {
        personnes[i] = personnes[i + 1];
    }

    nombrePersonnes--;
    printf("Personne supprimée avec succès !\n");
}


void afficherMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Ajouter une personne\n");
    printf("2. Afficher toutes les personnes  \n");
    printf("3. Mettre à jour une personne \n");
    printf("4. Supprimer une personne \n");
    printf("5. Quitter \n");
    printf("Choisissez une option : ");
}

int main() {
    int choix;
    do {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterPersonne();
                break;
            case 2:
                afficherPersonnes();
                break;
            case 3:
                mettreAJourPersonne();
                break;
            case 4:
                supprimerPersonne();
                break;
            case 5:
                printf(" Exit !\n");
                break;
            default:
                printf("invalide. \n");
        }
    } while (choix != 5);

    return 0;
}

