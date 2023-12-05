# 1. Laboratorijas darbs - Teilora rindas
Autors: Aleksejs Jakimovičs

Grupa: RECV0-1
## Mapes saturs
- [grafiks.c](https://github.com/Aleksejs63/RTR105/blob/main/darbi/1ld_series/grafiks.c) -> Uzrakstītā programma
- [graph.gp](https://github.com/Aleksejs63/RTR105/blob/main/darbi/1ld_series/graph.gp) -> Gnuplot skripts, kurš izveido grafiks.png
- [grafiks.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/1ld_series/grafiks.png) -> Gnuplotā izveidotais grafiks ar manuāli ievadītām argumenta vērtībām
- [kods.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/1ld_series/kods.png) -> Izpildītā koda attēls (1.daļa)
- [ascii.png](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/1ld_series/ascii.png) -> Izpildītā koda attēls kurš ietver ascii zīmējumu (2.daļa)
- [README.md](https://github.com/Aleksejs63/RTR105/blob/main/darbi/1ld_series/README.md) -> Laboratorijas darbu apraksošs dokuments, kurš satur sevī informāciju par uzrakstīto kodu un rezultātus attēlu veidā.
## Apraksts

Šajā laborotorijas darbā tika veikta teilora rindas implementēšana programmā C valodā. 

Teilora rindas ir metode ar kuras palīdzību ir iespējams ļoti precīzi pietuvināties matemātiskajām operācijām (piem. sin(x), sqrt(x) u.t.t.)

Šis ir viens no paņēmieniem kā var matemātiskās funkcijas implementēt koda veidā, kas visbiežāk tiek izmantots kalkulatoros. Teilora rindas izmanto bezgalīgu summu un ietver sevī arī faktoriālu. Šāds aprēķins var ļoti apgrūtināt datoru pat ja summu skaits ir salīdzinoši neliels, jo faktoriāls ātri kļūst ļoti liels. Šī iemesla dēļ nācās veikt matemātiskos pārveidojumus kuru rezultātā ieguvām funkciju, kura neietver sevī faktoriālu. Tika ierobežots arī summu skaits (šajā gadījumā 500).

## Programma
Šī programma satur dialogu ar lielotāju, kur tiek prasīta argumenta x ievade, kurš tiks lietots aprēķinos. 

Vispirms tiek attēloti izveidotās funkcijas summas un rekurences reizinātāja (a un sum) vērtības 499. un 500. iterācijā.

Pēc a un sum attēlošanas programma izvada funkcijas vērtību pie ievadītā argumenta izmantojot math.h headera iekļautās funkcijas. Pēc tā tiek izvadīta funkcijas vērtība pie ievadītā argumenta izmantojot funkciju, kura tika izveidota šā laborotorijas darba gaitā.

Var redzēt ka skaitļi ir ļoti tuvi. Precizitāti var uzlabot palielinot summu skaitu (apzīmēts ar mainīgo k).

Koda attēls (ievadītais mainīgas x = 2):

![koda attēls](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/1ld_series/kods.png)

Pēc koda attēlošanas tiek attēlots ASCII zīmējums kurā parādīta izveidotā funkcija (mainīgā vietā tiek rādīts lietotāja ievadītais skaitlis).

ASCII zīmējums:

![ascii attēls](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/1ld_series/ascii.png)



Funkcijas grafiks:

Attēlojot pirmos saskatiāmos (s0,s1,s2,s3) var redzēt, ka funkcijas ar katru iterāciju (pieskaitīšanu) pietuvojas oriģinālfunkcijai. Sīs grafiks ir ļoti labs piemērs Teilora rindu darbības principam.

![funkcijas grafiks](https://raw.githubusercontent.com/Aleksejs63/RTR105/main/darbi/1ld_series/grafiks.png)
