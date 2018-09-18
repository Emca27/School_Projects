#ifndef TAREAPORGRA_4_H_INCLUDED
#define TAREAPORGRA_4_H_INCLUDED

template <class T>
class Lista
{
private:
    T arrDatos[10];
    int iCant;

public:
    Lista();
    Lista(Lista &L);
    int getCant();
    T getDato(int iIndice);
    bool add(T dato);
    int search(T dato);
    void sort(bool bFlag);
    Lista<T> operator=( Lista L);
    bool operator==(Lista L);
    void print();
};

template<class T>
Lista<T>::Lista()
{
    iCant=0;
}

template<class T>
Lista<T>::Lista(Lista &L)
{
    for(int i =0;i<L.iCant;i++)
    {
        this->arrDatos[i]=L.arrDatos[i];
    }
    this->iCant = L.iCant;
}

template<class T>
int Lista<T>::getCant()
{
    return iCant;
}

template<class T>
T Lista<T>::getDato(int iIndice)
{
    return arrDatos[iIndice];
}

template<class T>
bool Lista<T>::add(T dato)
{
    bool bFlag = false;
    if (iCant<10)
    {
        arrDatos[iCant]=dato;
        iCant++;
        bFlag= true;
    }

    return bFlag;
}

template<class T>
int Lista<T>::search(T dato)
{
    for(int i=0;i<iCant;i++)
    {
        if(dato==arrDatos[i])
        {
            return i;
        }
    }
    return -1;
}

template<class T>
void Lista<T>::sort(bool bFlag)
{
    bool bInterruptor = 1;
    T datoAux;
    if(bFlag)
    {
        for(int i=0 ;i<iCant-1 && bInterruptor; i++)
        {
            bInterruptor=false;
            for(int j=0;j<iCant-1;j++)
            {
                if(arrDatos[j]>arrDatos[j+1])
                {
                    datoAux = arrDatos[j];
                    arrDatos[j]=arrDatos[j+1];
                    arrDatos[j+1]=datoAux;
                    bInterruptor=true;
                }
            }
        }
    }

    else
    {
         for(int i=0 ;i<iCant-1&&bInterruptor; i++)
        {
            bInterruptor=false;
            for(int j=0;j<iCant-1;j++)
            {
                if(arrDatos[j]<arrDatos[j+1])
                {
                    datoAux = arrDatos[j];
                    arrDatos[j]=arrDatos[j+1];
                    arrDatos[j+1]=datoAux;
                    bInterruptor=true;

                }
            }
        }
    }
}

template<class T>
Lista<T> Lista<T>::operator=(Lista L)
{
for(int i =0;i<L.iCant;i++)
    {
        this->arrDatos[i]=L.arrDatos[i];
    }
    this->iCant=L.iCant;
}

template<class T>
bool Lista<T>::operator==(Lista L)
{
    if(this-> iCant == L.iCant)
    {

        for(int i =0;i<this->iCant;i++)
        {
            if(this->arrDatos[i]!=L.arrDatos[i])
            {
                return false;
            }
        }
        return true;
    }

    else
    {
        return false;
    }
}

template<class T>
void Lista<T>::print()
{
    for(int i=0;i<iCant;i++)
    {
        cout<<i<<" - "<<arrDatos[i]<<endl;
    }
}


#endif // TAREAPORGRA_4_H_INCLUDED
