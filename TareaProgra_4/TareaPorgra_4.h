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
    Lista(Lista);
    int getCant();
    T getDato(int iIndice);
    bool add(T dato)
    void sort(bool bFlag);
    Lista operator=( Lista);
    bool operator==(Lista);
    void print();
};

template<class T>
Lista::Lista()
{
    iCant=0;
}

template<class T>
Lista::Lista(&Lista)
{
    this->Lista.arrDatos[]=Lista.arrDatos[];
}

template<class T>
int Lista::getCant()
{
    return iCant;
}

template<class T>
T Lista::getDatos(int iIndice)
{
    return arrDatos[i];
}

template<class T>
bool Lista::add(T dato)
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
void Lista::sort(bool bFlag)
{
    bool bInterruptor;
    T datoAux;
    if(bFlag==true)
    {
        for(int i=0 i<=iCant-1&&bInterruptor=true; i++)
        {
            bInterruptor=false;
            for(int j=0;j<10-iCant;j++)
            {
                if(arrDatos[j+1]<arrDatos[j])
                {
                    datoAux = arrDatos[j];
                    arrDatos[j]=arDatos[j+1];
                    arDatos[j+1]=datoAux;
                    bInterruptor=true;
                }
            }
        }
    }

    if(bFlag==false)
    {
         for(int i=0 i<=iCant-1&&bInterruptor=true; i++)
        {
            bInterruptor=false;
            for(int j=0;j<10-iCant;j++)
            {
                if(arrDatos[j+1]>arrDatos[j])
                {
                    datoAux = arrDatos[j];
                    arrDatos[j]=arDatos[j+1];
                    arDatos[j+1]=datoAux;
                    bInterruptor=true;

                }
            }
        }
    }
}

template<class T>
Lista Lista::operator=(Lista)
{
    this->Lista.arrDatos=Lista.arrDatos;
    this->Lista.iCant=Lista.iCant;
}

template<class T>
bool Lista::operator++(Lista)
{
    bool bFlag=false;
    if(this->Lista.arrDatos==Lista.arrDatos&&this->Lista.iCant==Lista.iCant)
    {
        bFlag=true;
    }
    return bFlag;
}

template<class T>
void Lista::print
{
    for(int i=0;i<iCant;i++)
    {
        cout<<iCant<<" - "<<arrDatos[i]<<endl;
    }
}


#endif // TAREAPORGRA_4_H_INCLUDED
