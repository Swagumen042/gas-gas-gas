#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//
//  Scrieti un program care realizeaza urmatoarele operatii pe biti:
//  1. Rotire la dreapta
//  2. Rotire la stanga
//  3. Seteaza toti bitii pana la n, introdus de la tastatura, la 1
//  4. Seteaza toti bitii pana la n, introdus de la tastatura, la 0
//  5. Schimba bitul de pe pozitia n (daca e 0, acesta va deveni 1 si invers.)
//  6. Schimba toti bitii pana la cel de pe pozitia n
//  7. Schimba toti bitii pana la cel de pe pozitia n INCEPAND de la stanga spre dreapta.
//  8. Verifica cati biti setati au in comun doua numere introduse de la tastatura
//  9. Scrie reprezentarea in cod gray (doua numere consecutive
//     scrise in cod gray difera intre ele de un singur bit) pt toate numerele
//     ce se scriu pe n biti (cu n introdus de la tastatura)
//  Utilizeaza functii ca nu degeaba le-ai invatat.
//  Pentru program se va folosi un meniu.
unsigned char flipnbit(unsigned char nr, unsigned n);
unsigned char setbitston(unsigned char nr, unsigned n);
unsigned char unsetbitston(unsigned char nr, unsigned n);
unsigned char rotater(unsigned char nr, unsigned n);
unsigned char rotatel(unsigned char nr, unsigned n);
unsigned char flipbitston(unsigned char nr, unsigned n);
void graycode(unsigned n);
void checksetbits(unsigned char nr_a);
unsigned char revflipbitston(unsigned char nr, unsigned n);


//
//  Daca ai venit pentru functii, dai scroll peste corpul "main".
//  In meniu se apeleaza doar functiile cu prototipurile de mai sus.
//
//


int main()
{
    unsigned char a;
    unsigned n,menu;
    int val;
    char check[100];
    n = 420;
    a = 69;
    do{
        printf("Numarul introdus de la tastatura este %u, iar n = %u\n", a, n);
        printf("1. Introducere parametri.\n");
        printf("2. Rotire la dreapta.\n");
        printf("3. Rotire la stanga.\n");
        printf("4. Seteaza bitii pana la n la 1.\n");
        printf("5. Seteaza bitii pana la n la 0.\n");
        printf("6. Seteaza bitul n la valoarea opusa.\n");
        printf("7. Seteaza bitii pana la n la valoarea opusa.\n");
        printf("8. Seteaza n-bitii incepand de la stanga la valoarea opusa.\n");
        printf("9. Verifica cati biti setati au in comun numerele introduse.\n");
        printf("10. Reprezentarea in cod gray pt numerele scrise pe n biti(fara semn)\n");
        printf("Nu exista 11. (0. Iesire).\n\n");
        scanf("%u%*c", &menu);
        switch(menu){
        case 1:
            printf("Introduceti un numar care se poate scrie pe 8 biti, fara semn: ");
            do{
                fgets(check, 100, stdin);
                val = atoi(check);
                if((val >= 256) || (val <= 0)){
                    printf("Introduceti un numar in intervalul [0, 255]:");
                }
                else
                    a = val;
            }while(val>=256 || val <= 0);
            printf("Introduceti n: ");
            scanf("%u", &n);
            break;
        case 2:
            //system("cls"); curata consola, ca sa nu ai meniul ala peste tot. NU MERGE PE LINUX
            printf("Numarul %u dupa rotire la dreapta cu %u biti este: %u.\n", a, n, rotater(a, n));
            break;
        case 3:
            //system("cls");
            printf("Numarul %u dupa rotire la stanga cu %u biti este: %u.\n", a, n, rotatel(a, n));
            break;
        case 4:
            //system("cls");
            printf("Numarul %u dupa setarea tuturor bitilor pana la %u la 1 este: %u.\n",a, n, setbitston(a, n));
            break;
        case 5:
            //system("cls");
            printf("Numarul %u dupa setarea tuturor bitilor pana la %u la 0 este: %u.\n",a, n, unsetbitston(a, n));
            break;
        case 6:
            //system("cls");
            printf("Numarul %u dupa ce bitul %u a fost setat la valoarea opusa este: %u.\n",a, n, flipnbit(a, n));
            break;
        case 7:
            //system("cls");
            printf("Numarul %u dupa ce bitii pana la %u au fost setati la valoarea opusa este: %u.\n",a, n, flipbitston(a, n));
            break;
        case 8:
            //system("cls");
            printf("Numarul %u dupa ce se seteaza primii %u biti, incepand de la stanga numarului este: %u.\n",a, n, revflipbitston(a, n));
            break;
        case 9:
            //system("cls");
            checksetbits(a);
            printf("\n");
            break;
        case 10:
            //system("cls");
            graycode(n);
            printf("\n");
            break;
        case 0:
            printf("Press the ANY key to continue.");
            getchar();
            break;
        case 11:
            skrra();
            break;
        default:
            printf("You chose poorly. Choose again.\n");
            break;

        }
    }while(menu);

}

unsigned char rotater(unsigned char nr, unsigned n){
    if (!(n%8)){
        return nr;
    }
    else
        return ((nr >> (n % 8)) + (nr << (8 - (n%8)))); // n%8 in caz de exista vreun "prof destept" care baga "n = 69" crezand ca o sa imi futa programu'
}

unsigned char rotatel(unsigned char nr, unsigned n){
    if (!(n%8)){
        return nr;
    }
    else
        return ((nr << (n % 8)) + (nr >> (8 - (n%8)))); // acelasi lucru
}

unsigned char setbitston(unsigned char nr, unsigned n){
    unsigned char bitSetter=0;
    unsigned char nrShifts=0;
    while(nrShifts<(n%8)) // n%8 in caz de exista vreun "destept" care vrea sa-mi futa programu' dandu-i sa seteze toti bitii pana la 2147483648
    {
        nrShifts++;
        bitSetter = bitSetter << 1;
        bitSetter++;
    }


    return (nr | bitSetter);
}

unsigned char unsetbitston(unsigned char nr, unsigned n){
    unsigned char bitUnsetter=0;
    unsigned nrShifts;
    while (nrShifts<(8 - (n%8))) // "da daca ii dau n = 747 oare nu se fute programu?" nu, am avut eu grija.
    {
        nrShifts++;
        bitUnsetter = bitUnsetter << 1;
        bitUnsetter++;
    }
    while(nrShifts>(n%8) && nrShifts<8){
        bitUnsetter = bitUnsetter<<1;
        nrShifts++;
    }
    return(nr & bitUnsetter);
}

unsigned char flipnbit(unsigned char nr, unsigned n){
    if (!(n%8))
        return nr;
    else
        return (nr ^ (1<<((n-1)%8))); // operatii cu masti (nu dinalea de halloween) se pot implementa pentru setarea bitului n la 1, la 0, sau pentru "flipuirea" lui
                              // pentru setarea bitului n la 1: XOR -> OR, pentru setarea bitului n la 0: XOR -> AND.
}

unsigned char flipbitston(unsigned char nr, unsigned n){
    unsigned char bitFlipper;
    unsigned nrShifts;
    while (nrShifts < (n%8)){
        nrShifts++;
        bitFlipper = bitFlipper << 1;
        bitFlipper++;
    }
    return(nr ^ bitFlipper);
}

// aici incepe magia neagra
// chestiile astea sunt TOTAL optionale, sunt aici doar daca vrei sa faci pe desteptul.

void checksetbits(unsigned char nr){
    //  "Pai ce trebuie sa faca algoritmul asta?" -tu, cand ajungi aici
    //
    //  Trebuie sa ia doua numere, sa le compare (pe biti), si sa iti spuna
    //  care sunt bitii care au valoarea 1 in AMBELE numere.
    //
    //  "Care-i rostul?"
    //
    //  Castigi experienta.
    //

    unsigned char new_nr;
    unsigned char new_aux;
    unsigned char old_nr;
    int countCommon=0;

    printf("Introduceti un nou numar: ");
    scanf("%u", &new_nr);
    new_aux = new_nr;
    old_nr = nr;
    printf("Numerele sunt: %u si %u\n", nr, new_nr);
    for(old_nr;old_nr>0;){
        countCommon++; // acest contor incrementeaza tot timpul pentru a putea afisa pozitia pe care cele doua numere au bit setat pe 1.
        if((old_nr % 2)==1 && (new_aux % 2)==1) // "de ce && si nu ==?" -tot tu, nedumerit de ceea ce se intampla.
        {                              // Pentru ca 0 este egal cu 0, iar noi vrem doar sa aflam pe ce pozitie bitii ambelor numere sunt setati pe 1.
                                       //
            printf("Ambele numere, %u si %u, au bitul %d setat la 1.\n", nr, new_nr, countCommon);
        }
        old_nr/=2;
        new_aux/=2;

    }
}

void graycode(unsigned n){
    //
    //  Cod gray: oricare doua numere consecutive difera unul de celalalt de un singur bit:
    //  Exemplu: 0, 1, 3, 2, 6, 7, 5, 4
    //
    unsigned char grayNum;
    printf("Reprezentarea in cod gray pentru %u biti este: ", n);
    for(grayNum=0; grayNum<pow(2,n); grayNum++){
        printf("%u ", grayNum^(grayNum/2));
    }
}

unsigned char revflipbitston(unsigned char nr, unsigned n){

    //
    //  Gas gas gas, I'm gonna step on the gas
    //
    //

    unsigned char flippedNum;
    unsigned new_n;
    new_n = n;
    flippedNum = rotatel(nr,new_n);
    unsigned char flipper;
    unsigned nrShift;
    while (nrShift < (n%8)){
        nrShift++;
        flipper = flipper << 1;
        flipper++;
    }
    flippedNum = flippedNum ^ flipper;
    flippedNum = rotater(flippedNum,new_n);
    return flippedNum;
    // da-ma in judecata
}

void skrra(){
    printf("Two + two is four, minus one that's three, quick maths\n");
            printf("Everyday man's on the block, smoke trees.\n");
            printf("See yo' girl in the park, that girl is a uckers.\n");
            printf("When da ting went \"quack, quack, quack\", you man went ducking.\n");
            printf("Hold tight, Azsnee.\n");
            printf("He's got a pumpy.\n");
            printf("Hold tight, my man.\n");
            printf("He's got a Frisbee.\n");
            printf("I trap, trap, trap on the road, movin' that cornflakes.\n");
            printf("Rice Krispie, hold tight, my girl Whitney.\n");
            printf("On the road doin' ten toes, like my toes.\n");
            printf("You man thought I froze, I see a peng girl, then I pose.\n");
            printf("If she's not on it, I ghost, hah, look at your nose.\n");
            printf("What? You dickhead! Look at your nose.\n");
            printf("Nose long like garden hose, shhh, you get me?\n");
            getchar();
            printf("Boom, man's gonna come back in.\n");
            printf("You know like that?\n");
            printf("You're feelin' that?\n");
            printf("You dun know, I see you shiverin' an' that.\n");
            printf("Don't get shook man's here.\n");
            printf("You protected-ed, yeah?\n");
            printf("Aight, boom, let's go, boom.\n");
            getchar();
            printf("Hop out the four-door with the .44, it was one-two-three and four.\n");
            printf("Chillin' in the corridor, your dad is fourty-four.\n");
            printf("And he's still callin' man for a draw, let him know.\n");
            printf("When I see him, I'm gonna spin his jaw.\n");
            printf("Your girl knows I've got the sauce, no ketchup.\n");
            printf("Just sauce, raw sauce.\n");
            printf("Boom, yo, gah.\n");
            getchar();
            printf("DA TING GO SKRRRA, PA PA KA-KA-KA\n");
            getchar();
            printf("SKIBIKI-PAP-PAP, AND A PU-PU TURRRUUU-BOOM\n");
            getchar();
            printf("SKYA, DU DU KU KU BOOM BOOM\n");
            getchar();
            printf("POOM POOM\n");
            getchar();
            printf("You dunno, Big Shaq.\n");
            printf("Man's never hot.\n\n\n\n");
}
