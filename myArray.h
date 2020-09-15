#ifndef MYARRAY_H_INCLUDED
#define MYARRAY_H_INCLUDED
#include "stdafx.h"
template<class T>
class myArray
{
    //member of data
private:
    int _nSize = 0;     //��¼��̬���鵱ǰ�ĳ���
    T * _ptrData = nullptr; //ָ��̬�����ָ��
    int _ncapacity = 10;

    //member of function
public:
    //ctor
    myArray():_ptrData(nullptr),_nSize(0){}
    myArray(int m,T nvalue=0) //���m��<=0��զ��
    {
        _nSize = m>0 ? m : 1;
        _ptrData = new T[_nSize];

        for(int i=0;i<_nSize;++i)
        {
            _ptrData[i] = nvalue;
        }
    }

    //copy ctor
    myArray(const myArray & obj)
    {
        //���ٿռ�
        _ptrData = new T[obj._nSize];
        //��ֵ
        for(int i=0;i<obj._nSize;++i)
        {
            _ptrData[i] = obj._ptrData[i];
        }
        //obj._ptrData;
        _nSize = obj._nSize;
    }

    //copy assignment
    //a=b
    myArray & operator=(const myArray & obj)
    {
        //���Ҹ�ֵ�ж� self assignment
        if(this->_ptrData == obj._ptrData){return *this;}

        //1.ɾ��ԭ�пռ�
        if(_ptrData){delete [] _ptrData;_ptrData = nullptr;}
        //2.
        if(obj._ptrData != nullptr)
        {
            T * ptemp = new T[obj._nSize];
            //3.��objb�е����ݿ�������
            for(int i=0; i<obj._nSize; ++i)
            {
                ptemp[i] = obj._ptrData[i];
            }
            _ptrData = ptemp;
        }
        _nSize = obj._nSize;

        return *this;
    }

    //dtor
    ~myArray()
    {
        if(_ptrData)
        {
            delete [] _ptrData;
            _ptrData = nullptr;
        }
    }

public:
    //function
    //��ȡ���鳤��
    int getLenth()const{return _nSize;}
    //ֻ�Ƕ�ȡ����
    T & At(int npos)
    {
        if(npos < 0 || npos > _nSize-1)
        {
            throw  1;//�쳣����
        }
        return _ptrData[npos];
    }
    T & operator[](int npos)
    {
        return _ptrData[npos];//5 [0,4]
    }
//    int ar[5];
//    ar[1] = 7;[] <=>*(ar+1)

    bool pushback(T & nvalue)
    {
        _nSize += 1;
        //���ԭ��һ��Ԫ�ض�û�У�ָ��Ϊ��
        if(_ptrData == nullptr)
        {
            _ptrData = new T[_nSize];
            if(_ptrData == nullptr){return false;}
            _ptrData[0] = nvalue;
        }
        else
        {
            int * ptemp = new T[_nSize];
            if(ptemp == nullptr){return false;}
            for(int i=0; i<_nSize-1; ++i)
            {
                ptemp[i] = _ptrData[i];
            }
            ptemp[_nSize-1] = nvalue;

            //�ͷ�ԭ�пռ�
            if(_ptrData)
            {
                delete [] _ptrData;
            }
            _ptrData = ptemp;
            ptemp = nullptr;
        }


    }
};


#endif // MYARRAY_H_INCLUDED
