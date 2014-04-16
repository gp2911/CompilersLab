package myClasses;

/**
 * Created with IntelliJ IDEA.
 * User: GP
 * Date: 25/09/13
 * Time: 7:14 PM
 * To change this template use File | Settings | File Templates.
 */
public class FuncCode {
    String funcName;
    String funcCode;
//    int noOfParams;
    int retVal;

    public FuncCode(String s1, String s2){
        funcName = s1;
        funcCode = s2;
//        noOfParams = i;
        retVal = 0;
    }

    public FuncCode(){
        funcName = "";
        funcCode = "";
//        noOfParams = 0;
    }
}
