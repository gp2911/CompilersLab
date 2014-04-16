package myClasses;

import syntaxtree.*;
import visitor.GJNoArguDepthFirst;

import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: GP
 * Date: 16/09/13
 * Time: 4:52 AM
 * To change this template use File | Settings | File Templates.
 */
public class InheritBuilder<R> extends GJNoArguDepthFirst<R> {
        Hashtable<String, ClassDetails> symbolTable;
        Hashtable<String,FuncDetails> currFuncTable, prevFuncTable;
        LinkedHashMap<String, VarDetails> currVarTable, prevVarTable;
        Hashtable<String,VarDetails> currFuncVarTable;
        Hashtable<String, ClassDetails> mySymTab;


        ClassDetails currClass=null, parentClass=null;
        FuncDetails currFunc=null;
        ArrayList<String> currArgList=null;
        ErrorHandler e = new ErrorHandler();

        int exprNum=1;
        boolean set=false;
        boolean returning = false;

        public void setSymbolTable(Hashtable<String, ClassDetails> h){
            symbolTable = h;
//            System.out.println(symbolTable);
        }

        public Hashtable<String,ClassDetails> getSymbolTable(){
            return symbolTable;
        }

    public Hashtable<String,ClassDetails> getSymTab(){
        return mySymTab;
    }

    public R visit(NodeList n) {
        R _ret=null;
        int _count=0;
        for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
            e.nextElement().accept(this);
            _count++;
        }
        return _ret;
    }

    public R visit(NodeListOptional n) {
        if ( n.present() ) {
            R _ret=null;
            int _count=0;
            for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
                e.nextElement().accept(this);
                _count++;
            }
            return _ret;
        }
        else
            return null;
    }

    public R visit(NodeOptional n) {
        if ( n.present() )
            return n.node.accept(this);
        else
            return null;
    }

    public R visit(NodeSequence n) {
        R _ret=null;
        int _count=0;
        for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
            e.nextElement().accept(this);
            _count++;
        }
        return _ret;
    }

    public R visit(NodeToken n) { return null; }

    //
    // User-generated visitor methods below
    //

    /**
     * f0 -> MainClass()
     * f1 -> ( TypeDeclaration() )*
     * f2 -> <EOF>
     */


    public R visit(Goal n) {
        R _ret=null;

//        System.out.println("-----------------inherit builder 1------------------------------------");
//        Iterator<String>f,j;
//        f = symbolTable.keySet().iterator();
//        while(f.hasNext()){
//            String key= f.next();
//            ClassDetails myClass = symbolTable.get(key);
//            j = myClass.classFuncs.keySet().iterator();
//            while (j.hasNext()){
//                String fname = j.next();
//                FuncDetails myFunc = myClass.classFuncs.get(fname);
//                System.out.println(myClass.name +" vars :"+ myClass.classVars);
////                System.out.println(myClass.name+"."+myFunc.name+" : "+myFunc.localVars);
//            }
//        }

        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
//        System.out.println("=========================");

//        System.out.println("-----------------inherit builder------------------------------------");
//        Iterator<String>f,j;
//        f = symbolTable.keySet().iterator();
//        while(f.hasNext()){
//            String key= f.next();
//            ClassDetails myClass = symbolTable.get(key);
//            j = myClass.classFuncs.keySet().iterator();
//            while (j.hasNext()){
//                String fname = j.next();
//                FuncDetails myFunc = myClass.classFuncs.get(fname);
//                System.out.println(myClass.name +" vars :"+ myClass.classVars);
////                System.out.println(myClass.name+"."+myFunc.name+" : "+myFunc.localVars);
//            }
//        }

        mySymTab  = new Hashtable<String, ClassDetails>();
        Iterator<String> it = symbolTable.keySet().iterator();
        while (it.hasNext()){
            String className = it.next();
//            System.out.println(className);
            ClassDetails myClass = symbolTable.get(className);
            ClassDetails tmp = new ClassDetails(myClass);
            mySymTab.put(className, tmp);

        }

//        System.out.println("-----------------inherit builder------------------------------------");
//        Iterator<String>f,j;
//        f = mySymTab.keySet().iterator();
//        while(f.hasNext()){
//            String key= f.next();
//            ClassDetails myClass = symbolTable.get(key);
//            j = myClass.classFuncs.keySet().iterator();
//            while (j.hasNext()){
//                String fname = j.next();
//                FuncDetails myFunc = myClass.classFuncs.get(fname);
//                System.out.println(myClass.name +" vars :"+ myClass.classVars);
////                System.out.println(myClass.name+"."+myFunc.name+" : "+myFunc.localVars);
//            }
//        }

//        System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>maami<<<<<<<<<<<<<<<<<<<<");


        return _ret;
    }

    /**
     * f0 -> "class"
     * f1 -> Identifier()
     * f2 -> "{"
     * f3 -> "public"
     * f4 -> "static"
     * f5 -> "void"
     * f6 -> "main"
     * f7 -> "("
     * f8 -> "String"
     * f9 -> "["
     * f10 -> "]"
     * f11 -> Identifier()
     * f12 -> ")"
     * f13 -> "{"
     * f14 -> PrintStatement()
     * f15 -> "}"
     * f16 -> "}"
     */
    public R visit(MainClass n) {
        R _ret=null;
        ClassDetails mainClass = symbolTable.get(n.f1.f0.toString()) ;
//        System.out.println(n.f1.f0.toString());
//        System.out.println(mainClass.name);
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        n.f4.accept(this);
        n.f5.accept(this);
        n.f6.accept(this);
        n.f7.accept(this);
        n.f8.accept(this);
        n.f9.accept(this);
        n.f10.accept(this);
        n.f11.accept(this);
        n.f12.accept(this);
        n.f13.accept(this);
        n.f14.accept(this);
        n.f15.accept(this);
        n.f16.accept(this);
        return _ret;
    }

    /**
     * f0 -> ClassDeclaration()
     *       | ClassExtendsDeclaration()
     */
    public R visit(TypeDeclaration n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> "class"
     * f1 -> Identifier()
     * f2 -> "{"
     * f3 -> ( VarDeclaration() )*
     * f4 -> ( MethodDeclaration() )*
     * f5 -> "}"
     */
    public R visit(ClassDeclaration n) {
        R _ret=null;
        ClassDetails prevClass = currClass;
        ClassDetails myClass = symbolTable.get(n.f1.f0.toString());
        ClassDetails tmp;
        //System.out.println(myClass+"========================&&&================");
        //myClass.isChild = false;
        //myClass.type = "class";
        n.f0.accept(this);
        set=true;
        //myClass.name=(String)n.f1.accept(this);
//        System.out.println(myClass.name);
        set=false;
        tmp = symbolTable.get(myClass.name);
        if(tmp == null)
            e.printError("Class does not exist");
        currClass = tmp;
        currFuncTable = tmp.classFuncs;
        currVarTable = tmp.classVars;
        n.f2.accept(this);
        n.f3.accept(this);
        n.f4.accept(this);
        n.f5.accept(this);
//        System.out.println(tmp.classFuncs);
        currClass = prevClass;
        if(prevClass==null){
            currVarTable = null;
            currFuncTable = null;
        }
        else{
            currVarTable = prevClass.classVars;
            currFuncTable = prevClass.classFuncs;
        }
        //symbolTable.put(tmp.name, tmp);
        return _ret;
    }

    /**
     * f0 -> "class"
     * f1 -> Identifier()
     * f2 -> "extends"
     * f3 -> Identifier()
     * f4 -> "{"
     * f5 -> ( VarDeclaration() )*
     * f6 -> ( MethodDeclaration() )*
     * f7 -> "}"
     */

    //TODO: Fix function over-riding problem.

    public R visit(ClassExtendsDeclaration n) {
        R _ret=null;
        ClassDetails prevClass = currClass;
        String className = n.f1.f0.toString();
        ClassDetails myClass = symbolTable.get(className);
        myClass.parentClass = symbolTable.get(myClass.parentClass.name);
        //myClass.isChild = false;
        //myClass.name=n.f1.f0.toString();
        //String parentName = n.f3.f0.toString();
//        System.out.println(symbolTable);
//        System.out.println(className);
//        System.out.println(myClass.name+"---------");
//        System.out.println(myClass.parentClass);
        LinkedHashMap<String,VarDetails> parentVars = myClass.parentClass.classVars;
//        System.out.println(parentVars+"-----");
        Hashtable<String,FuncDetails> parentFuncs = myClass.parentClass.classFuncs;
//
        //Iterator parentIterator=parentVars.keySet().iterator();
        //Iterator childKeysIterator=myClass.classVars.keySet().iterator();

        //

//        Iterator<String> parentKeysIterator = parentVars.keySet().iterator();

//        ArrayList<String> parentKeys = new ArrayList<String>(parentVars.keySet());
//        System.out.println(parentKeys+"<----");

        currClass = myClass;
        currVarTable = myClass.classVars;
        currFuncTable = myClass.classFuncs;

//        System.out.println("parentVars "+parentVars);
//        System.out.println("parentFuncs "+parentFuncs);
//        System.out.println(currVarTable);
//        System.out.println(currVarTable);

        Iterator<String> childFuncs = myClass.classFuncs.keySet().iterator();

        while(childFuncs.hasNext()){
            String fname = childFuncs.next();
            if( (parentFuncs.get(fname) != null) ) {
                myClass.classFuncs.get(fname).isOverridden = true;
            }
        }

        Iterator<String> childVars = myClass.classVars.keySet().iterator();

        while(childVars.hasNext()){
            String varName = childVars.next();
            if( (parentVars.get(varName) != null) ) {
                myClass.classVars.get(varName).isOverridden = true;
            }
        }

        if(parentVars!=null){
            Iterator<String> it = parentVars.keySet().iterator();
            while(it.hasNext()){
                String s = it.next();
                VarDetails myVar=parentVars.get(s);
                if(!myVar.isOverridden)   {
                    myClass.classVars.put(myVar.name, myVar);
                }
            }
        }
        if(parentFuncs!=null){
            Iterator<String> it = parentFuncs.keySet().iterator();
            while(it.hasNext()){
                String s = it.next();
                FuncDetails myFunc=parentFuncs.get(s);
                if(!myFunc.isOverridden)   {
                    myClass.classFuncs.put(myFunc.name, myFunc);
                }
            }
        }
//        System.out.println(currVarTable);
//        System.out.println(currFuncTable);
//        System.out.println("jjj-----");

        n.f0.accept(this);
        set=true;
        n.f1.accept(this);
        set=false;
        n.f2.accept(this);

        //String parentName = (String)n.f3.accept(this);
        //myClass.parentClass= symbolTable.get(parentName);
        //myClass.parentClass.children.add(myClass);

        n.f4.accept(this);
        //currClass = myClass;
        n.f5.accept(this);
        n.f6.accept(this);
        n.f7.accept(this);
        //currClass = null;
        symbolTable.put(n.f1.toString(), myClass);
        currClass = prevClass;
        if(prevClass==null){
            currVarTable = null;
            currFuncTable = null;
        }
        else{
            currVarTable = prevClass.classVars;
            currFuncTable = prevClass.classFuncs;
        }
        return _ret;
    }

    /**
     * f0 -> Type()
     * f1 -> Identifier()
     * f2 -> ";"
     */
    public R visit(VarDeclaration n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        return _ret;
    }

    /**
     * f0 -> "public"
     * f1 -> Type()
     * f2 -> Identifier()
     * f3 -> "("
     * f4 -> ( FormalParameterList() )?
     * f5 -> ")"
     * f6 -> "{"
     * f7 -> ( VarDeclaration() )*
     * f8 -> ( Statement() )*
     * f9 -> "return"
     * f10 -> Expression()
     * f11 -> ";"
     * f12 -> "}"
     */

    public R visit(MethodDeclaration n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        n.f4.accept(this);
        n.f5.accept(this);
        n.f6.accept(this);
        n.f7.accept(this);
        n.f8.accept(this);
        n.f9.accept(this);
        n.f10.accept(this);
        n.f11.accept(this);
        n.f12.accept(this);
        return _ret;
    }
    /**
     * f0 -> FormalParameter()
     * f1 -> ( FormalParameterRest() )*
     */
    public R visit(FormalParameterList n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        return _ret;
    }

    /**
     * f0 -> Type()
     * f1 -> Identifier()
     */
    public R visit(FormalParameter n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        return _ret;
    }

    /**
     * f0 -> ","
     * f1 -> FormalParameter()
     */
    public R visit(FormalParameterRest n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        return _ret;
    }

    /**
     * f0 -> ArrayType()
     *       | BooleanType()
     *       | IntegerType()
     *       | Identifier()
     */
    public R visit(Type n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> "int"
     * f1 -> "["
     * f2 -> "]"
     */
    public R visit(ArrayType n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        return _ret;
    }

    /**
     * f0 -> "boolean"
     */
    public R visit(BooleanType n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> "int"
     */
    public R visit(IntegerType n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> Block()
     *       | AssignmentStatement()
     *       | ArrayAssignmentStatement()
     *       | IfStatement()
     *       | WhileStatement()
     *       | PrintStatement()
     */
    public R visit(Statement n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> "{"
     * f1 -> ( Statement() )*
     * f2 -> "}"
     */
    public R visit(Block n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        return _ret;
    }

    /**
     * f0 -> Identifier()
     * f1 -> "="
     * f2 -> Expression()
     * f3 -> ";"
     */
    public R visit(AssignmentStatement n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        return _ret;
    }

    /**
     * f0 -> Identifier()
     * f1 -> "["
     * f2 -> Expression()
     * f3 -> "]"
     * f4 -> "="
     * f5 -> Expression()
     * f6 -> ";"
     */
    public R visit(ArrayAssignmentStatement n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        n.f4.accept(this);
        n.f5.accept(this);
        n.f6.accept(this);
        return _ret;
    }

    /**
     * f0 -> "if"
     * f1 -> "("
     * f2 -> Expression()
     * f3 -> ")"
     * f4 -> Statement()
     * f5 -> "else"
     * f6 -> Statement()
     */
    public R visit(IfStatement n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        n.f4.accept(this);
        n.f5.accept(this);
        n.f6.accept(this);
        return _ret;
    }

    /**
     * f0 -> "while"
     * f1 -> "("
     * f2 -> Expression()
     * f3 -> ")"
     * f4 -> Statement()
     */
    public R visit(WhileStatement n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        n.f4.accept(this);
        return _ret;
    }

    /**
     * f0 -> "System.out.println"
     * f1 -> "("
     * f2 -> Expression()
     * f3 -> ")"
     * f4 -> ";"
     */
    public R visit(PrintStatement n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        n.f4.accept(this);
        return _ret;
    }

    /**
     * f0 -> AndExpression()
     *       | CompareExpression()
     *       | PlusExpression()
     *       | MinusExpression()
     *       | TimesExpression()
     *       | ArrayLookup()
     *       | ArrayLength()
     *       | MessageSend()
     *       | PrimaryExpression()
     */
    public R visit(Expression n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> PrimaryExpression()
     * f1 -> "&"
     * f2 -> PrimaryExpression()
     */
    public R visit(AndExpression n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        return _ret;
    }

    /**
     * f0 -> PrimaryExpression()
     * f1 -> "<"
     * f2 -> PrimaryExpression()
     */
    public R visit(CompareExpression n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        return _ret;
    }

    /**
     * f0 -> PrimaryExpression()
     * f1 -> "+"
     * f2 -> PrimaryExpression()
     */
    public R visit(PlusExpression n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        return _ret;
    }

    /**
     * f0 -> PrimaryExpression()
     * f1 -> "-"
     * f2 -> PrimaryExpression()
     */
    public R visit(MinusExpression n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        return _ret;
    }

    /**
     * f0 -> PrimaryExpression()
     * f1 -> "*"
     * f2 -> PrimaryExpression()
     */
    public R visit(TimesExpression n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        return _ret;
    }

    /**
     * f0 -> PrimaryExpression()
     * f1 -> "["
     * f2 -> PrimaryExpression()
     * f3 -> "]"
     */
    public R visit(ArrayLookup n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        return _ret;
    }

    /**
     * f0 -> PrimaryExpression()
     * f1 -> "."
     * f2 -> "length"
     */
    public R visit(ArrayLength n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        return _ret;
    }

    /**
     * f0 -> PrimaryExpression()
     * f1 -> "."
     * f2 -> Identifier()
     * f3 -> "("
     * f4 -> ( ExpressionList() )?
     * f5 -> ")"
     */
    public R visit(MessageSend n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        n.f4.accept(this);
        n.f5.accept(this);
        return _ret;
    }

    /**
     * f0 -> Expression()
     * f1 -> ( ExpressionRest() )*
     */
    public R visit(ExpressionList n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        return _ret;
    }

    /**
     * f0 -> ","
     * f1 -> Expression()
     */
    public R visit(ExpressionRest n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        return _ret;
    }

    /**
     * f0 -> IntegerLiteral()
     *       | TrueLiteral()
     *       | FalseLiteral()
     *       | Identifier()
     *       | ThisExpression()
     *       | ArrayAllocationExpression()
     *       | AllocationExpression()
     *       | NotExpression()
     *       | BracketExpression()
     */
    public R visit(PrimaryExpression n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> <INTEGER_LITERAL>
     */
    public R visit(IntegerLiteral n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> "true"
     */
    public R visit(TrueLiteral n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> "false"
     */
    public R visit(FalseLiteral n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> <IDENTIFIER>
     */
    public R visit(Identifier n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> "this"
     */
    public R visit(ThisExpression n) {
        R _ret=null;
        n.f0.accept(this);
        return _ret;
    }

    /**
     * f0 -> "new"
     * f1 -> "int"
     * f2 -> "["
     * f3 -> Expression()
     * f4 -> "]"
     */
    public R visit(ArrayAllocationExpression n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        n.f4.accept(this);
        return _ret;
    }

    /**
     * f0 -> "new"
     * f1 -> Identifier()
     * f2 -> "("
     * f3 -> ")"
     */
    public R visit(AllocationExpression n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        n.f3.accept(this);
        return _ret;
    }

    /**
     * f0 -> "!"
     * f1 -> Expression()
     */
    public R visit(NotExpression n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        return _ret;
    }

    /**
     * f0 -> "("
     * f1 -> Expression()
     * f2 -> ")"
     */
    public R visit(BracketExpression n) {
        R _ret=null;
        n.f0.accept(this);
        n.f1.accept(this);
        n.f2.accept(this);
        return _ret;
    }

}


