/* File generated by Đức's ClasHStamP */
package abstracts;

import java.io.*;
import java.util.*;

public  abstract class BaseClass
{
    public abstract void publicMethod(
    );
    void setDerivableAttribute(int value){
        derivableAttribute = value;
    }
    protected abstract void protectedMethod(
    );
    protected abstract void packageVisibleMethod(
    );
    public  BaseClass(
        int _derivableAttribute
    ){
        derivableAttribute = _derivableAttribute;
    }                                                                                           
    private int derivableAttribute;                             
}
