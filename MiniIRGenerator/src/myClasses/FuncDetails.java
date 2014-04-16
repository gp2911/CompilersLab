package myClasses;

import java.util.*;

public class FuncDetails extends Details{
	String returnType;
	String containingClass;
	ArrayList < String > argumentTypes;
	LinkedHashMap<String,VarDetails> localVars;
    boolean isOverridden;
}