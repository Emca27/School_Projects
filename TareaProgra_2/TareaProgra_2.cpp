#include <iostream>
using namespace std;


//Funcion para llenar la matriz de entrada
void llenarMatriz(int iSudoku[][10])
{
     //Almacenando en matriz
    for (int i=0; i<=8; i++) //Filas
    {
        for(int j=0; j<=8; j++)//Columnas
        {
            cin >> iSudoku[i][j];
        }
    }

}

//Funcion de tipo booleana para revisar las filas
bool checarFilas(int iSudoku[][10])
{
    bool bBandera=false;
    int iAux;
    //Pasando por la matriz
    for (int i=0; i<=8; i++) //Filas
    {
        for(int j=0; j<=8; j++)//Columnas
        {
            iAux=iSudoku[i][j];
            for(int k=j; k<=8; k++)
            {
                if(k<8)
                {
                    if(iAux==iSudoku[i][k+1])
                        {
                            bBandera= true;
                        }
                }
            }
        }
    }
    return bBandera;
}

//Funcion de tipo booleana para revisar las columnas
bool checarColumnas(int iSudoku[][10])
{
    bool bBandera=false;
    int iAux;
    //Pasando por la matriz
    for (int i=0; i<=8; i++) //Filas
    {
        for(int j=0; j<=8; j++)//Columnas
        {
            iAux=iSudoku[i][j];
            for(int k=i; k<=8; k++)
            {
                if(k<8)
                {
                    if(iAux==iSudoku[k+1][j])
                        {
                            bBandera= true;
                        }
                }
            }
        }
    }
    return bBandera;
}

//Funcion para checar las matrices de 3x3
bool checarMatrices(int iSudoku[][10])
{
    bool bBandera=false;
    int iAux,iAuxArr;
    int iArr[8];
    //Pasando por la matriz
    for (int i=0; i<3; i++) //Cuadrantes en filas
    {
        for(int j=0; j<3; j++)//Cuadrantes en columnas
        {
            iAux=0;
            for(int k=0; k<3; k++)//Filas matriz chiquita
            {
                for(int m=0; m<3; m++)//Columnas matriz chiquita
                {
                   iArr[iAux]=iSudoku[((i*3)+k)][((j*3)+m)];
                    iAux++;
                }
            }
            for(int a=0; a<=8;a++)
            {
                iAuxArr=iArr[a];
                for(int b=a; b<=8;b++)
                {
                    if(b<8)
                    {
                        if(iAuxArr==iArr[b+1])
                        {
                            bBandera=true;
                        }
                    }
                }
            }
        }
    }
    return bBandera;
}

int main()
{
    int iSudoku[10][10];//Matriz de entrada.

    llenarMatriz(iSudoku);

    if(checarFilas(iSudoku)||checarColumnas(iSudoku)||checarMatrices(iSudoku))
    {
        cout<<"NO"<<endl;
    }
    if(!checarFilas(iSudoku)&&!checarColumnas(iSudoku)&&!checarMatrices(iSudoku))
    {
        cout<<"YES"<<endl;
    }
    return 0;
}

