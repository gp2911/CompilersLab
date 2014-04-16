package myClasses;

import java.util.*;
import java.util.List;

public class ClassDetails extends Details{
	boolean isChild;   //
	boolean isParent;    //
	boolean isDefined;     //
	ClassDetails parentClass;//
	List<ClassDetails> children;//
	LinkedHashMap<String,VarDetails> classVars;
	Hashtable<String,FuncDetails> classFuncs;
    ArrayList<FuncCode> classFuncCodes;
    String constructorCode;
    LinkedHashMap<String,VarDetails> initHash;
    int objCount;
    Hashtable<String, Integer> objRec;
    boolean isFuncCoded;

    public ClassDetails(){

    }
    public ClassDetails(ClassDetails m){
        isFuncCoded = m.isFuncCoded;
        isDefined = m.isDefined;
        isChild = m.isChild;
        isParent = m.isParent;
        parentClass = m.parentClass;
        children = m.children;
        classVars = m.classVars;
        classFuncs = m.classFuncs;
        classFuncCodes = m.classFuncCodes;
        initHash = m.initHash;
        objCount = m.objCount;
        objRec = m.objRec;
        name = m.name;
        type = m.type;
    }
	
}
