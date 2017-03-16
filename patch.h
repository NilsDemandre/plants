#ifndef PATCH_H_INCLUDED
#define PATCH_H_INCLUDED

#include <vector>
#include <array>

#include "individual.h"

/**
 * @file
 */


/**
 * @brief
 * Contient les caractéristiques d'un patch
 * et les méthodes nécessaires au fonctionnement
 * du modèle.
 */

class Patch
{
public:

    Patch(double p, int K, double sInit, double dInit);

    int K; /**< @brief La capacité d'accueil du patch */

    /** @brief Un vecteur qui contient tous les individus du patch */
    std::vector<Individual> population;

    /** @brief
     * Méthode qui détermine si le patch est pollinisé
     * en fonction de la probabilité qu'il le soit
     */
    void isPollenized(void);

    /** @brief
     * Méthode qui rassemble toutes les pression de propagule d'un type
     * donné (dispersantes ou résidentes) de tous les individus du patch
     *
     * @param delta         La dépression de consanguinité
     * @param c             Le coût de dispersion
     * @param dispNeeded    Si on souhaite les pressions dispersantes ou résidentes
     * @param press         Le vecteur de pression à remplir
     */
    void getPression(double delta, double c, bool dispNeeded, std::vector<double>& press);

    /**
      * @brief
      * Vector qui contient les pressions en graines dispersantes.
      * Cela permet de ne pas devoir les calculer 2 fois quand
      * on est au patch à gauche puis à droite.
      */
    std::vector<double> dispSeeds;

private:

    std::default_random_engine generator; /**< @brief Générateur de nombre aléatoire */

    double p; /**< @brief La probabilité d'être pollinisé */
    bool pollenized; /**< @brief L'état de pollinisation */
};

#endif // PATCH_H_INCLUDED
