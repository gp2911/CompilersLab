class test4{
    public static void main(String[] a){
        System.out.println(new B().fun1(10));
    }
}

class A {
	int f1;
	boolean f2;
	
	public int fun1(int p1, int p2){
		int loc1;
		boolean loc2;
		loc1=78;
		System.out.println(num);
	     	return 0;
	}
	
	public int fun2(){
		System.out.println(100);
	     	return 0;
	}
}

class B extends A{
	int f3;
	boolean f4;
	
    public int fun1(int p1, int p2){
    	int loc111;
    	loc111=45;
        System.out.println(num*5);
     	return 1;
    }
    
    public int fun3(boolean p11){
		System.out.println(75);
	     	return 5;
   } 
}

class C extends B{
	int f7;
	boolean f8;
	
    public int fun1(int p1, int p2){
    	int loc111;
    	boolean loc21;
    	
    	loc111=45;
        System.out.println(num*5);
     	return 1;
    }
    
    public int fun13(boolean p11){
    		int[] aray;
		System.out.println(75);
	     	return 5;
   } 
}

class D extends C{
	boolean f9;
    
    public int fun13(boolean p11, int p12){
    		boolean l1;
		System.out.println(75);
	     	return 5;
   } 
}
