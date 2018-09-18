#include <iostream>
#include "string.h"
using namespace std;

//Struct de los equipos con puntaje y tiempos
struct Equipo
{
    string sNombre;
    int iACC = 0;
    int iTiempo =0;
};

//Struct de los equipos y el tiempo que se tardan en los problemas y si es correcto
struct Correctas
{
    string sNombre;
    int iTiempo=0;
    char cVarCo;
};

//Struct de los equipos y el tiempo que se tardan en los problemas y si es incorrecto
struct Incorrectas
{
    string sNombre;
    int iTiempo=0;
    char cVarInco;
};

//Funcion void para almacenar cantidad y nombres de equipo
void equiposNombres ( int iT, int iP, Equipo E[20] )
{

    //Ciclo for para recibir los nombres
    for (int i = 0; i < iT ; ++i)
    {
        cin >> E[i].sNombre;
    }
}





int main()
{
    int iCorr=0;
    int iCincorr=0;
    int iT, iP, iS; //Declarando variables que guardan cantidad de equipos, problemas y soluciones
    struct Correctas *cPregCorr;
     struct Incorrectas *cPregIncorr;
    Equipo E[20];//Declrando equipos del concurso
    cin >> iT >> iP;
    equiposNombres (iT,iP,E);
    cin>>iS;
    cPregCorr = new struct Correctas[iS];
    cPregIncorr = new struct Incorrectas[iS];

    string sNomTemp;//Variable temporal para el nombre de equipo
    char cProTemp;//Variable temporal para el problema
    int iTiemTem;//Variable temporal para el tiempo
    char cCalTemp;//Variable temporal para ver si fue aprobado

    //Ciclo for para recibir datos de los equipos con sus puntos
    for (int i = 0; i < iS; ++i)
    {
        cin >> sNomTemp;
        cin >>cProTemp;
        cin >>iTiemTem;
        cin >>cCalTemp;

        if(cCalTemp=='A') //Si fue aceptado
        {
            cPregCorr[iCorr].cVarCo=cProTemp;
            cPregCorr[iCorr].sNombre=sNomTemp;
            cPregCorr[iCorr].iTiempo=iTiemTem;
            iCorr++;
        }

        else if(cCalTemp=='W')//Si no fue aceptado
        {
            cPregIncorr[iCincorr].cVarInco=cProTemp;
            cPregIncorr[iCincorr].sNombre=sNomTemp;
            cPregIncorr[iCincorr].iTiempo=iTiemTem;
            iCincorr++;
        }
    }

    for (int i =0 ; i <iCorr ; ++i)
    {
        for (int j =0 ; j <iCincorr ; ++j)
        {
            if(cPregCorr[i].sNombre == cPregIncorr[j].sNombre && cPregCorr[i].cVarCo == cPregIncorr[j].cVarInco)
            {
                cPregCorr[i].iTiempo+=20;
            }
        }
    }


    for (int i = 0; i <iCorr ; ++i)
    {
        for (int j = 0; j <iT ; ++j)
        {
            if(E[j].sNombre==cPregCorr[i].sNombre)
            {
                E[j].iTiempo+=cPregCorr[i].iTiempo;
                E[j].iACC++;
            }
        }
    }

    struct Equipo eAux;
    int iAux;
    for(int i=0; i<iT;i++)
    {
        for (int j = 1; j <iT ; ++j)
        {
            if(E[j-1].iACC<E[j].iACC||E[j-1].iACC==E[j].iACC&&E[j-1].iTiempo>E[j].iTiempo)
            {
                eAux=E[j];
                E[j]=E[j-1];
                E[j-1]=eAux;
            }
        }
    }




    for(int i=0; i < iT; i++)
    {
        cout << i+1 << " " << "-" << " ";
        cout << E[i].sNombre << " ";
        cout << E[i].iACC << " ";
        if(E[i].iTiempo == 0)
        {
            cout << "-";
        }
        else
        {
            cout << E[i].iTiempo;
        }
        cout << endl;
    }

    return 0;
}