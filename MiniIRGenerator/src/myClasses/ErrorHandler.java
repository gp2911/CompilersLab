package myClasses;

public class ErrorHandler {
	public void printError(){
		System.out.println("Type error");
		System.exit(1);
	}
	
	public void printError(String s){
		System.out.println("Type Error : "+s);
		System.out.println(" : " + s);
        printError();
		System.exit(1);
	}

}