#include <stdio.h>
#include <stdbool.h>

// Fonction pour vérifier si un nombre est premier
bool est_premier(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// PGCD avec affichage des étapes (Euclide)
int pgcd_etapes(int a, int b) {
    printf("=== Étapes de l'algorithme d'Euclide ===\n");
    while (b != 0) {
        int r = a % b;
        printf("%d = %d * (%d) + %d\n", a, b, a / b, r);
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b;

    printf("Entrez deux nombres : ");
    scanf("%d %d", &a, &b);

    // Test des nombres premiers
    printf("\n=== Test de primalité ===\n");
    printf("%d est %s\n", a, est_premier(a) ? "premier" : "non premier");
    printf("%d est %s\n", b, est_premier(b) ? "premier" : "non premier");

    // Calcul PGCD
    int resultat = pgcd_etapes(a, b);

    // Affichage du PGCD
    printf("\nPGCD(%d, %d) = %d\n", a, b, resultat);

    // Test si le PGCD est premier
    printf("Le PGCD est %s\n", est_premier(resultat) ? "premier" : "non premier");

    return 0;
}
