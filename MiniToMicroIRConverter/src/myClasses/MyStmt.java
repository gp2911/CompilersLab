package myClasses;

/**
 * Created with IntelliJ IDEA.
 * User: GP
 * Date: 26/09/13
 * Time: 3:04 PM
 * To change this template use File | Settings | File Templates.
 */
public class MyStmt {
    String code;
    int nextLabel;
    int label;
    int ifTrueLabel;
    int ifFalseLabel;
    int retVal;
    String moveCode;
    boolean isClassAlloc;
    boolean isNewSend;
    String info;

    public MyStmt(){
        code = "";
        nextLabel = 0;
        ifFalseLabel = 0;
        ifTrueLabel = 0;
        retVal = -1;
        moveCode = "";
        isClassAlloc = false;
        info = "";
    }
}


