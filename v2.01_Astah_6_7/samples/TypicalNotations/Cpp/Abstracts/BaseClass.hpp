#pragma once
/* File generated by Đức's ClasHStamP */
#include "Generic/CommonInclude.h"

class BaseClass{
    public: virtual void publicMethod(
    ) = 0;
    protected: int derivableAttribute;
    private: struct { BaseClass* pContainer; friend BaseClass;
        int& operator = (const int& value) { pContainer->setDerivableAttribute(value); }
    } m_derivableAttribute;
    protected: virtual int getDerivableAttribute() const { return derivableAttribute; }
    protected: virtual int& setDerivableAttribute(const int& value) { return derivableAttribute = value; }
    protected: virtual void protectedMethod(
    ) = 0;
    protected: virtual void packageVisibleMethod(
    ) = 0;
    public:  BaseClass(
        int _derivableAttribute
    ): derivableAttribute( _derivableAttribute )
    {
    }                                                                                           
};