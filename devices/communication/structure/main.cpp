// Programme de test

#include <iostream>
#include "Structure_Sigfox.h"

// convertis aussi bien la latitude que la longitude. Cette fonction suppose que le paramètre cardinal est N, S, E ou O.
double Dms_to_dd(char cardinal, int angle, int minute, double seconde){
	double res = angle;
	double temp = seconde/60;
	res += (minute+temp)/60;
	if( cardinal == 'S' || cardinal == 'O') { res = -res;}
	return res;ha
	}

int main() {
    Message m = Message();
    string res;
    res = m.int_to_hexa(314);
    //std::cout << res;
    double lat =  48.84527;
    int prec = 5;
    int res_int;
    res_int= m.double_to_int(lat, prec);
    //std::cout << res_int<<endl;
    
    res = m.double_to_hexa(lat,prec);//tester sur un plage de valeur d'etrée de 0 à 270;
    //std::cout << res;
    
    
    std::cout<<Dms_to_dd('S',48, 51, 17.005)<<endl;
    std::cout<<Dms_to_dd('O',2, 21, 0.749)<<endl;
    
}
