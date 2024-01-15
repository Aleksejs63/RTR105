# 4. Laboratorijas darbs - Integrēšana
Autors: Aleksejs Jakimovičs

Grupa: RECV0-1
## Mapes saturs
- [integral.c](https://github.com/Aleksejs63/RTR105/blob/main/darbi/4ld_integral/integral.c) -> Uzrakstītā programma
- [grafiks.gp](https://github.com/Aleksejs63/RTR105/blob/main/darbi/4ld_integral/grafiks.gp) -> Gnuplot skripts, kurš izveido derivative.png izmantojot datus no derivative.dat faila, kuru izveidoja atvasinajums.c programma. 
- [grafiks.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/4ld_integral/grafiks.png) -> Gnuplotā izveidotais grafiks, kurš satur pašu funkciju cos(sqrt(x)) un tās pirmās un otrās kārtas atvasinājumu pēc forward difference un analītiskās metodes.
- [wolfram-integral.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/4ld_integral/wolfram-integral.png) -> derivative.png grafika pietuvinātā daļa, lai var redzēt atšķirību starp abām metodēm.
- [kods.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/4ld_integral/kods.png) -> Gnuplot izveidotais grafiks, kur ar pelēko iekrāsotais laukums atbilst integrālim funkcijai cos(sqrt(x)) intervālā [30:35]
- [README.md](https://github.com/Aleksejs63/RTR105/blob/main/darbi/4ld_integral/README.md) -> Laboratorijas darbu apraksošs dokuments, kurš satur sevī informāciju par uzrakstīto kodu, pielietotām metodem un šīs mapes saturu.

## Apraksts

Šajā laboratorijas darbā tika izpētītas metodes kā var implementēt funkciju integrēšanu C valodā. 

Tā kā datoriem ir ierobežots resursu skaits, lai veiktu tādu darbību kā integrēšanai ir nepieciešams izmantot metodi, kura tuvinās patiesai vērtības(līdzīgi kā atvasināšanā un teilora rindās).

Šajā laboratorijas darbā tiek implementētas 3 metodes ar kurām ir iespējams atrast integrāli, respektīvi taisnstūru, trapeču un Simpsona metode.

Taisnstūru metode izveido taisnstūrus konkrētajā funkcijas intervālā ar vienādu katra taisnstūra platumu, kur taisnstūra augstums ir funkcijas vērtība pie tā platuma viduspunkta. Integrālis būs šo taisnstūru laukumu summa. Precizitāti ir iespējams palielināt palielinot taisnstūru skaitu intervālā. Šī ir visneprecīzākā no medodēm, bet to ir visvieglāk implementēt.

Trapeču metode darbojas līdzīgi, bet trapeces augšējā mala ir taisne kuras sākumpunks un galapunkts ir funkcijas vērtības pie trapeces platuma sākumpunkta un galapunkta, kas ļauj malai piekļauties funkcijai. Šī iemesla dēļ šī metode ir precīzāka par taisnstūru metodi, bet tāpat piekļaušanās ir tikai aptuvena, tapēc rezultāts nav tik precīzs kā pēdējai metodei.

Simpsona metode ir līdzīga trapeču metodei, bet figūras augšējā mala šajā metodē ir nevis taisne bet līkne, kas dod iespēju iegūt vēl precīzāku rezultātu, it īpaši, ja sākotnējā funkcija neveic straujas izmaiņas. Šī ir visprecīzākā no šīm trijām metodēm, bet to ir visgrūtāk implementēt.

## Programma
Sākumā tiek izveidota funkcija coskv, kas atgriež float tipa mainīgo cos(sqrt(x)). Šī funkcija izveidota, lai vienkāršotu koda pierakstu.

Pēc tā main funkcijā tiek izveidoti float tipa mainīgie
- a un b - intervāla punkti kurā tiek meklēts integrālis;
- integral1 un integral2 - 1. saglabā 2. vērtību un 2. saglabā precīzāku vērtību;
- eps - lietotāja uzdotā precizitāte līdz kurai tiks veikti aprēķini;
- h - cik daļās tiks sadalīts intervāls [a:b] / laukuma iedaļas figūras platums.
- n, m, k - nepieciešami, lai cikli darbotos.

Tālāk tiek iegūtas a, b un eps vērtības no lietotāja.

Pirmā no metodēm ir taisnstūra metode, kurā sākotnēji pie integral2 tiek piesaistīta aptuvenā vērtība (Šis tiek darīts visām metodēm, lai var uzsākt ciklu).

Cikls visām metodēm vienāds un tas darbojas pēc principa, ka cikls tiek izpildīts kamēr integral2 un integral1 starpības modulis ir lielāks par uzdoto precizitāti eps.

Ciklā m vērtība tiek palielināta 2 reizes (sākotnēji tā ir 1). Tad tiek iegūts laukuma figūru skaits n kurš ir 2 reizes lielāks par m.

Tālāk figūras augstums tiek aprēķināts kā b mīnuss a dalīts ar figūru skaitu, lai iegūt katras figūras platumu.

Tad integral1 vērtībā tiek saglabāta integral2 vērtība (lai tās var salīdzināt) un tad integral2 iestatās kā 0, lai varētu veiktu tālāko precīzāko aprēķinu, kas notiek iekšā for ciklā.

For cikls darbojas kamēr mainīgais k ir mazāks par figūru skaitu (iziet cauri visām figūrām) un tajā pie integral2 tiek piesaistīta integral2 vērtība pluss taisnstūra laukums ar platumu h un augstumu kurš ir funkcijas vērtība pie h viduspunkta.

Trapeču metodē viss ir identisks kā taisnstūru metodei izņemot for ciklu, kurš šoreiz sākas ar k = 1, lai varētu iegūt trapeces platuma sākumpunktu ((k-1) * h).
Pati formula arī atšķiras, jo tagad ir jāņem funkcijas pie sākumpunkta, jāsaskaita tā ar funkciju galapunktā un jāreizina ar platumu dalīts ar 2.

Simpsonu metode ir vissarežģītākā no šim trim metodēm, tapēc to izskaidrot ir sarežģītāk, bet būtībā integrālis tiek iegūts summējot funkciju pie intervāla sākumpunka un galapunkta, kā arī pirmspēdējo vērtību reizinot ar 4 un pie tā visa jāpieskaita visu intervālu summa, kura veidojas pāra vērtības reizinot ar 2 un nepāra ar 4 un to visu saskaitot un reizinot ar h/3 mēs iegūstam gala integrāli.

Pēc katras metodes tās rezultāts tiek izvadīts float tipā ar 5 cipariem aiz komata, norādot arī metodes nosaukumu.
### Grafiks
Attēlā var apskatīt koda darbības principu. No šiem visprecīzāko rezultātu atgrieza simpsona metode, ko var apskatīt otrajā attēlā.

![kods.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/4ld_integral/kods.png)
Šeit redzams integrāļa rezultāts no saites https://www.wolframalpha.com , ar kuru tika salīdzināts programmas rezultāts, lai izprast tās precizitāti.

![wolfram-integral.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/4ld_integral/wolfram-integral.png)

Gnupot grafikā redzams, ka funkcija intervālā x = [30:35] y ir aptuveni vidēji 0.8 un tā ka x ir 5 reizinot iegūstam 4 kas ir diezgan tuvu programmas iegūtai vērtībai (aptuveni 4.13). 
![grafiks.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/4ld_integral/grafiks.png)

