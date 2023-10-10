#include <stdio.h>

int main(void)
 {
 char c1; //šī ir diskreta mainīgā deklarēšana - noteikta izmēra atmiņas
          // apgabals (char -> 1 byte) tiks sasaistīts ar noteiktu
	  // identifikatoru (c1)
	  // atmiņā nav vakuums => šajā rezervētajā atmiņas apgabalā būs
	  // kaut kāda 0 un 1 kombinācija, kas palikus pēc kādas iepriekšējās
	  // programmas

 printf("c1 mainīgā vērtība uzreiz pēc deklarēšanas (simbols):  %c\n", c1);
 printf("c1 mainīgā vērtība uzreiz pēc deklarēšanas (dec):  %d\n", c1);
 printf("c1 mainīgā vērtība uzreiz pēc deklarēšanas (hex):  %#x\n", c1);
 printf("c1 mainīgā vērtība uzreiz pēc deklarēšanas (oct):  %#o\n", c1);
 printf("\n");
	   // mainīgā loma ir mainīties
 c1 = 'A'; // visbiežāk šo izmaiņu veiksim ar NB! piešķiršanas operāciju
	   // piešķiršanas operācijai ir gandrīz viszemākā prioritāte
	   // (tā tiek izpildīta viena no pēdējām)
	   // labajā pusē izrēķinātais lielums (vērtība) tiek izmitināta
	   // atmiņas apgabalā, kas ir saistīts ar kreisajā pusē pieminēto
	   // identifikatoru.
 printf("c1 mainīgā vērtība pēc piešķiršanas operācijas (simbols):  %c\n", c1);
 printf("c1 mainīgā vērtība pēc piešķiršanas operācijas (dec):  %d\n", c1);
 printf("c1 mainīgā vērtība pēc piešķiršanas operācijas (hex):  %#x\n", c1);
 printf("c1 mainīgā vērtība pēc piešķiršanas operācijas (oct):  %#o\n", c1);
 c1 = 0125;

 printf("\n");
 printf("c1 mainīgā vērtība pēc piešķiršanas operācijas (simbols):  %c\n", c1);
 printf("c1 mainīgā vērtība pēc piešķiršanas operācijas (dec):  %d\n", c1);
 printf("c1 mainīgā vērtība pēc piešķiršanas operācijas (hex):  %#x\n", c1);
 printf("c1 mainīgā vērtība pēc piešķiršanas operācijas (oct):  %#o\n", c1);

 int birth_year = 2000; // šī ir mainīgā definēšana (atmiņas apgabala 
			// sasaistīšana ar identifikatoru un vērtības piešķiršana)
			// mainīgajiem identifikatoriem, jeb vārdiem vēlams
			// izvēlēties mnemoniskus nosaukumus - nosaukuma vārds
			// vai teksts atspoguļo nolūku kādam šis mainīgais ir paredzēts
			// identifikators nevar sākties ar ciparu 
			// 			nevar saturēt atstarpi
 			// var saturēt - [A...Za....z][0...9][_]

 printf("\n");
 printf("birth_year mainīgā vērtība (simbols):  %c\n", birth_year);
 printf("birth_year mainīgā vērtība (dec):  %d\n", birth_year);
 printf("birth_year mainīgā vērtība (hex):  %#x\n", birth_year);
 printf("birth_year mainīgā vērtība (oct):  %#o\n", birth_year);

 int i1, i2 = 0, i3 = 0x13, i4 = 025;
 int modified_birth_year = birth_year >> 4;

 printf("\n");
 printf("modified_birth_year (simbols):  %c\n", modified_birth_year);
 printf("modified_birth_year (dec):  %d\n", modified_birth_year);
 printf("modified_birth_year (hex):  %#x\n", modified_birth_year);
 printf("modified_birth_year (oct):  %#o\n", modified_birth_year);

 char c = 10, cc = 127; // cc = 128(bus ar minus zimu jo signed robeza;
 int i =4569, ii = 126;
 float f = 3.14e+00, ff = 0.2569;
 double d = 4.789e9, dd = 0.69;


printf("\n");
 printf("c=%d\t\t(piešķirtas atmiņas izmērs baitos - %ld,\n\t\t", c, sizeof(c));
 printf("atrašanās vieta atmiņā - %p)\n", &c);
 printf("i=%d\t\t(piešķirtas atmiņas izmērs baitos - %ld,\n\t\t", i, sizeof(i));
 printf("atrašanās vieta atmiņā - %p)\n", &i);
 printf("f=%.2e\t(piešķirtas atmiņas izmērs baitos - %ld,\n\t\t", f, sizeof(f));
 printf("atrašanās vieta atmiņā - %p)\n", &f);
 printf("d=%.3e\t(piešķirtas atmiņas izmērs baitos - %ld,\n\t\t", d, sizeof(d));
 printf("atrašanās vieta atmiņā - %p)\n\n", &d);

 int *i_adrese = &i;
 printf("i mainīgā adrese - %p\n", i_adrese);
 int *i_adreses_kopija = i_adrese;
 printf("i adreses kopija - %p\n", i_adreses_kopija);
 printf("i mainīgā vērtība, izgūta pielietojot tā adresi - %d\n", *i_adrese);
 printf("i mainīgā vērtība, izgūta pielietojot tā adreses kopiju - %d\n", *i_adreses_kopija);

 int **i_adreses_adrese = &i_adrese;
 printf("i adreses adrese - %p\n", i_adreses_adrese);
 printf("i adreses adreses izmērs baitos - %ld\n", sizeof(i_adreses_adrese));

 /*
 float *f_adr = &f;
 printf("float: %f\n ", *f_adr); 
 printf("float: %d\n ", *f_adr); 
 
 eksperiments 
 */

 printf("dalīšanas operācijas pētīšana;\n");
 printf("char/char = ? -\n");
 printf("%d / %d = %d (rezultāta izmērs baitos - %ld)\n", cc, c, cc/c, sizeof(cc/c));
//char / int, char/double u.t.t
 printf("%d / %d = %d (rezultāta izmērs baitos - %ld)\n", i, ii, i/ii, sizeof(i/ii));
 printf("%f / %f = %f (rezultāta izmērs baitos - %ld)\n", f, ff, f/ff, sizeof(f/ff));
 printf("%f / %f = %f (rezultāta izmērs baitos - %ld)\n", d, dd, d/dd, sizeof(d/dd));

 return 0;
 }
