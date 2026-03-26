#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 La posizione delle stelle viene registrata in un sistema chiamato ascensione retta e declinazione, noto a tutti gli astronomi, dilettanti e professionisti, come RA e Dec: RA e' la posizione di una stella misurata in direzione est-ovest nel cielo (simile alla longitudine terrestre, la posizione di un luogo sulla Terra misurata a est o a ovest del meridiano di Greenwich, in Inghilterra). Dec e' la posizione della stella misurata in direzione nord-sud, similmente alla latitudine terrestre di una citta', che viene misurata a nord o a sud dell'Equatore. Gli astronomi solitamente registrano la RA in unita' di ore, minuti e secondi, come il tempo. La declinazione e' espressa in gradi, minuti e secondi d'arco. Novanta gradi formano un angolo retto, 60 minuti d'arco equivalgono a un grado e 60 secondi d'arco equivalgono a un minuto d'arco. Un minuto d'arco o un secondo d'arco sono anche comunemente chiamati rispettivamente arcominuto  o arcosecondo.
 --
 The positions of stars are recorded in a system called right ascension and declination, known to all astronomers, amateur and professional, as RA and Dec: RA is the position of a star measured in the east-west direction in the sky (similar to longitude, the position of a place on Earth measured east or west of the prime meridian in Greenwich, England). Dec is the position of the star measured in the north-south direction, like the latitude of a city, which is measured north or south of the Equator. Astronomers usually record RA in units of hours, minutes, and seconds, like time. Declination is given in degrees, minutes, and arcseconds. Ninety degrees form a right angle, 60 arcminutes equal one degree, and 60 arcseconds equal one arcminute. An arcminute or an arcsecond are also commonly called an arcminute or arcsecond, respectively.
 */

/*
In-depth Study of RA and Dec
A star with a RA of 2h 00m 00s is two hours east of a star with a RA of 0h 00m 00s,
regardless of their declinations. RA increases from west to east, starting at RA 0h 00m 00s, which corresponds to a line in the sky (actually a semicircle, centered on the Earth) from the North Celestial Pole to the South Celestial Pole. The first star may be at Dec 30deg north and the second at Dec 15deg 25' 12'' south, but they are still two hours apart in an east-west direction (and 45deg 25'12'' apart in a north-south direction). The North and South Celestial Poles are points in the sky to the north and south) around which the entire sky appears to rotate, with stars appearing and setting.
Remember the following details about the units RA and Dec:
One RA hour is equal to an arc of 15deg on the equator of the sky. Twenty-four RA hours cover the sky, and 24 x 15 = 360deg, or a full circle around the sky. One RA minute, called a minute of time, is a measure of an angle in the sky that is composed of 1/60 of one RA hour. That is, 15deg / 60, or 1/4deg. One RA second, or a second of time, is sixty times smaller than a minute of time. Dec is measured in degrees, like the degrees of a circle, and in minutes and seconds of arc. One full degree is about twice the apparent or angular size of the full moon. Each degree is divided into 60 minutes of arc. Both the Sun and the Moon appear to be about 32 arcminutes (32') across the sky, even though the Sun is actually much larger than the Moon. Each arcminute is divided into 60 arcseconds (60''). When you look through a high-magnification garden telescope, air turbulence blurs the image of the star. Under good conditions (low turbulence), the image should be 1 or 2 inches across. This means 1 or 2 arcseconds, not 1 or 2 inches.
--
Studio approfondito di ascensione retta e declinazione
Una stella con ascensione retta di 2h 00m 00s si trova due ore a est di una stella con ascensione retta di 0h 00m 00s, indipendentemente dalla loro declinazione. L'ascensione retta aumenta da ovest a est, a partire da 0h 00m 00s, che corrisponde a una linea nel cielo (in realta' un semicerchio, centrato sulla Terra) che va dal Polo Nord Celeste al Polo Sud Celeste. La prima stella puo' trovarsi a Declinazione 30deg nord e la
seconda a Declinazione 15deg 25' 12'' sud, ma sono comunque separate da due ore in direzione est-ovest (e da 45deg 25' 12'' in direzione nord-sud). I poli celesti Nord e Sud sono punti nel cielo a nord e a sud) attorno ai quali sembra ruotare l'intero cielo, con le stelle che appaiono e tramontano.
Ricorda i seguenti dettagli sulle unita' di misura AR e Dec: Un'ora AR equivale a un arco di 15deg sull'equatore celeste. Ventiquattro ore AR coprono l'intero cielo, e 24 x 15 = 360deg, ovvero un cerchio completo attorno al cielo. Un minuto AR, detto anche minuto di tempo, e' una misura di un angolo nel cielo composto da 1/60 di un'ora AR. Ovvero, 15deg / 60, o 1/4deg. Un secondo AR, o secondo di tempo, e' sessanta volte piu' piccolo di un minuto di tempo. La Dec si misura in gradi, come i gradi di un cerchio, e in minuti e secondi d'arco. Un grado intero e' circa il doppio della dimensione apparente o angolare della luna piena. Ogni grado e' diviso in 60 minuti d'arco. Sia il Sole che la Luna appaiono avere un diametro di circa 32 minuti d'arco (32') nel cielo, anche se in realta' il Sole e' molto piu' grande della Luna. Ogni minuto d'arco e' diviso in 60 secondi d'arco (60''). Quando si guarda attraverso un telescopio da giardino ad alto ingrandimento, la turbolenza dell'aria sfoca l'immagine della stella. In condizioni ottimali (bassa turbolenza), l'immagine dovrebbe avere un diametro di 1 o 2 pollici. Cio' significa 1 o 2 secondi d'arco, non 1 o 2 pollici.
 */

struct RA{
 int hours;
 int min;
 double sec;
};

struct Dec{
  int deg;
  int min;
  double sec;
};

double RAdd;
double DECdd;

double RAtoRAdd(const struct *RA ra){
    double myRAdd;
    return myRAdd;
}


double DecToDECdd(const struct *Dec dec){
    double myDECdd;
    return myDECdd;
}

int DECddToDec(struct *Dec dec){
 int res=0;
 return res;
}

int RAddToRA(double radd, struct *RA ra){
 int res=0;
 return res;
}

int main(int argc, char ** argv){

    return 0;
}
