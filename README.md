# RTR105
Sudiju kursa Datormācība (pamatkurss) elektroniskā klade

## 1. Nodarbības atziņas
**Manas Linux pirmās komandas:**  
- uname  
- uname -a  
- man uname  
- uname -p  
- man uname  
- uname -o  
- whoami  
- pwd  
- man pwd  
- history

## 2. Nodarbības atziņas
**Pārvietošanās sistēmā, failu izveide, kopēšana, dzēšana un pārlūkošana:**
- *ls* - Parāda direktorija saturu. Var apskatīties konkrētās mapes saturu norādot tās adresi pēc komandas.
  - -a norāda apslēptos laikus; -t sagrupē pēc izmaiņu laika; -l parāda failus ar detalizētāku aprakstu.
- *tree* - Parāda direktoriju saturu "koka" formātā.
- *cd* - Nomaina direktoriju, kurā atrodas lietotājs.
  - "." - Esošā mape; ".." - Atiet atpakaļ. cd bez nekā = home dir.
- *mkdir/rmdir* - Respektīvi direktorija izveide un dzēšana.
- *touch* - Var tikt izmantots failu(piem. txt) izveidei, kā arī var ietekmēt failu laikus.
- *echo* - Parāda teksta līniju. Var tikt izmantots teksta failu izveidei/modificēšanai.
  - Izmantošana: echo [teksts] >/>> [fails]. ">" - Izveido failu ar tekstu vai aizvieto esošo tekstu; ">>" - Pievieno jaunu tekstu.
- *cat* - Izprintē faila saturu.
- *hexdump* - Parāda faila saturu heksadecimālajā veidā.
- *rm* - Izdzēš failu(-s).
- *cp* - Kopē failus vai direktorijus.
- *mv* - Pārvieto vai pārdēvē failus.
   - Piemērs: mv CDE/text_1.txt CDE/text_3.txt  - Failu text_1 direktorijā CDE nepārvietoja, bet pārdēvēja par text_3.
