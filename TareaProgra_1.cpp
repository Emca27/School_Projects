#include <iostream>
using namespace std;

//Funcion para mostrar nueva matriz
void muestraNueva(int invaMatrix[][10])
{
     for (int i=0; i<=3; i++)
        {
            for(int j=0; j<=3; j++)
            {
                if(j==3)
                {
                    cout<<invaMatrix[i][j];
                }
                else if(j<3)
                {
                    cout<<invaMatrix[i][j]<<" ";

                }
            }
            cout<<endl;
        }
}

//Funcion caso 3
void casoTres(int iMatrix[][10],int invaMatrix[][10])
{
    //Recorriendo la matriz
    for (int i=0; i<=3; i++) //Filas
    {
            for(int j=0; j<=3; j++)//Columnas
            {
                    invaMatrix[3-j][i] = iMatrix[i][j];
            }
    }
    muestraNueva(invaMatrix);
}

//Funcion caso 2
void casoDos(int iMatrix[][10],int invaMatrix[][10])
{
    //Recorriendo la matriz
    for (int i=0; i<=3; i++) //Filas
    {
            for(int j=0; j<=3; j++)//Columnas
            {
                    invaMatrix[3-i][3-j] = iMatrix[i][j];
            }
    }
    muestraNueva(invaMatrix);
}

//Funcion caso 1
void casoUno(int iMatrix[][10],int invaMatrix[][10])
{
   //Recorriendo la matriz
    for (int i=0; i<=3; i++) //Filas
    {
            for(int j=0; j<=3; j++)//Columnas
            {
                    invaMatrix[j][3-i] = iMatrix[i][j];
            }


    }
    muestraNueva(invaMatrix);
}

//Funcion para llenar la matriz de entrada
void llenarMatriz(int iMatrix[][10])
{
     //Almacenando en matriz
    for (int i=0; i<=3; i++) //Filas
    {
        for(int j=0; j<=3; j++)//Columnas
        {
            cin >> iMatrix[i][j];
        }
    }

}

void mostrarOriginal(int iMatrix[][10] )
{
     //Mostrando la matriz
    for (int i=0; i<=3; i++)
    {
        for(int j=0; j<=3; j++)
        {
             if(j==3)
                {
                    cout<<iMatrix[i][j];
                }
                else if(j<3)
                {
                    cout<<iMatrix[i][j]<<" ";

                }
        }
        cout<<endl;
    }

}

int main()
{
    int iN, iCaso;
    int iMatrix[10][10]; //Matriz de entrada
    int invaMatrix[10][10]; //Matriz de salida

    cin >> iN;

    if(iN<0)
    {
        iCaso = (iN*-1)%4;
        if (iCaso==1)
        {
            iCaso+=2;
        }
        if(iCaso==3)
        {
            iCaso-=2;
        }
    }

    else if(iN>=0)
    {
        iCaso =iN%4;
    }


   llenarMatriz(iMatrix);
   if(iCaso==0)
   {
          mostrarOriginal(iMatrix);
   }
   else if(iCaso==1)
   {
       casoUno(iMatrix,invaMatrix);

   }
   else if(iCaso==2)
   {
       casoDos(iMatrix,invaMatrix);
   }
   else if(iCaso==3)
   {
       casoTres (iMatrix,invaMatrix);
   }
    return 0;
}

