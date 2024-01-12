# 2. Laboratorijas darbs - Saknes
Autors: Aleksejs Jakimovičs

Grupa: RECV0-1
## Mapes saturs
- [saknes.c](https://github.com/Aleksejs63/RTR105/blob/main/darbi/1ld_series/grafiks.c) -> Uzrakstītā programma
- [README.md](https://github.com/Aleksejs63/RTR105/blob/main/darbi/1ld_series/README.md) -> Laboratorijas darbu apraksošs dokuments, kurš satur sevī informāciju par uzrakstīto kodu.
- [roots.dat](https://github.com/Aleksejs63/RTR105/blob/main/darbi/2ld_roots/roots.dat) -> dat fails, kurš satur sakni no programmas un y = 0.
- [grafiks.gp](https://github.com/Aleksejs63/RTR105/blob/main/darbi/2ld_roots/grafiks.gp) -> Gnuplot skripts, kurš veido dotās funkcijas grafiku un punktu ar korrdinātēm no roots.dat faila.
- [grafiks.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/2ld_roots/grafiks.png) -> grafiks.gp skripta izveidotā grafika attēls.
- [kods.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/2ld_roots/kods.png) -> Koda darbības attēls.
## Apraksts

Šajā laboratorijas darbā tika uzrakstīta programma, kura atrod funkcijas saknes izmantojot dihotomijas metodi.

Dihotomijas metode ir veids ar kuru iespējams atrast konkrētā vienādojuma saknes, ja vienādojumam tās eksistē.

Šī metode apskata vai dotā intervāla galapunktos (piemēram a un b) mainās funkcijas zīme. Ja mainās, tad šajā intervālā sakne eksistē. Kad tiek konstatēts, ka sakne eksistē, tad var šo intervālu sadalīt uz pusēm un pārbaudīt kurā pusē atrodas sakne. Šo metodi var atkārot tik reizes cik vēlams, ar katru iterāciju iegūstot precīzāku saknes vērtību.

Metodes galvenais trūkums ir ka tā nespēj noteikt saknes, ja ir pāra sakņu skaits, jo funkcija pirms pirmās un pēc otrās saknes ir pozitīva.

## Programma

Programma sākas ar funkcijas izveidošanu, kura ļauj mums veikt pārbīdi pa y asi pēc nepieciešamība (piemēram, ja sākotnējā funkcija nekrusto x asi, tad pārbīdot to varam iegūt to, ka tā krustos x asi).

Dotā funkcija paņem kā argumentus x (funkcijas) vērtību un c (pārbīdes) vērtību. c vērtību ievada lietotājs un ja pārbīde nav nepieciešama, tad var ievadīt 0.

Main funkcijā tiek izveidoti float tipa mainīgie:
- a - intervāla sākumpunks;
- b - galapunks;
- c - pārbīde;
- x - saknes vērtība;
- delta_x - precizitāte; 
- func_a un func_b - funkcijas vērtības pie intervāla sākumpunkta un galapunkta.

Tiek arī izveidots int tipa mainīgais k, kurš norāda uz iterāciju skaitu.

Papildus tiek izveidots roots.dat fails, lai var iegūto sakni izvadīt gnuplot.

Pēc izveides programma lūdz lietotāju ievadīt a, b, c un delta_x vērtības.

Tad func_a un func_b tiek piešķirti dotās funkcijas lielumi respektīvi pie a un b.

Pēc tā ar nosacījuma operātoru if mēs pārbaudam vai funkcijas vērtības pie a un b reizinājums nav pozitīvs. Ja ir, tad programma izvada to, ka šajā intervālā sakņu nav vai to skaits ir pāra, pēc kā programma beidz savu darbību.

Ja tomēr reizinājums ir negatīvs, tad tas nozīmē, ka funkcijai dotajā intervālā [a:b] sakne pastāv, pēc kā tiek izprintētas funkcijas vērtības pie a un b.

Tālāk tiek pielietots while cikls, kas darbojas kamēr intervāls ir lielāks par norādīto precizitāti delta_x. Tajā mēs palielinam iterāciju skaitu k pa 1 vienību un piešķiram x vērtībai intervāla [a:b] viduspunkta vērtību. 

Tālāk tiek pārbaudīts vai funkcijas vērtība pie intervāla sākuma un viduspunka reizinājums ir lielāks par 0. Ja ir, tas nozīmē, ka saknes ir pa labi no intervāla viduspunkta (tuvāk pie b), kādā gadījumā a vērtībai tiks piešķirta viduspunkta vērtība x. 

Gadījumā ja sākuma un viduspunkta reizinājums ir mazāks par 0, tad intervāla kreizajā pusē (tuvāk pie a), kādā gadījumā b vērtībai tiks piešķirta viduspunkta vērtība x.

Pēc šī procesa tiek izprintēta iterācija, funkcijas vērtība pie sākumpunkta a, pie x un pie galapunkta b. 

Šis process atkārtojas līdz programma iziet no while cikla. Pēc tā Tiek izprintēta iegūtā saknes vērtība un funkcijas vērtība pie šīs saknes (jābūt ļoti tuvu 0).

Iegūto sakni ievada roots.dat failā un blakus pieliek 0 (tā būs y vērtība grafikā).

## Koda darbība un grafiks

Šeit var novērot programmas darbību intervālā no 1 līdz 5 bez pārbīdes, ar precizitāti 0.01.

![kods.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/2ld_roots/kods.png)

Iegūtā sakne pēc tā ievietojas roots.dat failā un fails tiek pieletots grafiks.gp skriptā, kurš izveido šo grafiku:


![grafiks.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/2ld_roots/grafiks.png)

X un Y intervāli izvēlēti ļoti mazi, lai var novērot saknes nobīdi no patiesās funkcijas vertības.

Var redzēt, ka metode ir ļoti precīza. Uzlabot rezultātu varētu ņemot vairāk ciparus aiz komata (šajā gadījumā bija tikai 3) vai iestādot lielāku precizitāti (šeit 0.01).  