package myClasses;
import java.util.*;
import java.lang.*;

import syntaxtree.*;
import visitor.*;
import myClasses.*;
public class TableConstructor<R> implements GJNoArguVisitor<R> {
	
	//class Details{
	//	String name;
	//	String type;
	//}
	//class VarDetails extends Details{
	//	String containingFunction;
	//	String containingClass;
	//	boolean isParam;
	//	boolean funcScope;
	//}
	//class FuncDetails extends Details{
//		String returnType;
//		String containingClass;
//		ArrayList < String > argumentTypes;
//	}
//	class ClassDetails extends Details{
//		boolean isDerived;
//		boolean derives;
//		ClassDetails parentClass;
//		List<ClassDetails> children;
//		Hashtable<String,VarDetails> classVars;
//		Hashtable<String,FuncDetails> classFuncs;
//		
//	}
	
//	int pass = 0;
	
//	Node root;
	
	Hashtable<String,ClassDetails> symbolTable = new Hashtable<String,ClassDetails>();
	Hashtable<String,FuncDetails> currFuncTable;
	LinkedHashMap<String, VarDetails> currVarTable;
	
	ClassDetails currClass;
	FuncDetails currFunc;
	
	ErrorHandler e = new ErrorHandler();

    boolean override = false;
	
	public Hashtable<String,ClassDetails> getSymbolTable(){
		return symbolTable;
	};
	
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
			   //root=n;
			   currClass=null;
			   currFuncTable=null;
			   currVarTable=null;
			   currFunc=null;
			  // System.out.println("Parsing Goal...");
		      R _ret=null;
		      n.f0.accept(this);
		      n.f1.accept(this);
		      n.f2.accept(this);
//               System.out.println("••••••••••••••••••••••••••••••••••••••••••");
//               System.out.println("••••••••••••••••••••••••••••••••••••••••••");
//               System.out.println("••••••••••••••••••••••••••••••••••••••••••");

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
			   ClassDetails prevClass = currClass;
			   ClassDetails main= new ClassDetails();
			   String mainName = n.f1.f0.toString();
//				System.out.println(mainName);
				main.isChild = false;
				main.isParent = false;
				main.type="class";
				main.name=mainName;
				main.classFuncs = new Hashtable<String,FuncDetails>();
				main.classVars = new LinkedHashMap<String, VarDetails>();
				currClass=main;
				currVarTable = main.classVars;
				currFuncTable = main.classFuncs;
				FuncDetails myFunc = new FuncDetails();
				myFunc.name = "main";
				myFunc.returnType = "void";
				myFunc.containingClass=main.name;
				myFunc.argumentTypes = new ArrayList<String>();
				myFunc.argumentTypes.add("String[]");
				currFunc = myFunc;
				main.classFuncs.put(myFunc.name, myFunc);
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
		      n.f13.accept(this);
		      n.f14.accept(this);
		      n.f15.accept(this);
		      n.f16.accept(this);
		      symbolTable.put(mainName, main);
		      currFunc=null;
		      currClass = prevClass;
		      if(prevClass==null){
		    	currVarTable = null;
			  	currFuncTable = null;
		      }
		      else{
		    	  currVarTable = prevClass.classVars;
		    	  currFuncTable = prevClass.classFuncs;
		      }
		      
		      //ClassDetails x = (ClassDetails)symbolTable.get("main");
		      //System.out.println(x.isDerived);
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
		     ClassDetails myClass = new ClassDetails();
		     myClass.isChild = false;
		     if(!(myClass.isParent==true))
		    	 myClass.isParent=false;
		     myClass.name = n.f1.f0.toString();
		     myClass.isDefined=true;
		     ClassDetails tmp = symbolTable.get(myClass.name);
		     //System.out.println(tmp.name+" : "+tmp.type);
		     if(tmp!=null && tmp.isDefined){
		    	 e.printError("multiple classes with same name");
		     }
		     myClass.type = "class";
		     myClass.classFuncs = new Hashtable<String,FuncDetails>();
		     myClass.classVars = new LinkedHashMap<String, VarDetails>();
		     currFuncTable = myClass.classFuncs;
		     currVarTable = myClass.classVars;
		     currClass = myClass;
		      n.f0.accept(this);
		      n.f1.accept(this);
		      n.f2.accept(this);
		      n.f3.accept(this);
		      n.f4.accept(this);
		      n.f5.accept(this);
              if(tmp!=null && tmp.isDefined == false)
                symbolTable.remove(tmp.name);
		      symbolTable.put(myClass.name, myClass);

//               System.out.println("=============================");
//               System.out.println("Class : "+ myClass.name);
               ClassDetails tmp2 = symbolTable.get(myClass.name);
//               System.out.println("Class : "+ tmp2.name);
//               System.out.println("ClassVars : "+tmp2.classVars);
//               System.out.println("ClassFuncs : "+tmp2.classFuncs);
//               System.out.println("=============================");

               if(myClass.isParent == true){
		    	  for(int i=0; i< myClass.children.size(); i++){
		    		  ClassDetails tmp1 = myClass.children.get(i);
//		    		  System.out.println(tmp1.name);
		    	  }
		      }
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
		      ClassDetails myClass = new ClassDetails();
		      myClass.isChild=true;
		      myClass.name=n.f1.f0.toString();
		      myClass.isDefined = true;
		      String parentName = n.f3.f0.toString();
//		      System.out.println(parentName);
		      myClass.parentClass = symbolTable.get(parentName);
               myClass.classFuncs = new Hashtable<String, FuncDetails>();
               myClass.classVars = new LinkedHashMap<String, VarDetails>();
		      if(myClass.parentClass==null){
		    	  ClassDetails tmp = new ClassDetails();
		    	  tmp.name = parentName;
		    	  tmp.type = "class";
                  tmp.classVars = new LinkedHashMap<String, VarDetails>();
                  tmp.classFuncs = new Hashtable<String, FuncDetails>();
		    	  symbolTable.put(parentName, tmp);
		    	  myClass.parentClass=tmp;
		      }
		      if(myClass.parentClass.children==null){
		    	  myClass.parentClass.children = new ArrayList<ClassDetails>();
		      }
		      myClass.parentClass.isParent = true;
		      myClass.parentClass.children.add(myClass);
			     currFuncTable = myClass.classFuncs;
			     currVarTable = myClass.classVars;
			     currClass = myClass;
		      
		      n.f0.accept(this);
		      n.f1.accept(this);
		      n.f2.accept(this);
		      n.f3.accept(this);
		      n.f4.accept(this);
		      n.f5.accept(this);
		      n.f6.accept(this);
		      n.f7.accept(this);
		      
		      if(myClass.isParent == true){
		    	  for(int i=0; i< myClass.children.size(); i++){
		    		  ClassDetails tmp = myClass.children.get(i);
//		    		  System.out.println(tmp.name);
		    	  }
		      }
		      symbolTable.put(n.f1.f0.toString(), myClass);

//               System.out.println("=============================");
//               System.out.println("Class : "+ myClass.name);
               ClassDetails tmp2 = symbolTable.get(myClass.name);
//               System.out.println("Class : "+ tmp2.name);
//               System.out.println("ParentClass : "+ tmp2.parentClass.name);
//               System.out.println("ParetnClass isDefined : "+tmp2.parentClass.isDefined);
//               System.out.println("ClassVars : "+tmp2.classVars);
//               System.out.println("ClassFuncs : "+tmp2.classFuncs);
//               System.out.println("=============================");

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
		     if(currFunc == null){
		      VarDetails myVar = new VarDetails();
		      myVar.name = n.f1.f0.toString();
		      myVar.type = (String)n.f0.accept(this);
		      //myVar.containingClass = currClass.name;
		      //myVar.containingFunction = currFunc.name;
		      VarDetails x = currVarTable.get(myVar.name);
		      if(x == null)
		    	  currVarTable.put(myVar.name, myVar);
		      x = (VarDetails)currVarTable.get(myVar.name);
//		      System.out.println(x.name + " : " + x.type+"<---------------------");
		     }
		     
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
		      FuncDetails myFunc = new FuncDetails();
		      myFunc.name = n.f2.f0.toString();
		      myFunc.containingClass = currClass.name;
		      myFunc.localVars = new LinkedHashMap<String, VarDetails>();
		      myFunc.argumentTypes = new ArrayList<String>();
		      currFunc = myFunc;
              ArrayList<String> refArgList=new ArrayList<String>();
              FuncDetails tmp = currFuncTable.get(myFunc.name);
              if(tmp!=null){
                  override = true;
                  refArgList = tmp.argumentTypes;
              }
		      n.f0.accept(this);
		      myFunc.returnType =(String) n.f1.accept(this);
		      //n.f1.accept(this);
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
              if(myFunc.argumentTypes.isEmpty())
                  myFunc.argumentTypes=null;
              if(override==true){
                  ArrayList<String> currArgList = myFunc.argumentTypes;
                  Iterator<String> i = refArgList.iterator();
                  Iterator<String> j = currArgList.iterator();
                  while(i.hasNext() && j.hasNext()){
                      String tmp1 = (String)i.next();
                      String tmp2 = (String)j.next();
//                      //System.out.println("====================");
//                      System.out.println(tmp1);
//                      System.out.println(tmp2);
                      if(tmp1.equals(tmp2) == false){
                          e.printError("Function overloading not allowed!");
                      }
                  }
              }
              override = false;
		      currFunc=null;
		      currFuncTable.put(myFunc.name, myFunc);
//			  System.out.println("Func table for class "+currClass.name+" : "+ currFuncTable+" : "+currClass.classFuncs);
		      FuncDetails x = (FuncDetails)currFuncTable.get(myFunc.name);
//		      System.out.println(x.name.toString()+" : " + x.containingClass.toString());
		      
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
//              System.out.println("¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢¢   "+currFunc.name+" : "+currFunc.argumentTypes);
		      return _ret;
		   }

		   /**
		    * f0 -> Type()
		    * f1 -> Identifier()
		    */
		   public R visit(FormalParameter n) {
		      R _ret=null;
		      VarDetails myParam = new VarDetails();
		      myParam.isParam=true;
		      myParam.name = n.f1.f0.toString();
		      myParam.type=(String)n.f0.accept(this);
//		      System.out.println(currFunc.name.toString());
		      if (currFunc.argumentTypes==null)
		    	  currFunc.argumentTypes = new ArrayList();
		      currFunc.argumentTypes.add(myParam.type);
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
		      //n.f0.accept(this);
//               if(n.f0.which==3)
//                    System.out.println("Trying to match Type with ID...");
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
//		    * f0 -> "System.out.println"
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
		      return (R) n.f0.toString();
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
