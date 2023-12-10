# 1. Laboratorijas darbs - Teilora rindas
Autors: Aleksejs Jakimovičs

Grupa: RECV0-1
## Mapes saturs
- [atvasinajums.c](https://github.com/Aleksejs63/RTR105/blob/main/darbi/3ld_derivative/atvasinajums.c) -> Uzrakstītā programma
- [derivative.gp](https://github.com/Aleksejs63/RTR105/blob/main/darbi/3ld_derivative/derivative.gp) -> Gnuplot skripts, kurš izveido derivative.png izmantojot datus no derivative.dat faila, kuru izveidoja atvasinajums.c programma. 
- [derivative.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/3ld_derivative/derivative.png) -> Gnuplotā izveidotais grafiks, kurš satur pašu funkciju cos(sqrt(x)) un tās pirmās un otrās kārtas atvasinājumu pēc forward difference metodes.
- [README.md](https://github.com/Aleksejs63/RTR105/blob/main/darbi/3ld_derivative/README.md) -> Laboratorijas darbu apraksošs dokuments, kurš satur sevī informāciju par uzrakstīto kodu, pielietotām metodem un šīs mapes saturu.
- [derivative.dat](https://github.com/Aleksejs63/RTR105/blob/main/darbi/3ld_derivative/derivative.dat) -> Satur no atvasinajums.c iegūtās vērtības tabulas veidā, tas ir, cos(sqrt(x)) analītisko grafiku kā arī to pirmās un otrās kārtas atvasinājumu pēc forward difference metodes un arī pirmās un otrās kārtas atvasinājumu pēc analītiskās formulas.
## Apraksts

Šajā laboratorijas darbā tika izpētītas metodes kā var implementēt funkciju atvasināšanu C valodā. 

Tā kā datoriem ir ierobežots resursu skaits, lai veiktu tādu darbību kā atvasināšana ir nepieciešams izmantot metodi, kura tuvinās patiesai vērtības(līdzīgi kā teilora rindās).

Viena no šādām metodēm ir finite difference, jeb galīgā starpība, kur no funkcijas vērtība pie lielāka argumenta tiek atņemta funkcijas vērtība pie mazāka argumenta un 
rezultāts tiek dalīts ar lielāka un mazāka argumenta starpību.

Parasti tiek izmantota viena no trim galvenajām finite difference metodēm: forward difference, backward difference un central difference. Visas šīs metodes balstās uz iepriekš minētā principa, bet katra to implementē savādāk. Šajā laborotorijas darbā tika izskatīta un pielietota tikai forward difference metode, kura iekļauj sevī funkcijas pie nākoša argumenta atņemšana no funkcijas pie iepriekšējā argumenta un rezultāta dalīšana ar šo divu argumentu starpību (šajā gadījumā apzīmēts kā delta_x).

## Programma
Šī programma satur dialogu ar lielotāju, kur tiek prasīta argumenta a,b un delta_x ievade, kuri tiks lietots aprēķinos.
- a - vērtība no kuras sāk aprēķinu(ieteicams nelikt 0, jo analītiskajos atvasinājumos tiek veikta dalīšana ar x[0], kurš tiek sākumā iestatīts kā a)
- b - vērtība līdz kurai tiks veikts aprēķins.
- delta_x - precizitāte ar kuru tiks veikti aprēķini. Arī ir notiecošais faktors cik lielumi tiks izveidoti derivative.dat failā.

Pēc argumentu ievades funckcija izveido failu derivative.dat, kurā tiks ierakstītas argumenta, funkcijas un atvasinājumu vērtības.

Šajā failā uzreiz pēc izveides tiek ierakstīti tabulu virsraksi, lai ir saprotams, kura vērtība ir kura.

Tiek ieviests ints i, kurš atbild par masīvu izmēru. Šis ints ir vienāds ar b-a/delta_x , kas ļauj mums iegūt cik vērtības būs masīvā.

Tālāk, tiek izveidoti masīvi un tiem tiek piešķirts atmiņas apjoms, kurš atbilst vērtību skaitam, kas būs katrā masīvā.
Tas ir nepieciešams, lai lieki nelietot atmiņu, ja nav uzreiz zināms cik vērtības būs masīvā. Šim nolūkam izmantota funkcija malloc.

Pēc tā x argumentu masīva 0 pozīcijai tiek piešķirts mainīgais a, jo a ir punkts no kura aprēķini tiek sākti. Tad izmantojot for ciklu saraksts tiek piepildīts pieskaitot pie iepriekšējās x vērtības precizitātes mainīgo delta_x. Saraksts tiek piepildīts līdz ko tas sasniedz intu i.

Pēc tam tiek piepildīts funkciju masīvs ar manu funckiju(cos(sqrt(x))) x argumentu izvēloties no iepriekšējā masīva.

Tālāk sākas forward difference pielietojums, kurš paņem no funkcijas masīva funkciju, atņem iepreikšējo funkciju un dala ar delta_x. Šādā veidā tiek iegūts tuvinājums funkcijas pirmās kārtas atvasinājumam, bet ar trūkumu, ka pēdējo vērtību nav iespējams iegūt, jo beigās tiek meiģināts paņemt nākošo funkciju, kad tāda neeksistē. Ši iemesla dēļ šajā for ciklā tiek pārbaudīts vai programma nokļuva pie pēdējās funkcijas un ja jā, tad pēdējā vērtība tiek iestatīta kā 0, lai neparādītos nejauša vērtība no atmiņas.

Pēc tāda paša principa tiek aprēķināts otrās kārtas atvasinājums, bet šoreiz tiek ņemta nevis pati funkcija no argumenta, bet tiek ņemtas vērtības no pirmās kārtas atvasinājuma masīva.

Šeit mēs varam ievērot šīs metodes galveno plusu, ka mums nav nepieciešams pašiem rēķināt tālākos atvasinājumus. Var vienkārši ņemt vērtības no iepriekšējā masīva un atvasināt tik reizes cik ir nepieciešams, bet ir arī galvenais trūkums. Ja iepriešējā reizē mums trūka vienas vērtības beigās, tad šī iemesla dēļ pie otras kārtas atvasinājuma mums trūks divas vērtības beigās. Ja lielumu skaits ir mazāks par atvasinājumu skaitu, tad var nonākt līdz tam, ka atvasinājumus vairs nebūs iespējams iegūt, jo nebūs vairs pietiekams skaits ieprieksējo vērtību, lai iegūt atvasinājumu.

Pēc tā atkal ar for ciklu tiek piepildīti analītisko pirmās un otrās kārtas atvasinājumu masīvi, lai varētu salīdzināt cik precīza ir finite diference metode.

Tālāk, derivative.dat failā tiek ierakstītas katra masīva vērtības tabulas veidā, lai to pēc tam varētu pielietot grafika izveidei izmantojot gnuplot programmatūru.

Pēc tā tiek atbrīvota atmiņa, ko mēs piešķīrām masīviem izmantojot malloc. 

Pašās beigās fails tiek aiztaisīts.


Pēc tā var palaist izveidoto derivative.gp gnuplot skriptu, kurš izveidos grafiku derivative.png, kurā varēs redzēt sākonējo funkciju, pirmās un otrās kārtas atvasinājumu izmantojot forward difference. 

### Grafiks
![derivative.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/3ld_derivative/derivative.png)


Ja ir vēlme izveidot grafiku ar citām vērtībām, tad ieteicams norādīt skripta failā x robežas no izvēlētā a līdz izvēlētam b atvasinajums.c programmā. Kā arī pareizi izvēlēties kolonnu no kuras tiek ņemtas vērtības. Ir jāņem vērā, ka plot robežas galējo vērtību nav jāņem kā izvēlēto b, jo pēc forward difference metodes nevar iegūt pēdējo pirmās kārtas atvasinājuma vērtību un pēdējās divas otrās kārtas atvasinājuma vērtību. Grafikā tas uzrādīsies kā funkciju straujš kritums uz y=0.
