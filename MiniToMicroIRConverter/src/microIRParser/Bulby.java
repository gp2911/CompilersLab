import syntaxtree.*;
import visitor.*;
// import myClasses.*;
// import microIRParser.*;

public class Bulby {
    public static void main(String [] args) {
        try {
            Node root = new microIRParser(System.in).Goal();
            System.out.println("Program parsed successfully");
            // CodeConverter converter = new CodeConverter();
            // root.accept(converter); // Your assignment part is invoked here.
        }
        catch (ParseException e) {
            System.out.println(e.toString());
        }
    }
}
