/**
 * Created with IntelliJ IDEA.
 * User: GP
 * Date: 25/09/13
 * Time: 5:22 PM
 * To change this template use File | Settings | File Templates.
 */

import syntaxtree.*;
import visitor.*;
import myClasses.*;

import java.util.*;

import myClasses.TableConstructor;
import myClasses.TypeChecker;

public class Main {
    public static void main(String [] args) {
        try {
            Node root = new MiniJavaParser(System.in).Goal();
            int pass=0;
            //System.out.println("Program parsed successfully");
            TableConstructor tc = new TableConstructor();
            root.accept(tc); // Your assignment part is invoked here.
            //Hashtable<String,ClassDetails> symbolTable = new Hashtable();
            InheritBuilder inheritBuilder = new InheritBuilder();
            inheritBuilder.setSymbolTable(tc.getSymbolTable());
            root.accept(inheritBuilder);
            TypeChecker check = new TypeChecker();
            check.setSymbolTable(inheritBuilder.getSymbolTable());
            root.accept(check);
            FunctionCoder functionCoder = new FunctionCoder();
            functionCoder.setSymbolTable(inheritBuilder.getSymbolTable());
            root.accept(functionCoder);
            MsgSendCoder msgSender = new MsgSendCoder();
            msgSender.setSymbolTable(inheritBuilder.getSymTab());
            msgSender.setTempVarMapping(functionCoder.getTempVarMapping());
            root.accept(msgSender);
            CodePrinter codePrinter = new CodePrinter();
            codePrinter.setSymbolTable(inheritBuilder.getSymTab());
            codePrinter.setTempVarMapping(msgSender.getTempVarMapping());
            root.accept(codePrinter);
//            System.out.println("Program type checked successfully");
        }
        catch (ParseException e) {
            System.out.println(e.toString());
        }
    }
}










