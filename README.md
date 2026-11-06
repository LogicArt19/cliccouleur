# ClicCouleur

Petit programme Windows qui fait un clic gauche automatique quand le curseur passe sur une couleur choisie. Utile pour les tâches répétitives.

## Télécharger

Dernière version : [ClicCouleur.exe](https://github.com/LogicArt19/cliccouleur/releases/latest/download/ClicCouleur.exe)

Aucune installation, aucun AutoHotkey nécessaire.

## Utilisation

| Touche / bouton | Action |
|---|---|
| **F8** / « Choisir la couleur » | Fige l'écran : entoure une zone (ou clique sur un point) pour prendre sa couleur dominante. Échap ou clic droit pour annuler. |
| **F9** / « Activer / Désactiver » | Active ou désactive le clic automatique. |
| **F10** | Quitte le programme. |
| « Mettre à jour » | Télécharge et installe la dernière version publiée ici. |

- Se lance au démarrage de Windows, réduit et désactivé (désactivable dans Gestionnaire des tâches → Applications de démarrage).
- Ne clique jamais quand un jeu en ligne est au premier plan.

## Mises à jour

Chaque modification poussée sur la branche `main` est compilée automatiquement par GitHub Actions et publiée dans **Releases**. Le logiciel le signale au démarrage, et le bouton « Mettre à jour » l'installe.

Pour modifier les réglages (tolérance, délais), édite les lignes `#define` en haut de `src/cliccouleur.c`.

## Compiler soi-même (Linux)

```sh
sudo apt install clang lld llvm
./build.sh 1
```
