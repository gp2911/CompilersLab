package myClasses;
import java.util.*;
import java.lang.*;

import myClasses.*;
import syntaxtree.*;
import visitor.GJNoArguVisitor;


/*
 *  STATUS:
  *     ALL PROGRAMS WORK!! :D
  *
  *     Note: Function over-riding is not being supported. Fix it.
  *
 */


public class TypeChecker<R> implements GJNoArguVisitor<R> {

	Hashtable<String, ClassDetails> symbolTable;
	Hashtable<String,FuncDetails> currFuncTable, prevFuncTable;
	LinkedHashMap<String,VarDetails> currVarTable, prevVarTable;
	Hashtable<String,VarDetails> currFuncVarTable;
	

	
	ClassDetails currClass, parentClass;
	FuncDetails currFunc;
	ArrayList<String> currArgList=null;
	ErrorHandler e = new ErrorHandler();
	
	int exprNum=1;
	boolean set=false;
	boolean returning = false;
	public void setSymbolTable(Hashtable<String, ClassDetails> h){
		symbolTable = h;
//		System.out.println(symbolTable);
	}
    public Hashtable<String,ClassDetails> getSymbolTable(){
        return  symbolTable;
    }
	
	//
	// Auto class visitors--probably don't need to be overridden.
	//
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
//        System.out.println("=========================");
		
		   currClass=null;
		   currFuncTable=null;
		   currVarTable=null;
		   currFunc=null;
		
//		System.out.println("Parsing Goal...");
		//System.out.println(symbolTable);
		R _ret=null;
		n.f0.accept(this);
		n.f1.accept(this);
		n.f2.accept(this);

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
	 * f11 -> Identifier	)
	 * f12 -> ")"
	 * f13 -> "{"
	 * f14 -> PrintStatement()
	 * f15 -> "}"
	 * f16 -> "}"
	 */
	public R visit(MainClass n) {
		ClassDetails prevClass = currClass;
		String mainName = n.f1.f0.toString();
		//System.out.println(mainName);
		//currFuncVarTable=null;
		ClassDetails main = symbolTable.get(n.f1.f0.toString());
		currClass = main;
		currVarTable = main.classVars;
		currFuncTable = main.classFuncs;
		R _ret=null;
		n.f0.accept(this);
		set=true;
		main.name = (String)n.f1.accept(this);
		set=false;
		n.f2.accept(this);
		n.f3.accept(this);
		n.f4.accept(this);
		n.f5.accept(this);
		n.f6.accept(this);
		n.f7.accept(this);
		n.f8.accept(this);
		n.f9.accept(this);
		n.f10.accept(this);
		set=true;
		n.f11.accept(this);
		set=false;
		n.f12.accept(this);
		n.f13.accept(this);
		n.f14.accept(this);
		n.f15.accept(this);
		n.f16.accept(this);
		symbolTable.put(main.name, main);
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
//		System.out.println(myClass.name);
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
//		System.out.println(tmp.classFuncs);
//        System.out.println("øøøøøøøøøøøøøøøøøøøøøøøøøøøøøøøøøøøøøøø");
//        VarDetails myVar;
//        System.out.println("In class...");
//        Iterator<String> varDetailsIterator = currClass.classVars.keySet().iterator()    ;
//        while (varDetailsIterator.hasNext())                          {
//            myVar = currClass.classVars.get(varDetailsIterator.next());
//            System.out.println(myVar.name);
//        }
//        System.out.println("πππππππππππππππππππππππππππππππππππππππππßßß");

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
	public R visit(ClassExtendsDeclaration n) {
		R _ret=null;
		ClassDetails prevClass = currClass;
        String className = n.f1.f0.toString();
		ClassDetails myClass = symbolTable.get(className);
		//myClass.isChild = false;
		//myClass.name=n.f1.f0.toString();
		//String parentName = n.f3.f0.toString();
////        System.out.println(symbolTable);
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
        if(parentVars!=null)
            currVarTable.putAll(parentVars);
        if(parentFuncs!=null)
            currFuncTable.putAll(parentFuncs);
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
		if(currFunc != null){
			//set = true;
			//Hashtable<String, VarDetails> funcVars = new Hashtable<String, VarDetails>();
			//funcVars.putAll(currVarTable);
			//Hashtable prevVarTable = currVarTable;
			//Hashtable <String,VarDetails> funcVars=new Hashtable<String,VarDetails>();
			//if(currVarTable != null)
			//	funcVars.putAll(currVarTable);
			VarDetails myVar = new VarDetails();
			myVar.name = n.f1.f0.toString();
			myVar.type = (String)n.f0.accept(this);
			myVar.containingClass = currClass.name;
			myVar.containingFunction = currFunc.name;
			VarDetails x = currVarTable.get(myVar.name);
			if(x == null) {
				currVarTable.put(myVar.name, myVar);
            }
			else{
				currVarTable.remove(myVar.name);
				currVarTable.put(myVar.name, myVar);
			}
			x = currVarTable.get(myVar.name);
//			System.out.println(x.name + " : " + x.type);
		}

		set=true;
		n.f1.accept(this);
		set = false;
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
		LinkedHashMap<String, VarDetails> prevVarTable = currVarTable;
		// prevVarTable.putAll(currVarTable);
		currVarTable = new LinkedHashMap<String, VarDetails>(  );
		//System.out.println("Class vars : "+currClass.classVars);
		//System.out.println(currClass.name);
		if(currClass.classVars != null)
			currVarTable.putAll(currClass.classVars);
//        Hashtable<String, VarDetails> initHash = new Hashtable<String, VarDetails>();
//        initHash.putAll(currVarTable);
		//currVarTable.putAll(prevVarTable);
		//System.out.println("<========================>");
		//System.out.println(currVarTable);
		//if(currVarTable == null)
		//		currVarTable = new Hashtable<String, VarDetails>();
		//System.out.println(currVarTable);
		String funcName = n.f2.f0.toString();
		//System.out.println(funcName);
		//System.out.println(currClass.classFuncs);
		FuncDetails myFunc = currClass.classFuncs.get(funcName);
		//System.out.println(myFunc+"----------$---$------------");
		//System.out.println(myFunc.name);

		//currVarTable = myFunc.localVars;
		//if(currClass.classVars!=null)
		//	currVarTable.putAll(currClass.classVars);
		//myFunc.name = n.f2.f0.toString();
		//myFunc.containingClass = currClass.name;
		currFunc = myFunc;	
		//System.out.println("--------------------------------");
//        System.out.println("•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••");
//        System.out.println("Tryig to match function "+ myFunc.name);
		n.f0.accept(this);
		//myFunc.returnType =(String) n.f1.accept(this);
		n.f1.accept(this);
		set=true;
		n.f2.accept(this);
		set=false;
//		System.out.println("--------------------------------");
//		System.out.println(currVarTable);
		n.f3.accept(this);
		n.f4.accept(this);
		n.f5.accept(this);
		//System.out.println("<========================>>>");

//        System.out.println("--------------------------------");
		n.f6.accept(this);
		n.f7.accept(this);
//        System.out.println(currVarTable);
		n.f8.accept(this);
		n.f9.accept(this);
//		System.out.println("return encountered from "+ myFunc.name);
		returning=true;



        String returnType = (String)n.f10.accept(this);
		String reqdType = currClass.classFuncs.get(myFunc.name).returnType;
		if(!returnType.equals(reqdType)){
			VarDetails tmp = currVarTable.get(returnType);
			if(tmp==null){
				e.printError("Return type mismatch"+ returnType);
			}
			else if(tmp.type != reqdType){
				e.printError("Return type mismatch"+ tmp.type);
			}
		}
		returning=false;
		n.f11.accept(this);
		n.f12.accept(this);
        currFunc.localVars = currVarTable;
		//currVarTable = currFuncVarTable;
       	currFunc=null;



        //currFuncTable.put(myFunc.name, myFunc);
		FuncDetails x = (FuncDetails)currFuncTable.get(myFunc.name);
//		System.out.println(x.name.toString()+" : " + x.containingClass.toString());

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
//        System.out.println("trying to match param with currArgLsit :"+ currArgList + " for function"+ currFunc.name);
		R _ret=null;
		VarDetails myParam = new VarDetails();
		myParam.isParam=true;
		myParam.name = n.f1.f0.toString();
		myParam.type=(String)n.f0.accept(this);
		
//		System.out.println("----------"+myParam.type);
		//System.out.println(currFunc.name.toString());
//		System.out.println(myParam.name +" : "+ myParam.type);
		if (currFunc.argumentTypes==null)
			currFunc.argumentTypes = new ArrayList();
		//currFunc.argumentTypes.add(myParam.type);
		currVarTable.put(myParam.name, myParam);
		//System.out.println(currVarTable);
		set=true;
		n.f1.accept(this);
		set=false;
		return _ret;
	}

	/**
	 * f0 -> ","
	 * f1 -> FormalParameter()
	 */
	public R visit(FormalParameterRest n) {
		R _ret=null;
		n.f0.accept(this);
		set=true;
		n.f1.accept(this);
		set=false;
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
		//n.f0.accept(this);
        if(n.f0.which == 3){
            String type = (String)n.f0.accept(this);
            ClassDetails tmp = symbolTable.get(type);
            if(tmp == null)
                e.printError("Unknown class in Type");
            return (R) tmp.name;
        }
		return n.f0.accept(this);
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
		return (R)"int[]";
	}

	/**
	 * f0 -> "boolean"
	 */
	public R visit(BooleanType n) {
		R _ret=null;
		n.f0.accept(this);
		return (R)"boolean";
	}

	/**
	 * f0 -> "int"
	 */
	public R visit(IntegerType n) {
		R _ret=null;
		n.f0.accept(this);
		return (R)"int";
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
		//currVarTable = currClass.classVars;
		//System.out.println(currClass.name+"<-`-`-`-`-`-`-`-`-`-`-`-`-");
		//System.out.println(currVarTable+"<---------------------");
		String varName=n.f0.f0.toString();
		VarDetails myVar = currVarTable.get(varName);
//        System.out.println("CurrVarTable = "+currVarTable);
		Details exprType=new Details();
		exprType.name="expression"+String.valueOf(exprNum);
		String type=(String)n.f0.accept(this);
//        System.out.println(myVar.name +" : "+myVar.type);
		n.f1.accept(this);
		exprType.type=(String)n.f2.accept(this);
        if(exprType.type.equals("this")){
//            System.out.println("this = "+currClass.name);
        }
//		System.out.println("----------------"+myVar.type+"  :  "+exprType.type);
		if(myVar.type.equals(exprType.type)==false){
			e.printError("Assignment mismatch");
		}
//		System.out.println(exprType.type);
		return (R) exprType.type;

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
	
	int arrayIndexNum = 1;
	public R visit(ArrayAssignmentStatement n) {
		R _ret=null;
		Details arrayIndex = new Details();
		Details exprValue = new Details();
		arrayIndex.name = "arrayIndex"+String.valueOf(arrayIndexNum);
		arrayIndexNum++;
		exprValue.name = "expression"+String.valueOf(exprNum);
		exprNum++;
		n.f0.accept(this);
		n.f1.accept(this);
		arrayIndex.type=(String)n.f2.accept(this);
		if(arrayIndex.type.equals("int") == false)
			e.printError("illegal array index");
		n.f3.accept(this);
		n.f4.accept(this);
		exprValue.type = (String)n.f5.accept(this);
		if(exprValue.type.equals("int") == false)
			e.printError("type mismatch in array allocation");
		n.f6.accept(this);
		return (R) "int";
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
	
	int condNum =1;
	public R visit(IfStatement n) {
		R _ret=null;
		Details ifExpr = new Details();
		ifExpr.name = "ifExpr"+String.valueOf(condNum);
		condNum++;
		n.f0.accept(this);
		n.f1.accept(this);
		ifExpr.type = (String)n.f2.accept(this);
		if(ifExpr.type.equals("boolean") == false)
			e.printError("if condition not boolean");
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
		Details exprType = new Details();
		exprType.name = "expression"+String.valueOf(exprNum);
		exprNum++;
		n.f0.accept(this);
		n.f1.accept(this);
		exprType.type=(String)n.f2.accept(this);
		if(exprType.type.equals("boolean")==false)
				e.printError("while condition not boolean");
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
		String s = (String)n.f2.accept(this);
		if(s.equals("int") == false)
			e.printError("non-integer print string");
		n.f3.accept(this);
		n.f4.accept(this);
		return _ret;
	}

	/**
	 * f0 -> AndExpression()		0
	 *       | CompareExpression()	1
	 *       | PlusExpression()		2
	 *       | MinusExpression()	3
	 *       | TimesExpression()	4
	 *       | ArrayLookup()		5
	 *       | ArrayLength()		6
	 *       | MessageSend()		7	
	 *       | PrimaryExpression()	8
	 */
	public R visit(Expression n) {
		R _ret=null;
		String type = (String) n.f0.accept(this);
//		System.out.println("Expr choice : "+ n.f0.which);
		//System.out.println(currVarTable+"<---------------------");
		//currVarTable=currClass.classVars;
		//VarDetails myVar = currVarTable.get(type);
		return (R) type;
	}

	/**
	 * f0 -> PrimaryExpression()
	 * f1 -> "&"
	 * f2 -> PrimaryExpression()
	 */
	public R visit(AndExpression n) {
		R _ret=null;
		String type1 = (String) n.f0.accept(this);
		n.f1.accept(this);
		String type2 = (String)n.f2.accept(this);
		if ((!(type1.equals("boolean")&&(type2.equals("boolean")))) && !(type1.equals("int")&&(type2.equals("int")))){
			e.printError("AndExpr type mismatch");
		}
		return (R) "boolean";
	}

	/**
	 * f0 -> PrimaryExpression()
	 * f1 -> "<"
	 * f2 -> PrimaryExpression()
	 */
	public R visit(CompareExpression n) {
		R _ret=null;
		String type0 =(String)n.f0.accept(this);
		//System.out.println(currVarTable+"<-----------***********--------");
		VarDetails myVar = currVarTable.get(type0);
        if(type0==null)
			e.printError("Unknown variable "+ type0 +" on lhs");
		n.f1.accept(this);
		//String type1=currVarTable.get(type0).type;
		String type2 =(String)n.f2.accept(this);
		if ((type0.equals("int")==false) || (type2.equals("int")==false))
			e.printError("comparison error");
		//System.out.println(currVarTable+"<---------------------");
		currClass.classVars=currVarTable;
		return (R) "boolean";
	}

	/**
	 * f0 -> PrimaryExpression()
	 * f1 -> "+"
	 * f2 -> PrimaryExpression()
	 */
	public R visit(PlusExpression n) {
		R _ret=null;
		String type0 =(String)n.f0.accept(this);
		//System.out.println(currVarTable);
		VarDetails myVar = currVarTable.get(type0);
        if(type0==null)
            e.printError("Unknown variable "+ type0 +" on lhs");
		n.f1.accept(this);
		//String type1=currVarTable.get(type0).type;
		String type2 = (String)n.f2.accept(this);
		if ((type0.equals("int")==false) || (type2.equals("int")==false))
			e.printError("type mismatch in add expr");
		currClass.classVars=currVarTable;
		return (R) "int";

	}

	/**
	 * f0 -> PrimaryExpression()
	 * f1 -> "-"
	 * f2 -> PrimaryExpression()
	 */
	public R visit(MinusExpression n) {
		R _ret=null;
		String type0 =(String)n.f0.accept(this);
		//System.out.println(currVarTable);
		VarDetails myVar = currVarTable.get(type0);
        if(type0==null)
            e.printError("Unknown variable "+ type0 +" on lhs");
		n.f1.accept(this);
		//String type1=currVarTable.get(type0).type;
		String type2 = (String)n.f2.accept(this);
		if ((type0.equals("int")==false) || (type2.equals("int")==false))
			e.printError("type mismatch in minus");
		currClass.classVars=currVarTable;

		return (R) "int";
	}

	/**
	 * f0 -> PrimaryExpression()
	 * f1 -> "*"
	 * f2 -> PrimaryExpression()
	 */
	public R visit(TimesExpression n) {
		R _ret=null;
//		System.out.println("a*b");
		String type0 =(String)n.f0.accept(this);
		//System.out.println(type0);
		//System.out.println(currVarTable+"<---------------------");
		//System.out.println("CurrVarTable : "+currVarTable);
		//VarDetails myVar = currVarTable.get(type0);
		if(type0==null)
            e.printError("Unknown variable "+ type0 +" on lhs");
		n.f1.accept(this);
		//String type1=currVarTable.get(type0).type;
		//System.out.println("Type 1 : "+ type1);
		String type2 = (String)n.f2.accept(this);
		//System.out.println("Type 2 : "+ type2);
		if ((type0.equals("int")==false) || (type2.equals("int")==false))
			e.printError("in a*b");
//		System.out.println("a*b ends...");
		currClass.classVars=currVarTable;

		return (R) "int";
	}

	/**
	 * f0 -> PrimaryExpression()
	 * f1 -> "["
	 * f2 -> PrimaryExpression()
	 * f3 -> "]"
	 */
	public R visit(ArrayLookup n) {
		R _ret=null;
		String type1 = (String)n.f0.accept(this);
		n.f1.accept(this);
		String type2 = (String)n.f2.accept(this);
//        System.out.println(type1+"["+type2+"]");
		if ((type1.equals("int[]")==false) || (type2.equals("int")==false))
			e.printError("in Array Lookup");
		currClass.classVars=currVarTable;
		return (R) "int";	}

	/**
	 * f0 -> PrimaryExpression()
	 * f1 -> "."
	 * f2 -> "length"
	 */
	public R visit(ArrayLength n) {
		R _ret=null;
		String type1 = (String)n.f0.accept(this);
		if(type1.equals("int[]") == false)
			e.printError("in ArrayLength");
		n.f1.accept(this);
		//System.out.println(type1 +"<-----------------<<----------");
		n.f2.accept(this);
		return (R) "int";
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
//		System.out.println("££££££££££££££££££££££");
//        System.out.println("CurrArgTable at start of matching MessageSend : "+ currArgList);
		String className = (String)n.f0.accept(this);
		//System.out.println(className);
		if(className.equals("this")){
			//System.out.println("heyy");
			className=currClass.name;
		}
		//System.out.println("~~~~~~~~"+className);
		//System.out.println(currClass.name+"<----------------");
		ClassDetails myClass = symbolTable.get(className);
//		System.out.println("Class called: "+myClass.name);
		//System.out.println(myClass.classFuncs);
		//System.out.println(currFuncTable);
		prevFuncTable = currFuncTable;
		currFuncTable = new Hashtable<String, FuncDetails>();
		if(myClass.classFuncs != null)
			currFuncTable.putAll(myClass.classFuncs);
//		System.out.println("CurrFuncTable : "+currFuncTable);
		if(myClass==null)
			e.printError("null class...");
		//Hashtable prevFuncTable = currFuncTable;
		//System.out.println(currClass.name+"<-----------");
		//System.out.println(prevFuncTable);
		//currFuncTable = myClass.classFuncs;
		//currFuncTable = myClass.classFuncs;
		String funcName = (String)n.f2.f0.toString();
//		System.out.println("Func name : "+funcName);
		//currArgList = new ArrayList<String>();
		FuncDetails myFunc = currFuncTable.get(funcName);
//        System.out.println(currFuncTable);

//		System.out.println(myFunc.name);
		ArrayList refArgList = currFuncTable.get(funcName).argumentTypes;
//		System.out.println("Ref Arg list :"+refArgList);
		//if(currArgList==null)
	    currArgList = new ArrayList<String>();

//		System.out.println("currArgList : "+currArgList+"<------------------");
		n.f1.accept(this);
		n.f2.accept(this);
		n.f3.accept(this);
		//System.out.println(currArgList);
		//while(currArgList.isEmpty() == false){
		//	currArgList.removeAll(currArgList);
		//}
		currArgList = (ArrayList<String>)n.f4.accept(this);
//		System.out.println("¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡");
//		System.out.println("Curr Arg List : "+currArgList);
//		System.out.println("!!!!!!!!!!!!!!!!!!!!!!!!!");

		if(currArgList==null && refArgList!=null)
			e.printError("currArgList null");
		else if( (currArgList != null) && (refArgList != null) && (currArgList.size() != refArgList.size()) )
			e.printError("size mismatch of curr arg list and ref arg list...are you trying to overload functions?");
		else if(  (currArgList != null) && (refArgList != null) && (currArgList.size() == refArgList.size())) {
			/*for(int i=0; i<currArgList.size();i++){
				if(currArgList.get(i-1).equals(refArgList.get(i)) == false)
					e.printError();
			}*/
			Iterator i = currArgList.iterator();
			Iterator j = refArgList.iterator();
			while(i.hasNext() && j.hasNext()){
				String tmp1 = (String)i.next();
				String tmp2 = (String)j.next();
				//System.out.println("====================");
//				System.out.println(tmp1);
//				System.out.println(tmp2);
				if(tmp1.equals(tmp2) == false){
                    ClassDetails tmp = symbolTable.get(tmp1);
                    if(tmp==null)
                        e.printError("Arg mismatch...unknown class");
                    else if(tmp.parentClass.name.equals(tmp2)==false)
                        e.printError("Arg mismatch...incompatible classes");

                }
			//	i.next();
			//	j.next();
			}
		}

		n.f5.accept(this);
		currFuncTable=prevFuncTable;
//        System.out.println("Message send matched with "+myFunc.name);
		return (R) myFunc.returnType;
	}

	/**
	 * f0 -> Expression()
	 * f1 -> ( ExpressionRest() )*
	 */
	public R visit(ExpressionList n) {
		R _ret=null;
//        System.out.println("Trying to match ExpressionList...currArgList = "+currArgList);
		String type=(String)n.f0.accept(this);
//        System.out.println("Type : "+type);
		/*String type2=(String)*/
		//String type = null;
        if(currArgList == null)
            currArgList = new ArrayList<String>();
//        System.out.println("currArgList before add() : "+ currArgList);
		currArgList.add(type);
        n.f1.accept(this);
//        System.out.println("currArgList after add() : "+ currArgList);
//		System.out.println("Expression type : "+ type);
//        System.out.println("Matched ExprList...currArgList = "+currArgList);
		return (R) currArgList;
	}

	/**
	 * f0 -> ","
	 * f1 -> Expression()
	 */
	public R visit(ExpressionRest n) {
//        System.out.println("Trying to match ExpressionRest...currArgList = "+currArgList);

        R _ret=null;
		n.f0.accept(this);
		String type = (String)n.f1.accept(this);
        currArgList.add(type);
		return (R) type;
	}

	/**
	 * f0 -> IntegerLiteral()				0
	 *       | TrueLiteral()				1
	 *       | FalseLiteral()				2
	 *       | Identifier()					3
	 *       | ThisExpression()				4
	 *       | ArrayAllocationExpression()	5
	 *       | AllocationExpression()		6
	 *       | NotExpression()				7
	 *       | BracketExpression()			8
	 */
	public R visit(PrimaryExpression n) {
		R _ret=null;
//		System.out.println("PE choice: "+n.f0.which);
		//if(n.f0.which == 3) 
			//System.out.println("PE with ID");
		String type = (String)n.f0.accept(this);
        if(n.f0.which == 3){
//            System.out.println("PE as ID");
            VarDetails tmp = currVarTable.get(type);
            if(tmp != null){
                type = tmp.type;
            }

        }

        if(n.f0.which==4)
            type = currClass.name;

//		System.out.println("PE Type: "+type);
		return (R) type;
	}

	/**
	 * f0 -> <INTEGER_LITERAL>
	 */
	public R visit(IntegerLiteral n) {
		R _ret=null;
		n.f0.accept(this);
		return (R) "int";
	}

	/**
	 * f0 -> "true"
	 */
	public R visit(TrueLiteral n) {
		R _ret=null;
		n.f0.accept(this);
		return (R) "boolean";
	}
	/**
	 * f0 -> "false"
	 */
	public R visit(FalseLiteral n) {
		R _ret=null;
		n.f0.accept(this);
		return (R) "boolean";
	}

	/**
	 * f0 -> <IDENTIFIER>
	 */
	public R visit(Identifier n) {
		R _ret=null;
		//String type = null;
		//if(set==false){
		//	ClassDetails myClass= symbolTable.get(n.f0.toString());
		//	System.out.println(myClass);
		//	if(myClass==null){
		//		VarDetails myVar = currVarTable.get(n.f0.toString());
		//		System.out.println(myVar);
		//		if(myVar==null){
		//			FuncDetails myFunc = currFuncTable.get(n.f0.toString());
		//			System.out.println(myFunc);
		//			if(myFunc==null)
		//				e.printError();
		//			type = "func";
		//		}
		//		type = "var";
		//	}
		//	type = "class";
		//}
		//System.out.println("ID : "+n.f0.toString());
		//System.out.println(type);
	      n.f0.accept(this);
	      return (R) n.f0.toString();
		}

	/**
	 * f0 -> "this"
	 */
	public R visit(ThisExpression n) {
		R _ret=null;
		n.f0.accept(this);
		return (R) "this";
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
		String type1=(String)n.f3.accept(this);
		if(type1.equals("int") == false)
			e.printError("rhs of array allocation not int");
		n.f4.accept(this);
		return (R) "int[]";
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
		String className = (String)n.f1.f0.toString();
//		System.out.println(n.f1.f0.toString());
		ClassDetails cd = symbolTable.get(className);
		if(cd==null)
			e.printError("Constructor for non existing class in new()");
		n.f2.accept(this);
		n.f3.accept(this);
		return (R) n.f1.f0.toString();
	}

	/**
	 * f0 -> "!"
	 * f1 -> Expression()
	 */
	public R visit(NotExpression n) {
		R _ret=null;
		n.f0.accept(this);
		String type1 = (String)n.f1.accept(this);
		if(type1.equals("boolean")==false)
			e.printError("arg of NOT is not boolean");
		return (R)"boolean";
	}

	/**
	 * f0 -> "("
	 * f1 -> Expression()
	 * f2 -> ")"
	 */
	public R visit(BracketExpression n) {
		R _ret=null;
		n.f0.accept(this);
		String type =(String) n.f1.accept(this);
		n.f2.accept(this);
		return (R) type;
	}	 

}
