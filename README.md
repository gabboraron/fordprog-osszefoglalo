# Összefoglaló
## 1 - lexikális
eredeti jegyzet: [gabboraron/fordprog-beadando1](https://github.com/gabboraron/fordprog-beadando1)
Flex segédanyag: [gabboraron/fordprog-1-flex](https://github.com/gabboraron/fordprog-1-flex)
mintakód: [1-lexikalis](https://github.com/gabboraron/fordprog-osszefoglalo/tree/master/1-lexikalis/1-lexikalis)

- Lexikális hiba észlelése esetén hibajelzést kell adni, ami tartalmazza a hiba sorának számát; ezután a program befejeződhet, nem kell folytatni az elemzést.
- Két fájlból álljon, egy *flex* és egy *c++* forrásfájlból. 
- Az elemzőprogram visszatérési értéke lexikálisan helyes program esetén *nulla*, egyébként *nullától különböző* legyen! Ezt figyeli az automatikus tesztelő!
  >  kulcsszo: if
  >  valtozo: b
  >  kulcsszo: then

## 2 - szintaktikai
eredeti jegyzet: [gabboraron/fordprog-beadando2](https://github.com/gabboraron/fordprog-beadando2)
mintakód: [2-szintaktikus] (https://github.com/gabboraron/fordprog-osszefoglalo/tree/master/2-szintaktikus/2-szintaktikus)
Bisonc++ segédanyag: [gabboraron/fordprog-2-bisoncpp](https://github.com/gabboraron/fordprog-2-bisoncpp)

- szintaktikus elemző elkészítése
- **szintaktikus hiba észlelése esetén** hibajelzést kell adni, és a fordítóprogram visszatérési értéke `1` legyen (azaz `exit(1)` utasítást kell végrehajtani a hibajelzés után)
- **ha a forrásfájl szintaktikusan helyes**, akkor a fordítóprogram visszatérési értéke legyen `0` (azaz return 0 utasítással fejeződjön be)
  >  ertekadas -> azonosito ERTEKADAS kifejezes PONTOSVESSZO
  >  utasitas -> ertekadas
  >  ...
  
## 3 - szemantikus
mintakód: [3-szemantikus](https://github.com/gabboraron/fordprog-osszefoglalo/tree/master/3-szemantikus/3-szemantikus)
segédanyag: [deva/szemantikus](http://deva.web.elte.hu/szemantikus.hu.html)
példakód: [szemantikus-pelda](https://github.com/gabboraron/fordprog-osszefoglalo/tree/master/szemantikus-pelda)

- szemantikus elemző elkészítése
- flex, bisonc++ és C++ segítségével
- **hiba észlelése esetén** hibajelzést kell adni, és a fordítóprogram visszatérési értéke `1` legyen (azaz exit(1) utasítást kell végrehajtani a hibajelzés után)
- **ha a forrásfájl helyes**, akkor a fordítóprogram visszatérési értéke legyen `0` (azaz return 0 utasítással fejeződjön be)

## 4 - kódgenerátor
mintakód: [4-kodgen](https://github.com/gabboraron/fordprog-osszefoglalo/tree/master/4-kodgen/4-kodgen)
példakód: [kodgen-pelda](https://github.com/gabboraron/fordprog-osszefoglalo/tree/master/kodgen-pelda)
- kódgenerátor készítése
- flex, bisonc++ és C++ segítségével
- **hiba észlelése esetén** hibajelzést kell adni, és a fordítóprogram visszatérési értéke `1` legyen
- **ha a forrásfájl helyes**, akkor a fordítóprogram fordítsa le a forrásfájlt `NASM assembly`-re, és írja azt a standard output-ra, majd `0` visszatérési értékkel fejeződjön be
- Egész számok és **logikai értékek beolvasására, kiírására** használhatóak a `be_egesz`, `ki_egesz` stb. függvények az [io.c](https://github.com/gabboraron/fordprog-osszefoglalo/blob/master/kodgen-pelda/io.c) fájlból. 
