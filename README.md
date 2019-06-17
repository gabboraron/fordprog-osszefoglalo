# Összefoglaló
## Mintanyelv - A beadandóhoz használandó programozási nyelv leírása (While, 2019 tavasz)

A félév során az alábbi programozási nyelvhez kell fordítóprogramot írni `flex` és `bisonc++` segítségével.
A nyelv az oktatási célokra gyakran felhasznált While nyelv egy változata.
Az alábbi példaprogram a bemeneten kapott nemnegatív egész szám legkisebb valódi osztóját számolja ki.

````While
program oszto
  natural a;
  natural i;
  natural oszto;
  boolean vanoszto;
begin
  read( a );
  vanoszto := false;
  i := 2;
  while not vanoszto and i < a do
    if a mod i = 0 then
      vanoszto := true;
      oszto := i;
    endif
    i := i+1;
  done
  if vanoszto then
    write( vanoszto );
    write( oszto );
  else
    write( vanoszto );
  endif
end
````

### A nyelv definíciója

#### Karakterek

A forrásfájlok a következő ASCII karaktereket tartalmazhatják:
- az angol abc kis és nagybetűi
- számjegyek (0-9)
- ():+-*<>=_;#
- szóköz, tab, sorvége
- megjegyzések belsejében pedig tetszőleges karakterek állhatnak

Minden más karakter esetén hibajelzést kell adnia a fordítónak, kivéve megjegyzések belsejében, mert ott tetszőleges karakter megengedett. A nyelv case-sensitive, azaz számít a kis és nagybetűk közötti különbség.

#### Kulcsszavak

A nyelv kulcsszavai a következők: `program`, `begin`, `end`, `natural`, `boolean`, `true`, `false`, `div`, `mod`, `and`, `or`, `not`, `skip`, `if`, `then`, `else`, `elseif`, `endif`, `while`, `do`, `done`, `read`, `write`

#### Azonosítók

A változók nevei betűkből, számjegyekből és _ jelből állhatnak, betűvel kell kezdődniük, és nem ütközhetnek egyik kulcsszóval sem.

#### Típusok

- `natural`: négy bájtos, előjel nélküli egészként kell megvalósítani; konstansai számjegyekből állnak és nincs előttük előjel
- `boolean`: egy bájton kell ábrázolni; értékei: false, true

#### Megjegyzések

A `#` karaktertől kezdve a következő `#` karakterig. Megjegyzések a program tetszőleges pontján előfordulhatnak, és tetszőleges számú sorra kiterjedhetnek. A fordítást és a keletkező programkódot nem befolyásolják.

#### A program felépítése

A program szignatúrából, deklarációs részből, törzsből és befejezésből áll. A szignatúra tartalma: `program`*név*, ahol a *név* tetszőleges azonosító. A szignatúrát a deklarációs rész követi, majd `begin` kulcsszó vezeti be a törzset. A deklarációs rész lehet üres is. A törzs legalább egy utasítást tartalmaz. A befejezést az `end` kulcsszó jelzi.

#### Változódeklarációk

Minden változót *típus név `;`* alakban kell deklarálni, több azonos típusú változó esetén mindegyiket külön-külön.

#### Kifejezések
- `natural` típusú kifejezések: számkonstansok, natural típusú változók és az ezekből a `+` (összedás), `-` (kivonás), `*` (szorzás), `div` (egészosztás), `mod` (maradékképzés) infix operátorokkal és zárójelekkel felépített kifejezések.
- `boolean` típusú kifejezések: `true` és `false`, `boolean` típusú változók, és két `natural` típusú kifejezésből az `=` (egyenlőség), `<` (kisebb), `>` (nagyobb) infix operátorral, valamint a boolean típusú kifejezésekből az `and` (konjunkció), `or` (diszjunkció), `=` (egyenlőség) infix és a `not` (negáció) prefix operátorral és zárójelekkel felépített kifejezések.
- Az infix operátorok mind balasszociatívak és a precedenciájuk növevő sorrendben a következő:
  - `and` `or`
  - `=`
  - `<` `>`
  - `+` `-`
  - `*` `div` `mod`
  
#### Utasítások

- `skip` utasítás: a változók értékeinek megváltoztatása nélküli továbblépés.
- Értékadás: az `:=` operátorral. Baloldalán egy változó, jobboldalán egy - a változóéval megegyező típusú - kifejezés állhat.
- Olvasás: A `read(`*változó*`);` utasítás a megadott változóba olvas be egy megfelelő típusú értéket a konzolról. (Megvalósítása: meg kell hívni a `be_egesz` (vagy a `be_logikai`) eljárást, amit a 4. beadandó leírásához mellékelt C fájl tartalmaz. A beolvasott érték natural típus esetén az `eax`, logikai típus esetén az `al` regiszterben lesz.)
- Írás: A `write(`*kifejezés*`);` utasítás a megadott kifejezés értékét a képernyőre írja (és egy sortöréssel fejezi be). (Megvalósítása: meg kell hívni a `ki_egesz` (vagy a `ki_logikai`) eljárást, amit a 4. beadandó leírásához mellékelt C fájl tartalmaz. Paraméterként a kiírandó értéket (mindkét esetben 4 bájtot) kell a verembe tenni.)
- While ciklus: `while`*feltétel*`do` *utasítások* `done` A feltétel logikai kifejezés, a ciklusmag legalább egy utasítást tartalmaz. A megszokott módon, elöltesztelős ciklusként működik.
- Elágazás: `if` *feltétel* `then` utasítások `elseif` *feltétel* `then` *utasítások* … `else` *utasítások* `endif` alakú. A feltételek logikai kifejezések, az ágak legalább egy utasítást tartalmaznak. Elseif ágból akárhány lehet (akár nulla is), az else ágból legfeljebb egy lehet, de el is hagyható. Az elágazások a megszokott módon működnek.

---

## 1 - lexikális
eredeti jegyzet: [gabboraron/fordprog-beadando1](https://github.com/gabboraron/fordprog-beadando1)

Flex segédanyag: [gabboraron/fordprog-1-flex](https://github.com/gabboraron/fordprog-1-flex)

mintakód: [1-lexikalis](https://github.com/gabboraron/fordprog-osszefoglalo/tree/master/1-lexikalis/1-lexikalis)

- Lexikális hiba észlelése esetén hibajelzést kell adni, ami tartalmazza a hiba sorának számát; ezután a program befejeződhet, nem kell folytatni az elemzést.
- Két fájlból álljon, egy *flex* és egy *c++* forrásfájlból. 
- Az elemzőprogram visszatérési értéke lexikálisan helyes program esetén *nulla*, egyébként *nullától különböző* legyen! Ezt figyeli az automatikus tesztelő!
  >  kulcsszo: if
  >
  >  valtozo: b
  >
  >  kulcsszo: then

## 2 - szintaktikai
eredeti jegyzet: [gabboraron/fordprog-beadando2](https://github.com/gabboraron/fordprog-beadando2)

mintakód: [2-szintaktikus] (https://github.com/gabboraron/fordprog-osszefoglalo/tree/master/2-szintaktikus/2-szintaktikus)

Bisonc++ segédanyag: [gabboraron/fordprog-2-bisoncpp](https://github.com/gabboraron/fordprog-2-bisoncpp)

- szintaktikus elemző elkészítése
- **szintaktikus hiba észlelése esetén** hibajelzést kell adni, és a fordítóprogram visszatérési értéke `1` legyen (azaz `exit(1)` utasítást kell végrehajtani a hibajelzés után)
- **ha a forrásfájl szintaktikusan helyes**, akkor a fordítóprogram visszatérési értéke legyen `0` (azaz return 0 utasítással fejeződjön be)
  >  ertekadas -> azonosito ERTEKADAS kifejezes PONTOSVESSZO
  >
  >  utasitas -> ertekadas
  >
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
