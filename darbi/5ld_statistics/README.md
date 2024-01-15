# 5. Laboratorijas darbs - Skaitļu kopas kārtošana un statistika
Autors: Aleksejs Jakimovičs

Grupa: RECV0-1
## Mapes saturs
- [bubble.c](https://github.com/Aleksejs63/RTR105/blob/main/darbi/5ld_statistics/bubble.c) -> Uzrakstītā programma
- [sort.gp](https://github.com/Aleksejs63/RTR105/blob/main/darbi/5ld_statistics/sort.gp) -> Gnuplot skripts, kurš izveido grafiks.png vadoties pēc sort.dat datu faila kur x ass ir burts un y ass ir tā parādīšanās biežums.
- [grafiks.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/5ld_statistics/grafiks.png) -> Gnuplotā izveidotais grafiks.
- [sortkods.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/5ld_statistics/sortkods.png) -> Koda darbības piemērs.
- [sort.dat](https://github.com/Aleksejs63/RTR105/blob/main/darbi/5ld_statistics/sort.dat) -> bubble.c izveidots datu fails, kurš satur vienā stabiņā ievadītos burtus un otrā to biežumu rindā.
- [README.md](https://github.com/Aleksejs63/RTR105/blob/main/darbi/5ld_statistics/README.md) -> Laboratorijas darbu apraksošs dokuments, kurš satur sevī informāciju par uzrakstīto kodu, pielietotām metodem un šīs mapes saturu.

## Apraksts

Šajā laboratorijas darbā tiek aplūkota skaitļu kopas kārtošanas metode ar nosaukumu bubble sort. Šī metode tiek izmantota, lai efektīvi sakārtot kādu skaiļu kopu. 

Šīs metodes darbības princips ir tāds, ka tiek paņemtas divas blakus esošās vērtības un tās tiek salīdzinātas savā starpā un mazākā vērtība tiek novietota pa labi vai pa kreisi atkarībā vai nepieciešams vērtības kārtot augošā vai dilstošā secībā. Ja vērtības vienādas, tad nekas netiek darīts.

Metode tiek atkārtota tik reizes, cik nepieciešams, lai sakārtotu visu kopu.

## Programma

Sākotnēji tiek izveidots mainīgais len ar vērtību 256, kas būs teksts masīva izmērs. Tad tiek izveidots masīvs teksts.

Pēc tā tiek palūgts, lai lietotājs ievada tekstu un ar fgets komandu, tad tiek ievietots masīvā teksts (netiek izmantots scanf, jo tad nebūtu iespējams likt atstarpes ievadītajā tekstā).

Tiek izveidots arī mainīgais spacecount, kurš skaita cik atstarpes lietotāja ievadītajā teksta rindā.

Tālāk for ciklā, kurš darbojas līdz mēs neizejam visu lietotāja ievadītās teksta rindas garumu, mēs pārbaudam vai ievadītā teksta rinda nesatur neatbilstošus simbolus (tie kuri nav angļu alfabētā un nav atstarpes).

Ja simbols ir atstarpe, tad mēs palielinam spacecount.

Tālāk tiek veikta rindas kārtošana, kur mēs katru burtu salīdzinam ar visiem pārējiem masīvā un, ja tas ir lielāks, tad mēs ieliekam tā burta vietā ar ko tas tiek salīdzināts. Lai to paveiktu pirms cikla tiek izveidots mainīgais bigger, kurš saglabās sevī lielāko vērtību no divām un tad vērtībai pa kreisi tieks piesaistīta mazākā vērtība un vērtībai pa labi tieks piesaistīta lielākā (bigger). Šo mēs atkārtojam, līdz nav iziets viss masīvs.

Pēc kārtošanas tiek izvadīts sakārtots teksts ar atstarpēm.

Tālāk tiek veikta atstarpju dzēšana, jo atstarpes traucē tālākām darbībām ar rindu (vidējā, mediānas iegūšana u.t.t.).

Tiek izveidots masīvs fixtext ar izmēru teksts masīva lielums mīnus atstarpju skaits spacecount. 


Tiek izveidots mainīgas a, lai aizpildītu fixtext masīvu. For ciklā mēs aizpildam fixtext masīvu pie mainīgā a ar burtiem no teksts masīva gadījumā, ja simbols teksts masīvā nav atstarpe un a tiek palielināts par 1. Pēc tā masīva fixtext beigās tiek pielikts simbols '\0', kurš apzīmē līnijas beigas (bez tā rodas kļūdas).

Pēc šī tiek izvadīts sakārots teksts bez atstarpēm.

Šajā brīdī sākas teksta statistiskā analīze.

Sākumā tiek iegūtas minimālās un maksimālās vērtības, kuras ir vienārši saraksta pirmā (nevis nultā, jo nultā ir jaunas līnijas simbols, jo tam ir vismazākā vērtības ASCII tabulā) un pēdējā vērtība.

Tālāk tiek iegūta vidējā vērtība ieviešot mainīgo sum (summa) un for ciklā pie sum vērtības liekot klāt visus teksta skaitļus.

Pēc tā summa tiek dalīta ar masīva elementu skaitu, tādā veidā iegūstot saraksta vidējo vērtību, kura tiek izvadīta kā simbols un blakus iekavās tā skaitliskā vērtība. Skaitlis tiek automātiski apaļots, jo tiek lietots int tipa mainīgais priekš vidējās vērtības vid.

Mediānas iegūšanai tiek izveidots mainīgais amount, kas parāda cik vērtības ir masīvā, pēc kā tiek aprēķināta mediāna (med) kā amount dalīts ar 2 plus 1 (plus 1, jo int apaļo uz apakšu un rezultāts savādāk ir nepareizs).

Tiek pārbaudīts vai elementu skaits ir pāra vai nepāra (jo mediānas šiem gadījumiem atšķiras). Ja dalījums nepāra, tad vienkārši tiek izprintēts burts, kurš ir masīvā pie indeksa med. Ja dalījums pāra tad printēti divi burti, viens pie indeksa med-1 un otrs pie med.

Pēdējais lielums, kuru nepieciešams iegūt ir moda. 

Tiek izveidoti masīvi chars un freq ar lielumu len. 
chars masīvs saturēs katru unikālu simbolu, kurš atrodas masīvā fixtext (izņemot pirmo, kurš ir jauna līnija).
freq masīvs atbilstoši saturēs katra chars masīva unikālā burta parādīšanās biežumu. Tā kā saraksts jau ir sakārtots, tad indeksi būs atbilstoši abiem sarakstiem (katra burta indekss atbildīs sava biežuma indeksam).

Papildus tiek izveidoti mainīgie max_moda, kas satur lielākās modas vērtību (sākumā 0) un modu_count (sākumā 1, jo vismaz viena moda masīvā būs).

a iestatam kā 0, lai varētu aizpildīt chars un freq masīvus.

chars pie a (0) tiek iestatīts kā fixtext pie 1 (jo 0. vērtīva kā jau minēts ir jauna līnija). Freq pie a iestatīts kā 0.

Tālāk for ciklā sākot ar i = 2 līdz fixtext masīva lielumu skaitam tiek pārbaudīts vai fixtext pie ir nav vienāds ar chars pie a (lai simboli neatkārtojas), pēc kā tiek pieskaitīts 1 pie a, lai turpinās chars aizpilde un chars tiek iestatīts kā fixtext pie 1. Visas freq saraksta vērtības pie a tiek iestatītas kā 0, lai tālāk nerastos klūdas.

Pēc tā tiek aizpildīts freq masīvs. Tiek iziets caur visu chars masīvu un pie katras chars vērtības tiek iziets caur visu fixtext masīvu, kur tiek pārbaudīts vai konkrētais simbols char masīvā pie indeksa j parādās fixtext masīvā un ja jā, tad pieskaita 1 pie frekvences masīva pie indeksa j.

Pēdējā darbība ir modas meklēšana biežuma masīvā freq.

Sākumā tiek izveidots masīvs moda_index, kurš glabās visu modu indeksus.

Tad for ciklā mēs iziejam caur visam freq sarakstam un ja vērtība tajā ir lielāka par max_moda (sākumā True, jo max_moda sākumā ir 0) un ja ir, tad max_moda tiek piešķirts lielums no freq pie indeksa j un masīva moda_index pirmajai vērtībai tiek piešķirts j.

Tālāk atkal tiek iziets masīvs freq un, ja vērtība tajā ir vienāda ar max_moda un indeksi nesakrīt (lai nav vienādi burti modu masīvā), tad tiek moda_index pie indeksa modu_count tiek piesaistīts i un tiek pieskaitīts 1 pie modu_count.

Tādā veidā tiek aizpildīts modu indeksu masīvs, kuru var izmantot, lai izvadītu vienu vai vairākas modas (ja ir vairākas).

Tālāk tiek veikta pārbaude vai ir viena vai vairākas modas un atbilstoši tiek veikta izvade. Tiek parādīta moda/-s burtu veidā, to ASCII vērtība un cik reizes tā/-s parādās.

Pēc tā arī izvada modu skaitu.

Programmas beigās dati tiek izvadīti sort.dat failā, kur pirmā rinda ir burts un frekvence (vārdiski uzrakstīts vieglākai pārlasei).

Tad for ciklā tiek failā ievadīti visi unikālie burti no chars masīva un blakus to parādīšanās biežums.

## Grafiki un attēli

Koda darbības piemērs:

![sortkods.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/5ld_statistics/sortkods.png)


Izvadītie faili tiek ar gnuplot skripta sort.gp palīdzību pārtaisiti stabiņu diagrammas veidā kur uz x ass attēlots burts un uz y to parādīšanās biežums.

Grafika piemērs:

![grafiks.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/5ld_statistics/grafiks.png)


