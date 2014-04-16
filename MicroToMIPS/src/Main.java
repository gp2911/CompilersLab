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

import myClasses.*;

public class Main {
    public static void main(String [] args) {
        try {
            Node root = new MiniRAParser(System.in).Goal();
            MiniRAToMIPS c = new MiniRAToMIPS();
            root.accept(c);
        }
        catch (ParseException e) {
            System.out.println(e.toString());
        }
    }
}










