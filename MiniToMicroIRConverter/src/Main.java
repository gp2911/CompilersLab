/**
 * Created with IntelliJ IDEA.
 * User: GP
 * Date: 04/10/13
 * Time: 6:07 PM
 * To change this template use File | Settings | File Templates.
 */
import syntaxtree.*;
import visitor.*;
import myClasses.*;


public class Main {
    public static void main(String [] args) {
        try {
            Node root = new MiniIRParser(System.in).Goal();
//            System.out.println("Program parsed successfully");
            CodeConverter converter = new CodeConverter();
            root.accept(converter); // Your assignment part is invoked here.
        }
        catch (ParseException e) {
            System.out.println(e.toString());
        }
    }
}

