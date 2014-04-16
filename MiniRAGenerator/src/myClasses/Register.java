package myClasses;

/**
 * Created with IntelliJ IDEA.
 * User: GP
 * Date: 21/10/13
 * Time: 4:26 PM
 * To change this template use File | Settings | File Templates.
 */
public class Register implements Comparable<Register>{
    public int regNo;
    public char type;
    public boolean justFreed;

    public Register(int i){
        regNo = i;
        justFreed = false;
        if(regNo < 10)
            type = 't';
        else if(regNo < 18)
            type = 's';
        else
            type = 'x';

    }

    public Register(char c, int i){
        regNo = i;
        type = c;
    }

    public int compareTo(Register register){
        return this.regNo - register.regNo;
    }

    public String regCode(Register buff){
        String str = "";
        if(type == 'x')
            str ="ALOAD "+buff.toString()+" SPILLEDARG "+Integer.toString(regNo-18);
        else
            str = null;
        return str;
    }
    public String toString(){
        String reg = "";
        reg = reg + Character.toString(type);
        if(type != 'x')
            reg = reg + Integer.toString(regNo%10);
        else
            reg = reg + Integer.toString(regNo - 18);
        return reg;
    }

}
