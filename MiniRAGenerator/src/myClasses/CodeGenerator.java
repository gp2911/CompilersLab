package myClasses;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created with IntelliJ IDEA.
 * User: GP
 * Date: 25/09/13
 * Time: 9:20 PM
 * To change this template use File | Settings | File Templates.
 */
public class CodeGenerator {
    String code;
    int indent;
    public  void addCodeLine(String s){
        for(int i=0; i< indent; i++){
            code = code + " ";
        }
        while (s.startsWith("\n"))
            s = s.substring(1);
        code = code + s;
        code = code + "\n";
    }
    public  void addCodeLine1(String s){
        for(int i=0; i< indent; i++){
            code = code + " ";
        }
        while (s.startsWith("\n"))
            s = s.substring(1);
        code = code + s;
//        code = code + "\n";
    }
    public void addCode(String s){
        code = code + s;
    }

    public void addLabel(String label){
        code = code + "\n";
        addCode(label + "  ");
    }
    public  void addCode(String s, int i){
        if(s == ""){
            code = code + "\nNULL";
            return;
        }
        for(int j=0; j< i; j++){
            code = code + " ";
        }

        code = code + s;
    }
    public CodeGenerator(int i, String c){
        code = c;
        indent = i;
    }

    public CodeGenerator(int i){
        code = "";
        indent = i;
    }

    public CodeGenerator(){
        code = "";
        indent = 0;
    }
}
