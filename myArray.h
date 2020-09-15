#ifndef MYARRAY_H_INCLUDED
#define MYARRAY_H_INCLUDED
#include "stdafx.h"
template<class T>
class myArray
{
    //member of data
private:
    int _nSize = 0;     //记录动态数组当前的长度
    T * _ptrData = nullptr; //指向动态数组的指针
    int _ncapacity = 10;

    //member of function
public:
    //ctor
    myArray():_ptrData(nullptr),_nSize(0){}
    myArray(int m,T nvalue=0) //如果m是<=0那咋办
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
        //开辟空间
        _ptrData = new T[obj._nSize];
        //赋值
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
        //自我赋值判断 self assignment
        if(this->_ptrData == obj._ptrData){return *this;}

        //1.删除原有空间
        if(_ptrData){delete [] _ptrData;_ptrData = nullptr;}
        //2.
        if(obj._ptrData != nullptr)
        {
            T * ptemp = new T[obj._nSize];
            //3.将objb中的内容拷贝过来
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
    //获取数组长度
    int getLenth()const{return _nSize;}
    //只是读取出来
    T & At(int npos)
    {
        if(npos < 0 || npos > _nSize-1)
        {
            throw  1;//异常处理
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
        //如果原来一个元素都没有，指针为空
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

            //释放原有空间
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
