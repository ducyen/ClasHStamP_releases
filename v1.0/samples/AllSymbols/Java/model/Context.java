package model;

import model.*;
import interfaces.*;

public class Context extends BaseClass implements Interface2, Interface1
{
    public void virtualFunc(
        int param0
    ){
    } /* Context.virtualFunc */

    public  static void staticFunc(

    ){
    } /* Context.staticFunc */
    public void leafFunc(

    ){
    } /* Context.leafFunc */
    public void operation1(

    ){
    } /* Context.operation1 */
    public void operation2(

    ){
    } /* Context.operation2 */
    public  Context(
        int _attribute0,
        Composition _aComposition
    ) {
        super(  );

        attribute1 = 345;
        attribute0 = _attribute0;
        anAggregation = null;
        aComposition = _aComposition;
    }                                                                                           
    private  int attribute1;                                    
    private  int attribute0;                                    
    private  Aggregration anAggregation;                        
    private  Composition aComposition;                          
}
