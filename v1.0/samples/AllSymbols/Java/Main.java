import model.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	    ContextImpl ctxTest = new ContextImpl( new Composition(4) );
	    int n;
	    do {
	        ctxTest.Start();
	        do {
	        	n = base.TopState.InputValue("Enter event number('q': quit, 'r':restart): E");
	        	if (n < ContextImpl._EventId.NUM.ordinal()) {
	        		ctxTest.EventProc(n, null);
	        	}
	        } while (n+'0' != 'q' && n+'0' != 'r');
	    }while (n+'0' != 'q');
	}

}
